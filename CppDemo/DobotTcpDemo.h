
#include "api/DobotMove.h"
#include "api/Dashboard.h"
#include "api/Feedback.h"
#include "api/ErrorInfoBean.h"
#include "api/ErrorInfoHelper.h"
#include <iostream>
#include <algorithm>
#include <regex>
#include <mutex>

class DobotTcpDemo
{

public:
    DobotTcpDemo();
    ~DobotTcpDemo();
    void moveRobot();

private:
    void getFeedBackInfo();
    void moveArriveFinish(const Dobot::CDescartesPoint &pt);
    std::vector<std::string> regexRecv(std::string getRecvInfo);
    void clearRobotError();

private:
    Dobot::CDobotMove m_DobotMove;
    Dobot::CDashboard m_Dashboard;
    Dobot::CFeedback m_CFeedback;
    Dobot::CFeedbackData feedbackData;
    Dobot::CErrorInfoBeans m_ErrorInfoBeans;
    Dobot::CErrorInfoHelper m_CErrorInfoHelper;
    bool isStateFinish{false};
    std::thread threadGetFeedBackInfo;
    std::thread threadClearRobotError;
    std::mutex m_mutexValue;
    std::mutex m_mutexState;
};
