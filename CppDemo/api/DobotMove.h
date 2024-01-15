#pragma once

#include "DobotClient.h"
#include "DescartesPoint.h"
#include "JointPoint.h"

namespace Dobot
{
class CDobotMove : public CDobotClient
{
public:
    CDobotMove();
    virtual ~CDobotMove();

    /// 关节点动运动，不固定距离运动
    /// <param name="s">点动运动轴</param>
    /// <returns>返回执行结果的描述信息</returns>
    std::string MoveJog();
    template <typename... Args>
    std::string MoveJog(Args... args);

    /// 停止关节点动运动
    /// <returns>返回执行结果的描述信息</returns>
    std::string StopMoveJog();

    // 轨迹拟合。(轨迹文件笛卡尔点)
    /// <param traceName="s">轨迹文件名（含后缀)  轨迹路径存放在/dobot/userdata/project/process/trajectory/ </param>
    /// <returns>返回执行结果的描述信息</returns>
    std::string StartTrace(std::string traceName);

    // 轨迹复现。(轨迹文件关节点)
    /// <param traceName="s">轨迹文件名（含后缀） 轨迹路径存放在/dobot/userdata/project/process/trajectory/ </param>
    /// <param constInt="s">constInt=1时，匀速复现，轨迹中的停顿及死区会被移除;  constInt=0时，按照原速复现； </param>
    /// <param cart="s"> cart=1时，按笛卡尔路径复现； cart=0时，按关节路径复现； </param>
    /// <returns>返回执行结果的描述信息</returns>
    std::string StartPath(std::string traceName, int constInt, int cart);

    /// 点到点运动，目标点位为笛卡尔点位
    /// <param name="pt">笛卡尔点位</param>
    /// <returns>返回执行结果的描述信息</returns>
    std::string MovJ(const CDescartesPoint& pt);
    template <typename... Args>
    std::string MovJ(const CDescartesPoint& pt, Args... args);

    /// 直线运动，目标点位为笛卡尔点位
    /// <param name="pt">笛卡尔点位</param>
    /// <returns>返回执行结果的描述信息</returns>
    std::string MovL(const CDescartesPoint& pt);
    template <typename... Args>
    std::string MovL(const CDescartesPoint& pt, Args... args);

    /// 点到点运动，目标点位为关节点位。
    /// <param name="pt"></param>
    /// <returns>返回执行结果的描述信息</returns>
    std::string JointMovJ(const CJointPoint& pt);
    template <typename... Args>
    std::string JointMovJ(const CJointPoint& pt, Args... args);

    // std::string RelMovJ();
    // std::string RelMovL();

    std::string MovLIO(const CDescartesPoint& pt);
    template <typename... Args>
    std::string MovLIO(const CDescartesPoint& pt, Args... args);

    std::string MovJIO(const CDescartesPoint& pt);
    template <typename... Args>
    std::string MovJIO(const CDescartesPoint& pt, Args... args);

    std::string Arc(const CDescartesPoint& pt, const CDescartesPoint& pt2);
    template <typename... Args>
    std::string Arc(const CDescartesPoint& pt, const CDescartesPoint& pt2, Args... args);

    std::string ServoJ(const CJointPoint& pt);
    template <typename... Args>
    std::string ServoJ(const CJointPoint& pt, Args... args);

    std::string ServoJS(const CJointPoint& pt);
    std::string ServoP(const CDescartesPoint& pt);

    std::string Circle3(const CDescartesPoint& pt, const CDescartesPoint& pt2, int count);
    template <typename... Args>
    std::string Circle3(const CDescartesPoint& pt, const CDescartesPoint& pt2, int count, Args... args);

    std::string Sync();

    std::string RelMovJUser(const CDescartesPoint& pt, int User);
    template <typename... Args>
    std::string RelMovJUser(const CDescartesPoint& pt, int User, Args... args);

    std::string RelMovLUser(const CDescartesPoint& pt, int User);
    template <typename... Args>
    std::string RelMovLUser(const CDescartesPoint& pt, int User, Args... args);

    std::string RelMovLTool(const CDescartesPoint& pt, int Tool);
    template <typename... Args>
    std::string RelMovLTool(const CDescartesPoint& pt, int Tool, Args... args);

