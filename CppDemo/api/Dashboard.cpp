#include "Dashboard.h"
#include <sstream>

namespace Dobot
{
    CDashboard::CDashboard() {}
    CDashboard::~CDashboard() {}

    void CDashboard::OnConnected()
    {
    }
    void CDashboard::OnDisconnected()
    {
    }

    std::string CDashboard::ClearError()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ClearError()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::PowerOn()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "PowerOn()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(15000);
    }

    std::string CDashboard::PowerOff()
    {
        return EmergencyStop();
    }

    std::string CDashboard::EmergencyStop()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "EmergencyStop()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(15000);
    }

    std::string CDashboard::EnableRobot()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "EnableRobot()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(20000);
    }

    std::string CDashboard::EnableRobot(double load)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "EnableRobot(" + std::to_string(load) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(20000);
    }

    std::string CDashboard::EnableRobot(double load, double centerX, double centerY, double centerZ)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "EnableRobot(" + std::to_string(load) + "," + std::to_string(centerX) + "," + std::to_string(centerY) + "," + std::to_string(centerZ) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(20000);
    }

    std::string CDashboard::DisableRobot()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "DisableRobot()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(20000);
    }

    std::string CDashboard::ResetRobot()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ResetRobot()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(20000);
    }

    std::string CDashboard::SpeedFactor(int ratio)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "SpeedFactor(" << ratio << ")";
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    /*
        std::string CDashboard::DigitalOutputs(int index, bool status)
        {
            if (!IsConnected())
            {
                return "device does not connected!!!";
            }

            std::ostringstream oss;
            oss << "DO(" << index << "," << (status ? 1 : 0) << ")";
            std::string str = oss.str();
            if (!SendData(str))
            {
                return str + ":send error";
            }

            return WaitReply(5000);
        }
    */

    std::string CDashboard::GetErrorID()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetErrorID()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::User(int index)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "User(" + std::to_string(index) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::Tool(int index)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "Tool(" + std::to_string(index) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::RobotMode()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "RobotMode()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::PayLoad(double weight, double inertia)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "PayLoad(" + std::to_string(weight) + "," + std::to_string(inertia) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::DO(int index, int status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "DO(" + std::to_string(index) + "," + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::DOExecute(int index, int status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "DOExecute(" + std::to_string(index) + "," + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::ToolDO(int index, int status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ToolDO(" + std::to_string(index) + "," + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::ToolDOExecute(int index, int status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ToolDOExecute(" + std::to_string(index) + "," + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::AO(int index, int status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "AO(" + std::to_string(index) + "," + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::AOExecute(int index, int status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "AOExecute(" + std::to_string(index) + "," + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::AccJ(int Rprecent)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "AccJ(" + std::to_string(Rprecent) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::AccL(int Rprecent)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "AccL(" + std::to_string(Rprecent) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::Arch(int index)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "Arch(" + std::to_string(index) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::Arch(int index, std::string cpValue)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "Arch(" + std::to_string(index) + "," + std::string(cpValue) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SpeedJ(int Rprecent)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SpeedJ(" + std::to_string(Rprecent) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SpeedL(int Rprecent)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SpeedL(" + std::to_string(Rprecent) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::CP(int Rprecent)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "CP(" + std::to_string(Rprecent) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SetArmOrientation(int LorR)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetArmOrientation(" + std::to_string(LorR) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SetArmOrientation(int LorR, int UorD, int ForN, int Config6)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetArmOrientation(" + std::to_string(LorR) + "," +
                          std::to_string(UorD) + "," + std::to_string(ForN) + "," + std::to_string(Config6) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::RunScript(std::string projectName)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "RunScript(" + std::string(projectName) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::StopScript()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "StopScript()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::PauseScript()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "PauseScript()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::ContinueScript()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ContinueScript()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SetPayload(float load)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetPayload(" + std::to_string(load) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::PositiveSolution(const CDescartesPoint &pt, int User, int Tool)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "PositiveSolution(" + std::to_string(pt.x) + "," + std::to_string(pt.y) + "," +
                          std::to_string(pt.z) + "," + std::to_string(pt.rx) + "," + std::to_string(pt.ry) + "," +
                          std::to_string(pt.y) + "," + std::to_string(User) + "," + std::to_string(Tool) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::InverseSolution(const CDescartesPoint &pt, int User, int Tool)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "InverseSolution(" + std::to_string(pt.x) + "," + std::to_string(pt.y) + "," +
                          std::to_string(pt.z) + "," + std::to_string(pt.rx) + "," + std::to_string(pt.ry) + "," +
                          std::to_string(pt.y) + "," + std::to_string(User) + "," + std::to_string(Tool) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SetCollisionLevel(int level)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetCollisionLevel(" + std::to_string(level) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SetSafeSkin(int status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetSafeSkin(" + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SetObstacleAvoid(int status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetObstacleAvoid(" + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetTraceStartPose(std::string traceName)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetTraceStartPose(" + std::string(traceName) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetPathStartPose(std::string traceName)
    {

        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetPathStartPose(" + std::string(traceName) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::HandleTrajPoints(std::string traceName)
    {

        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "HandleTrajPoints(" + std::string(traceName) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::GetSixForceData()
    {

        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetSixForceData()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::SetCollideDrag(int status)
    {

        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetCollideDrag(" + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::SetTerminalKeys(int status)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetTerminalKeys(" + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::SetTerminal485(int baudRate, int dataLen, std::string parityBit, int stopBit)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetTerminal485(" + std::to_string(baudRate) + "," + std::to_string(dataLen) + "," +
                          std::string(parityBit) + "," + std::to_string(stopBit) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::GetTerminal485()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetTerminal485()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::TCPSpeed(int vt)
    {

        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "TCPSpeed(" + std::to_string(vt) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::TCPSpeedEnd()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "TCPSpeedEnd()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::GetAngle()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetAngle()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetPose()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetPose()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetPose(int user, int tool)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetPose(" + std::to_string(user) + "," + std::to_string(tool) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::ModbusCreate(std::string ip, int port, int slave_id)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ModbusCreate(" + std::string(ip) + "," + std::to_string(port) +
                          std::to_string(slave_id) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::ModbusCreate(std::string ip, int port, int slave_id, int isRTU)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ModbusCreate(" + std::string(ip) + "," + std::to_string(port) +
                          std::to_string(slave_id) + std::to_string(isRTU) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::ModbusClose(int index)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ModbusClose(" + std::to_string(index) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetInBits(int index, int addr, int count)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetInBits(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                          std::to_string(count) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetInRegs(int index, int addr, int count)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetInRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                          std::to_string(count) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetInRegs(int index, int addr, int count, std::string valType)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetInRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                          std::to_string(count) + "," + std::string(valType) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetCoils(int index, int addr, int count)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetCoils(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                          std::to_string(count) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SetCoils(int index, int addr, int count, std::string valTab)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetCoils(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                          std::to_string(count) + "," + std::string(valTab) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetHoldRegs(int index, int addr, int count)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetHoldRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                          std::to_string(count) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::GetHoldRegs(int index, int addr, int count, std::string valType)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "GetHoldRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                          std::to_string(count) + "," + std::string(valType) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SetHoldRegs(int index, int addr, int count, std::string valTab)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetHoldRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                          std::to_string(count) + "," + std::string(valTab) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::SetHoldRegs(int index, int addr, int count, std::string valTab, std::string valType)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "SetHoldRegs(" + std::to_string(index) + "," + std::to_string(addr) + "," +
                          std::to_string(count) + "," + std::string(valTab) + "," + std::string(valType) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::DI(int index)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "DI(" + std::to_string(index) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::ToolDI(int index)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ToolDI(" + std::to_string(index) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::AI(int index)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "AI(" + std::to_string(index) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::ToolAI(int index)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "ToolAI(" + std::to_string(index) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::DIGroup(int index, int value)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "DIGroup(" + std::to_string(index) + "," + std::to_string(value) + ")";
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::DOGroup(int index, int value)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "DOGroup(" + std::to_string(index) + "," + std::to_string(value) + ")";
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDashboard::BrakeControl(int axisID, int value)
    {

        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "BrakeControl(" + std::to_string(axisID) + "," + std::to_string(value) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::StartDrag()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        std::string str = "StartDrag()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::StopDrag()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        std::string str = "StopDrag()";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };

    std::string CDashboard::LoadSwitch(int status)
    {

        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        std::string str = "LoadSwitch(" + std::to_string(status) + ")";
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };
}