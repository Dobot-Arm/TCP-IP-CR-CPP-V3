
#include "DobotTcpDemo.h"
#include <fstream>

DobotTcpDemo::DobotTcpDemo()
{
    std::string robotIp = "192.168.5.1";
    unsigned int controlPort = 29999;
    unsigned int movePort = 30003;
    unsigned int feekPort = 30004;

    m_Dashboard.Connect(robotIp, controlPort);
    m_DobotMove.Connect(robotIp, movePort);
    m_CFeedback.Connect(robotIp, feekPort);

    m_CErrorInfoHelper.ParseControllerJsonFile("../alarm_controller.json");
    m_CErrorInfoHelper.ParseServoJsonFile("../alarm_servo.json");

    threadGetFeedBackInfo = std::thread(&DobotTcpDemo::getFeedBackInfo, this);
    threadGetFeedBackInfo.detach();
    threadClearRobotError = std::thread(&DobotTcpDemo::clearRobotError, this);
    threadClearRobotError.detach();
}

DobotTcpDemo::~DobotTcpDemo()
{
    m_DobotMove.Disconnect();
    m_Dashboard.Disconnect();
    m_CFeedback.Disconnect();
}

void DobotTcpDemo::moveRobot()
{
    double pointa[] = {-800, 10, -70, -100, -40, 90};
    double pointb[] = {-900, 15, -80, -90, -30, 100};
    m_Dashboard.EnableRobot();
    Dobot::CDescartesPoint ptPointa;
    Dobot::CDescartesPoint ptPointb;
    memcpy(&ptPointa, pointa, sizeof(ptPointa));
    memcpy(&ptPointb, pointb, sizeof(ptPointb));

    while (true)
    {
        m_DobotMove.MovL(ptPointa);
        moveArriveFinish(ptPointa);
        m_DobotMove.MovL(ptPointb);
        moveArriveFinish(ptPointb);
    }
}

void DobotTcpDemo::getFeedBackInfo()
{
    while (true)
    {
        {
            std::unique_lock<std::mutex> lockValue(m_mutexValue);
            feedbackData = m_CFeedback.GetFeedbackData();
            // std::cout << feedbackData.QActual << std::endl;
            // std::cout << feedbackData.RunQueuedCmd << std::endl;
            // std::cout << feedbackData.EnableStatus << std::endl;
            // std::cout << feedbackData.ErrorStatus << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void DobotTcpDemo::moveArriveFinish(const Dobot::CDescartesPoint &pt)
{

    while (true)
    {
        {
            std::unique_lock<std::mutex> lockValue(m_mutexValue);
            std::unique_lock<std::mutex> lockState(m_mutexState);
            bool hasNonZero = std::any_of(std::begin(feedbackData.ToolVectorActual), std::end(feedbackData.ToolVectorActual),
                                          [](double val)
                                          { return val != 0.0; });
            if (hasNonZero)
            {
                auto stateFinish = [=](double value1, double value2)
                {
                    return std::abs(value1 - value2) < 1;
                };

                bool xFinish = stateFinish(feedbackData.ToolVectorActual[0], pt.x);
                bool yFinish = stateFinish(feedbackData.ToolVectorActual[1], pt.y);
                bool zFinish = stateFinish(feedbackData.ToolVectorActual[2], pt.z);
                bool rxFinish = stateFinish(feedbackData.ToolVectorActual[3], pt.rx);
                bool ryFinish = stateFinish(feedbackData.ToolVectorActual[4], pt.ry);
                bool rzFinish = stateFinish(feedbackData.ToolVectorActual[5], pt.rz);
                if (xFinish && yFinish && zFinish && rxFinish && ryFinish && rzFinish)
                {
                    isStateFinish = true;
                }

                if (isStateFinish)
                {
                    isStateFinish = false;
                    return;
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
};

std::vector<std::string> DobotTcpDemo::regexRecv(std::string getRecvInfo)
{
    std::regex pattern("-?\\d+");
    std::smatch matches;
    std::string::const_iterator searchStart(getRecvInfo.cbegin());
    std::vector<std::string> vecErrorId;
    while (std::regex_search(searchStart, getRecvInfo.cend(), matches, pattern))
    {
        for (auto &match : matches)
        {
            vecErrorId.push_back(match.str());
        }
        searchStart = matches.suffix().first;
    }
    return vecErrorId;
};

void DobotTcpDemo::clearRobotError()
{
    while (true)
    {
        {
            std::unique_lock<std::mutex> lockValue(m_mutexValue);
            std::unique_lock<std::mutex> lockState(m_mutexState);
            if (feedbackData.ErrorStatus && feedbackData.EnableStatus)
            {
                std::vector<std::string> errorIdVec = regexRecv(m_Dashboard.GetErrorID());
                for (int i = 1; i < errorIdVec.size(); i++)
                {
                    Dobot::CErrorInfoBean beanController;
                    Dobot::CErrorInfoBean beanServo;
                    if (std::stoi(errorIdVec[i]) != 0)
                    {
                        printf("告警码：%s\n", errorIdVec[i].c_str());
                        if (m_CErrorInfoHelper.FindController(std::stoi(errorIdVec[i]), beanController))
                        {
                            printf("控制器告警：%d, 告警原因：%s,%s\n", beanController.id,
                                   beanController.zh_CN.description.c_str(), beanController.en.description.c_str());
                        }
                        else
                        {
                            if (m_CErrorInfoHelper.FindServo(std::stoi(errorIdVec[i]), beanServo))
                            {
                                printf("伺服告警：%d,告警原因：%s, %s\n", beanServo.id,
                                       beanServo.zh_CN.description.c_str(), beanServo.en.description.c_str());
                            }
                        }
                    }
                }

                std::vector<std::string> clearErrorIDVec = regexRecv(m_Dashboard.ClearError());
                if (clearErrorIDVec.size() > 0 && !std::stoi(clearErrorIDVec[0]))
                {
                    std::vector<std::string> contiRecvVec;
                    contiRecvVec = regexRecv(m_DobotMove.Continue());
                    if (!std::stoi(contiRecvVec[0]))
                    {
                        std::vector<std::string> errorIDVec = regexRecv(m_Dashboard.GetErrorID());
                        auto nonZero = std::find_if(errorIDVec.begin(), errorIDVec.end(), [](std::string i)
                                                    { return std::atoi(i.c_str()) != 0; });
                        if (nonZero == errorIDVec.end())
                        {
                            isStateFinish = true;
                            break;
                        }
                    }
                }
            }
            else
            {
                if (feedbackData.EnableStatus && (!feedbackData.RunQueuedCmd))
                {
                    m_DobotMove.Continue();
                }
            }
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(5000));
    }
}
int main()
{
    DobotTcpDemo *demo = new DobotTcpDemo();
    demo->moveRobot();
}