    std::string RelMovJTool(const CDescartesPoint& pt, int Tool);
    template <typename... Args>
    std::string RelMovJTool(const CDescartesPoint& pt, int Tool, Args... args);

    std::string RelJointMovJ(const CDescartesPoint& pt);
    template <typename... Args>
    std::string RelJointMovJ(const CDescartesPoint& pt, Args... args);

    std::string wait();
    std::string Continue();
    std::string pause();

protected:
    void OnConnected() override;
    void OnDisconnected() override;

private:
    // 类外定义成员函数
    template <typename T>
    void printArg(T arg);

    template <typename T, typename... Args>
    void printArg(T arg, Args... args);

    template <typename T>
    std::string toString(T arg);
    std::string strSend{ "" };
    std::mutex m_mutexSend;
};

// 可选参数输出
template <typename T>
void CDobotMove::printArg(T arg)
{
    strSend = strSend + toString(arg) + ")";
}

// 递归输出可选参数
template <typename T, typename... Args>
void CDobotMove::printArg(T arg, Args... args)
{
    strSend = strSend + toString(arg) + ",";
    printArg(args...);
}

// 辅助函数，将参数转换为字符串
template <typename T>
std::string CDobotMove::toString(T arg)
{
    std::stringstream ss;
    ss << arg;
    return ss.str();
}

template <typename... Args>
std::string CDobotMove::MoveJog(Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    strSend = "MoveJog(";
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

// 可选参数
template <typename... Args>
std::string CDobotMove::MovJ(const CDescartesPoint& pt, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "MovJ(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::MovL(const CDescartesPoint& pt, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "MovL(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << "," << pt.rz << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::JointMovJ(const CJointPoint& pt, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "JointMovJ(" << pt.j1 << ',' << pt.j2 << ',' << pt.j3 << ',' << pt.j4 << ',' << pt.j5 << ',' << pt.j6 << ',';
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::MovLIO(const CDescartesPoint& pt, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "MovLIO(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << ',' << pt.rz << ',';
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::MovJIO(const CDescartesPoint& pt, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "MovJIO(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << "," << pt.rz << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::Arc(const CDescartesPoint& pt, const CDescartesPoint& pt2, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "Arc(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << "," << pt.rz << "," << pt2.x
        << ',' << pt2.y << ',' << pt2.z << ',' << pt2.rx << "," << pt2.ry << "," << pt2.rz << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::ServoJ(const CJointPoint& pt, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "ServoJ(" << pt.j1 << ',' << pt.j2 << ',' << pt.j3 << ',' << pt.j4 << ',' << pt.j5 << ',' << pt.j6 << ',';
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::Circle3(const CDescartesPoint& pt, const CDescartesPoint& pt2, int count, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "Circle3(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << "," << pt.rz << ","
        << pt2.x << ',' << pt2.y << ',' << pt2.z << ',' << pt2.rx << "," << pt2.ry << "," << pt2.rz << ","
        << std::to_string(count) << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::RelMovJUser(const CDescartesPoint& pt, int User, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "RelMovJUser(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << "," << pt.rz << ","
        << std::to_string(User) << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::RelMovLUser(const CDescartesPoint& pt, int User, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "RelMovLUser(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << "," << pt.rz << ","
        << std::to_string(User) << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::RelMovLTool(const CDescartesPoint& pt, int Tool, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "RelMovLTool(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << "," << pt.rz << ","
        << std::to_string(Tool) << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::RelMovJTool(const CDescartesPoint& pt, int Tool, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "RelMovJTool(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << "," << pt.rz << ","
        << std::to_string(Tool) << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

template <typename... Args>
std::string CDobotMove::RelJointMovJ(const CDescartesPoint& pt, Args... args)
{
    std::unique_lock<std::mutex> lockValue(m_mutexSend);
    std::ostringstream oss;
    oss << "RelJointMovJ(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << "," << pt.ry << "," << pt.rz << ",";
    strSend = oss.str();
    printArg(args...);
    std::string str = strSend;
    strSend.clear();
    return SendRecvMsg(str);
}

}    // namespace Dobot
