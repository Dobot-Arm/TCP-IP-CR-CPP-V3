#include "Dashboard.h"
#include <sstream>

namespace Dobot
{
CDashboard::CDashboard()
{
}
CDashboard::~CDashboard()
{
}

void CDashboard::OnConnected()
{
}
void CDashboard::OnDisconnected()
{
}

std::string CDashboard::ClearError()
{
    std::string str = "ClearError()";
    return SendRecvMsg(str);
}

std::string CDashboard::PowerOn()
{
    std::string str = "PowerOn()";
    return SendRecvMsg(str, 15000);
}

std::string CDashboard::PowerOff()
{
    return EmergencyStop();
}

std::string CDashboard::EmergencyStop()
{
    std::string str = "EmergencyStop()";
    return SendRecvMsg(str, 15000);
}

std::string CDashboard::EnableRobot()
{
    std::string str = "EnableRobot()";
    return SendRecvMsg(str, 20000);
}

std::string CDashboard::EnableRobot(double load)
{
    std::string str = "EnableRobot(" + std::to_string(load) + ")";
    return SendRecvMsg(str, 20000);
}

std::string CDashboard::EnableRobot(double load, double centerX, double centerY, double centerZ)
{
    std::string str = "EnableRobot(" + std::to_string(load) + "," + std::to_string(centerX) + "," +
                      std::to_string(centerY) + "," + std::to_string(centerZ) + ")";
    return SendRecvMsg(str, 20000);
}

std::string CDashboard::DisableRobot()
{
    std::string str = "DisableRobot()";
    return SendRecvMsg(str, 20000);
}

std::string CDashboard::ResetRobot()
{
    std::string str = "ResetRobot()";
    return SendRecvMsg(str, 20000);
}

std::string CDashboard::SpeedFactor(int ratio)
{
    std::ostringstream oss;
    oss << "SpeedFactor(" << ratio << ")";
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDashboard::GetErrorID()
{
    std::string str = "GetErrorID()";
    return SendRecvMsg(str);
}

std::string CDashboard::User(int index)
{
    std::string str = "User(" + std::to_string(index) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::Tool(int index)
{
    std::string str = "Tool(" + std::to_string(index) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::RobotMode()
{
    std::string str = "RobotMode()";
    return SendRecvMsg(str);
};

std::string CDashboard::PayLoad(double weight, double inertia)
{
    std::string str = "PayLoad(" + std::to_string(weight) + "," + std::to_string(inertia) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::DO(int index, int status)
{
    std::string str = "DO(" + std::to_string(index) + "," + std::to_string(status) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::DOExecute(int index, int status)
{
    std::string str = "DOExecute(" + std::to_string(index) + "," + std::to_string(status) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::ToolDO(int index, int status)
{
    std::string str = "ToolDO(" + std::to_string(index) + "," + std::to_string(status) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::ToolDOExecute(int index, int status)
{
    std::string str = "ToolDOExecute(" + std::to_string(index) + "," + std::to_string(status) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::AO(int index, int status)
{
    std::string str = "AO(" + std::to_string(index) + "," + std::to_string(status) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::AOExecute(int index, int status)
{
    std::string str = "AOExecute(" + std::to_string(index) + "," + std::to_string(status) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::AccJ(int Rprecent)
{
    std::string str = "AccJ(" + std::to_string(Rprecent) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::AccL(int Rprecent)
{
    std::string str = "AccL(" + std::to_string(Rprecent) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::Arch(int index)
{
    std::string str = "Arch(" + std::to_string(index) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::Arch(int index, std::string cpValue)
{
    std::string str = "Arch(" + std::to_string(index) + "," + std::string(cpValue) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SpeedJ(int Rprecent)
{
    std::string str = "SpeedJ(" + std::to_string(Rprecent) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SpeedL(int Rprecent)
{
    std::string str = "SpeedL(" + std::to_string(Rprecent) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::CP(int Rprecent)
{
    std::string str = "CP(" + std::to_string(Rprecent) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SetArmOrientation(int LorR)
{
    std::string str = "SetArmOrientation(" + std::to_string(LorR) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SetArmOrientation(int LorR, int UorD, int ForN, int Config6)
{
    std::string str = "SetArmOrientation(" + std::to_string(LorR) + "," + std::to_string(UorD) + "," +
                      std::to_string(ForN) + "," + std::to_string(Config6) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::RunScript(std::string projectName)
{
    std::string str = "RunScript(" + std::string(projectName) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::StopScript()
{
    std::string str = "StopScript()";
    return SendRecvMsg(str);
};

std::string CDashboard::PauseScript()
{
    std::string str = "PauseScript()";
    return SendRecvMsg(str);
};

std::string CDashboard::ContinueScript()
{
    std::string str = "ContinueScript()";
    return SendRecvMsg(str);
};

std::string CDashboard::SetPayload(float load)
{
    std::string str = "SetPayload(" + std::to_string(load) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::PositiveSolution(const CDescartesPoint& pt, int User, int Tool)
{
    std::string str = "PositiveSolution(" + std::to_string(pt.x) + "," + std::to_string(pt.y) + "," +
                      std::to_string(pt.z) + "," + std::to_string(pt.rx) + "," + std::to_string(pt.ry) + "," +
                      std::to_string(pt.y) + "," + std::to_string(User) + "," + std::to_string(Tool) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::InverseSolution(const CDescartesPoint& pt, int User, int Tool)
{
    std::string str = "InverseSolution(" + std::to_string(pt.x) + "," + std::to_string(pt.y) + "," +
                      std::to_string(pt.z) + "," + std::to_string(pt.rx) + "," + std::to_string(pt.ry) + "," +
                      std::to_string(pt.y) + "," + std::to_string(User) + "," + std::to_string(Tool) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SetCollisionLevel(int level)
{
    std::string str = "SetCollisionLevel(" + std::to_string(level) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SetSafeSkin(int status)
{
    std::string str = "SetSafeSkin(" + std::to_string(status) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SetObstacleAvoid(int status)
{
    std::string str = "SetObstacleAvoid(" + std::to_string(status) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::GetTraceStartPose(std::string traceName)
{
    std::string str = "GetTraceStartPose(" + std::string(traceName) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::GetPathStartPose(std::string traceName)
{
    std::string str = "GetPathStartPose(" + std::string(traceName) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::HandleTrajPoints(std::string traceName)
{
    std::string str = "HandleTrajPoints(" + std::string(traceName) + ")";
    return SendRecvMsg(str);
}

std::string CDashboard::GetSixForceData()
{
    std::string str = "GetSixForceData()";
    return SendRecvMsg(str);
}

std::string CDashboard::SetCollideDrag(int status)
{
    std::string str = "SetCollideDrag(" + std::to_string(status) + ")";
    return SendRecvMsg(str);
}

std::string CDashboard::SetTerminalKeys(int status)
{
    std::string str = "SetTerminalKeys(" + std::to_string(status) + ")";
    return SendRecvMsg(str);
}

std::string CDashboard::SetTerminal485(int baudRate, int dataLen, std::string parityBit, int stopBit)
{
    std::string str = "SetTerminal485(" + std::to_string(baudRate) + "," + std::to_string(dataLen) + "," +
                      std::string(parityBit) + "," + std::to_string(stopBit) + ")";
    return SendRecvMsg(str);
}

std::string CDashboard::GetTerminal485()
{
    std::string str = "GetTerminal485()";
    return SendRecvMsg(str);
}

std::string CDashboard::TCPSpeed(int vt)
{
    std::string str = "TCPSpeed(" + std::to_string(vt) + ")";
    return SendRecvMsg(str);
}

std::string CDashboard::TCPSpeedEnd()
{
    std::string str = "TCPSpeedEnd()";
    return SendRecvMsg(str);
}

std::string CDashboard::GetAngle()
{
    std::string str = "GetAngle()";
    return SendRecvMsg(str);
};

std::string CDashboard::GetPose()
{
    std::string str = "GetPose()";
    return SendRecvMsg(str);
};

std::string CDashboard::GetPose(int user, int tool)
{
    std::string str = "GetPose(" + std::to_string(user) + "," + std::to_string(tool) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::ModbusCreate(std::string ip, int port, int slave_id)
{
    std::string str = "ModbusCreate(" + std::string(ip) + "," + std::to_string(port) + std::to_string(slave_id) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::ModbusCreate(std::string ip, int port, int slave_id, int isRTU)
{
    std::string str = "ModbusCreate(" + std::string(ip) + "," + std::to_string(port) + std::to_string(slave_id) +
                      std::to_string(isRTU) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::ModbusClose(int index)
{
    std::string str = "ModbusClose(" + std::to_string(index) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::GetInBits(int index, int addr, int count)
{
    std::string str =
        "GetInBits(" + std::to_string(index) + "," + std::to_string(addr) + "," + std::to_string(count) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::GetInRegs(int index, int addr, int count)
{
    std::string str =
        "GetInRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," + std::to_string(count) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::GetInRegs(int index, int addr, int count, std::string valType)
{
    std::string str = "GetInRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," + std::to_string(count) +
                      "," + std::string(valType) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::GetCoils(int index, int addr, int count)
{
    std::string str =
        "GetCoils(" + std::to_string(index) + "," + std::to_string(addr) + "," + std::to_string(count) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SetCoils(int index, int addr, int count, std::string valTab)
{
    std::string str = "SetCoils(" + std::to_string(index) + "," + std::to_string(addr) + "," + std::to_string(count) +
                      "," + std::string(valTab) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::GetHoldRegs(int index, int addr, int count)
{
    std::string str =
        "GetHoldRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," + std::to_string(count) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::GetHoldRegs(int index, int addr, int count, std::string valType)
{
    std::string str = "GetHoldRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                      std::to_string(count) + "," + std::string(valType) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SetHoldRegs(int index, int addr, int count, std::string valTab)
{
    std::string str = "SetHoldRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                      std::to_string(count) + "," + std::string(valTab) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::SetHoldRegs(int index, int addr, int count, std::string valTab, std::string valType)
{
    std::string str = "SetHoldRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                      std::to_string(count) + "," + std::string(valTab) + "," + std::string(valType) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::DI(int index)
{
    std::string str = "DI(" + std::to_string(index) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::ToolDI(int index)
{
    std::string str = "ToolDI(" + std::to_string(index) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::AI(int index)
{
    std::string str = "AI(" + std::to_string(index) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::ToolAI(int index)
{
    std::string str = "ToolAI(" + std::to_string(index) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::DIGroup(int index, int value)
{
    std::ostringstream oss;
    oss << "DIGroup(" + std::to_string(index) + "," + std::to_string(value) + ")";
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDashboard::DOGroup(int index, int value)
{
    std::ostringstream oss;
    oss << "DOGroup(" + std::to_string(index) + "," + std::to_string(value) + ")";
    std::string str = oss.str();
    return SendRecvMsg(str);
}

std::string CDashboard::BrakeControl(int axisID, int value)
{
    std::string str = "BrakeControl(" + std::to_string(axisID) + "," + std::to_string(value) + ")";
    return SendRecvMsg(str);
};

std::string CDashboard::StartDrag()
{
    std::ostringstream oss;
    std::string str = "StartDrag()";
    return SendRecvMsg(str);
};

std::string CDashboard::StopDrag()
{
    std::ostringstream oss;
    std::string str = "StopDrag()";
    return SendRecvMsg(str);
};

std::string CDashboard::LoadSwitch(int status)
{
    std::ostringstream oss;
    std::string str = "LoadSwitch(" + std::to_string(status) + ")";
    return SendRecvMsg(str);
};
}    // namespace Dobot