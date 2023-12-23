#pragma once

#include "DobotClient.h"
#include "DobotMove.h"

namespace Dobot
{
    class CDashboard : public CDobotClient
    {
    public:
        CDashboard();
        virtual ~CDashboard();

        /// <summary>
        /// 复位，用于清除错误
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string ClearError();

        /// <summary>
        /// 机器人上电
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string PowerOn();

        /// <summary>
        /// 急停
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string PowerOff();

        /// <summary>
        /// 急停
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string EmergencyStop();

        /// <summary>
        /// 使能机器人
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string EnableRobot();
        std::string EnableRobot(double load);
        std::string EnableRobot(double load, double centerX, double centerY, double centerZ);

        /// <summary>
        /// 下使能机器人
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string DisableRobot();

        /// <summary>
        /// 机器人停止
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string ResetRobot();

        /// <summary>
        /// 设置全局速度比例。
        /// </summary>
        /// <param name="ratio">运动速度比例，取值范围：1~100</param>
        /// <returns>返回执行结果的描述信息</returns>
        std::string SpeedFactor(int ratio);

        /// <summary>
        /// 设置数字输出端口状态（队列指令）
        /// </summary>
        /// <param name="index">数字输出索引，取值范围：1~16或100~1000</param>
        /// <param name="status">数字输出端口状态，true：高电平；false：低电平</param>
        /// <returns>返回执行结果的描述信息</returns>
        std::string DO(int index, int status);
        // std::string DigitalOutputs(int index, bool status);   //DO

        /// <summary>
        /// 获取错误ID
        /// </summary>
        /// <returns>返回执行结果的描述信息</returns>
        std::string GetErrorID();

        std::string User(int index);
        std::string Tool(int index);
        std::string RobotMode();
        std::string PayLoad(double weight, double inertia);
        std::string DOExecute(int index, int status);
        std::string ToolDO(int index, int status);
        std::string ToolDOExecute(int index, int status);
        std::string AO(int index, int status);
        std::string AOExecute(int index, int status);
        std::string AccJ(int Rprecent);
        std::string AccL(int Rprecent);

        std::string Arch(int index);
        std::string Arch(int index, std::string cpAValue);

        std::string SpeedJ(int Rprecent);
        std::string SpeedL(int Rprecent);
        std::string CP(int Rprecent);
        std::string SetArmOrientation(int LorR);
        std::string SetArmOrientation(int LorR, int UorD, int ForN, int Config6);
        std::string RunScript(std::string projectName);
        std::string StopScript();
        std::string PauseScript();
        std::string ContinueScript();
        std::string SetPayload(float load);
        std::string PositiveSolution(const CDescartesPoint &pt, int User, int Tool);
        std::string InverseSolution(const CDescartesPoint &pt, int User, int Tool);

        template <typename... Args>
        std::string InverseSolution(const CDescartesPoint &pt, int User, int Tool, Args... args);

        std::string SetCollisionLevel(int level);

        std::string SetSafeSkin(int status);
        std::string SetObstacleAvoid(int status);
        std::string GetTraceStartPose(std::string traceName);
        std::string GetPathStartPose(std::string traceName);
        std::string HandleTrajPoints(std::string traceName);
        std::string GetSixForceData();
        std::string SetCollideDrag(int status);
        std::string SetTerminalKeys(int status);
        std::string SetTerminal485(int baudRate, int dataLen, std::string parityBit, int stopBit);
        std::string GetTerminal485();
        std::string TCPSpeed(int vt);
        std::string TCPSpeedEnd();

        std::string GetAngle();
        std::string GetPose();
        std::string GetPose(int user, int tool);

        std::string ModbusCreate(std::string ip, int port, int slave_id);
        std::string ModbusCreate(std::string ip, int port, int slave_id, int isRTU); //  重载可选参数

        std::string ModbusClose(int index);
        std::string GetInBits(int index, int addr, int count);

        std::string GetInRegs(int index, int addr, int count);
        std::string GetInRegs(int index, int addr, int count, std::string valType); //  重载可选参数

        std::string GetCoils(int index, int addr, int count);
        std::string SetCoils(int index, int addr, int count, std::string valTab);
        std::string GetHoldRegs(int index, int addr, int count);
        std::string GetHoldRegs(int index, int addr, int count, std::string valType); //  重载可选参数
        std::string SetHoldRegs(int index, int addr, int count, std::string valTab);
        std::string SetHoldRegs(int index, int addr, int count, std::string valTab, std::string valType); //  重载可选参数
        std::string DI(int index);
        std::string ToolDI(int index);
        std::string AI(int index);
        std::string ToolAI(int index);

        std::string DIGroup(int index, int value);
        template <typename... Args>
        std::string DIGroup(Args... args);

        std::string DOGroup(int index, int value);
        template <typename... Args>
        std::string DOGroup(Args... args);

        std::string BrakeControl(int axisID, int value);
        std::string StartDrag();
        std::string StopDrag();
        std::string LoadSwitch(int status);

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
        std::string strSend{""};
    };

    // 模版函数要定义声明到.h文件里面
    // 可选参数输出
    template <typename T>
    void CDashboard::printArg(T arg)
    {
        strSend = strSend + toString(arg) + ")";
    }

    // 递归输出可选参数
    template <typename T, typename... Args>
    void CDashboard::printArg(T arg, Args... args)
    {
        strSend = strSend + toString(arg) + ",";
        printArg(args...);
    }

    // 辅助函数，将参数转换为字符串
    template <typename T>
    std::string CDashboard::toString(T arg)
    {
        std::stringstream ss;
        ss << arg;
        return ss.str();
    }

    template <typename... Args>
    std::string CDashboard::DIGroup(Args... args)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "DIGroup(";
        strSend = oss.str();
        printArg(args...);
        std::string str = strSend;
        strSend.clear();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    template <typename... Args>
    std::string CDashboard::DOGroup(Args... args)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "DOGroup(";
        strSend = oss.str();
        printArg(args...);
        std::string str = strSend;
        strSend.clear();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    template <typename... Args>
    std::string CDashboard::InverseSolution(const CDescartesPoint &pt, int User, int Tool, Args... args)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "InverseSolution(" + std::to_string(pt.x) + "," +
                   std::to_string(pt.y) + "," + std::to_string(pt.z) + "," +
                   std::to_string(pt.rx) + "," + std::to_string(pt.ry) + "," +
                   std::to_string(pt.rz) + "," + std::to_string(User) + "," + std::to_string(Tool);
        strSend = oss.str();
        printArg(args...);
        std::string str = strSend;
        strSend.clear();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    };
}
