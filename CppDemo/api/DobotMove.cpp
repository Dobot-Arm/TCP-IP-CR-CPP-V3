#include "DobotMove.h"
#include <sstream>

namespace Dobot
{
CDobotMove::CDobotMove()
{
}
CDobotMove::~CDobotMove()
{
}

void CDobotMove::OnConnected()
{
}
void CDobotMove::OnDisconnected()
{
}

// 重载无参函数
std::string CDobotMove::MoveJog()
{
    std::string str = "MoveJog()";

    return SendRecvMsg(str);
}

std::string CDobotMove::StopMoveJog()
{
    return MoveJog();
}

std::string CDobotMove::StartTrace(std::string traceName)
{
    std::string str = "StartTrace(" + std::string(traceName) + ")";

    return SendRecvMsg(str);
}

std::string CDobotMove::StartPath(std::string traceName, int constInt, int cart)
{
    std::string str =
        "StartPath(" + std::string(traceName) + "," + std::to_string(constInt) + "," + std::to_string(cart) + ")";

    return SendRecvMsg(str);
}

// 无可选参数
std::string CDobotMove::MovJ(const CDescartesPoint& pt)
{
    std::ostringstream oss;
    oss << "MovJ(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::MovL(const CDescartesPoint& pt)
{
    std::ostringstream oss;
    oss << "MovL(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::JointMovJ(const CJointPoint& pt)
{
    std::ostringstream oss;
    oss << "JointMovJ(" << pt.j1 << ',' << pt.j2 << ',' << pt.j3 << ',' << pt.j4 << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::MovLIO(const CDescartesPoint& pt)
{
    std::ostringstream oss;
    oss << "MovLIO(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::MovJIO(const CDescartesPoint& pt)
{
    std::ostringstream oss;
    oss << "MovJIO(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::Arc(const CDescartesPoint& pt, const CDescartesPoint& pt2)
{
    std::ostringstream oss;
    oss << "Arc(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ',' << pt2.x
        << ',' << pt2.y << ',' << pt2.z << ',' << pt2.rx << ',' << pt2.ry << ',' << pt2.rz << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::ServoJ(const CJointPoint& pt)
{
    std::ostringstream oss;
    oss << "ServoJ(" << pt.j1 << ',' << pt.j2 << ',' << pt.j3 << ',' << pt.j4 << ',' << pt.j5 << ',' << pt.j6 << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::ServoP(const CDescartesPoint& pt)
{
    std::ostringstream oss;
    oss << "ServoP(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::ServoJS(const CJointPoint& pt)
{
    std::ostringstream oss;
    oss << "ServoJS(" << pt.j1 << ',' << pt.j2 << ',' << pt.j3 << ',' << pt.j4 << ',' << pt.j5 << ',' << pt.j6 << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::Circle3(const CDescartesPoint& pt, const CDescartesPoint& pt2, int count)
{
    std::ostringstream oss;
    oss << "Circle3(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ','
        << pt2.x << ',' << pt2.y << ',' << pt2.z << ',' << pt2.rx << ',' << pt2.ry << ',' << pt2.rz << ','
        << std::to_string(count) << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::Sync()
{
    std::string str = "Sync()";
    return SendRecvMsg(str,50000000);
}

std::string CDobotMove::RelMovJUser(const CDescartesPoint& pt, int User)
{
    std::ostringstream oss;
    oss << "RelMovJUser(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ','
        << std::to_string(User) << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::RelMovLUser(const CDescartesPoint& pt, int User)
{
    std::ostringstream oss;
    oss << "RelMovLUser(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ','
        << std::to_string(User) << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::RelMovJTool(const CDescartesPoint& pt, int Tool)
{
    std::ostringstream oss;
    oss << "RelMovJTool(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ','
        << std::to_string(Tool) << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::RelMovLTool(const CDescartesPoint& pt, int Tool)
{
    std::ostringstream oss;
    oss << "RelMovLTool(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ','
        << std::to_string(Tool) << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::RelJointMovJ(const CDescartesPoint& pt)
{
    std::ostringstream oss;
    oss << "RelJointMovJ(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDobotMove::wait()
{
    std::string str = "wait()";
    return SendRecvMsg(str);
}

std::string CDobotMove::pause()
{
    std::string str = "pause()";
    return SendRecvMsg(str);
}

std::string CDobotMove::Continue()
{
    std::string str = "continue()";
    return SendRecvMsg(str);
}
}    // namespace Dobot
