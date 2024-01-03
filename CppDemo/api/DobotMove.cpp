#include "DobotMove.h"
#include <sstream>

namespace Dobot
{
    CDobotMove::CDobotMove() {}
    CDobotMove::~CDobotMove() {}

    void CDobotMove::OnConnected()
    {
    }
    void CDobotMove::OnDisconnected()
    {
    }

    // 重载无参函数
    std::string CDobotMove::MoveJog()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "MoveJog()";

        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::StopMoveJog()
    {
        return MoveJog();
    }

    std::string CDobotMove::StartTrace(std::string traceName)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "StartTrace(" + std::string(traceName) + ")";

        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::StartPath(std::string traceName, int constInt, int cart)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::string str = "StartPath(" + std::string(traceName) + "," + std::to_string(constInt) + "," + std::to_string(cart) + ")";

        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    // 无可选参数
    std::string CDobotMove::MovJ(const CDescartesPoint &pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovJ(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::MovL(const CDescartesPoint &pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovL(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::JointMovJ(const CJointPoint &pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "JointMovJ(" << pt.j1 << ',' << pt.j2 << ',' << pt.j3 << ',' << pt.j4 << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    // std::string CDobotMove::RelMovJ()
    // {
    // }
    // std::string CDobotMove::RelMovL()
    // {
    // }

    std::string CDobotMove::MovLIO(const CDescartesPoint &pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovLIO(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::MovJIO(const CDescartesPoint &pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovJIO(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::Arc(const CDescartesPoint &pt, const CDescartesPoint &pt2)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "Arc(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ','
            << pt2.x << ',' << pt2.y << ',' << pt2.z << ',' << pt2.rx << ',' << pt2.ry << ',' << pt2.rz << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::ServoJ(const CJointPoint &pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "ServoJ(" << pt.j1 << ',' << pt.j2 << ',' << pt.j3 << ',' << pt.j4 << ',' << pt.j5 << ',' << pt.j6 << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::ServoP(const CDescartesPoint &pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "ServoP(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::Circle3(const CDescartesPoint &pt, const CDescartesPoint &pt2, int count)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "Circle3(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ','
            << pt2.x << ',' << pt2.y << ',' << pt2.z << ',' << pt2.rx << ',' << pt2.ry << ',' << pt2.rz << ',' << std::to_string(count) << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::Sync()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }
        std::string str = "Sync()";
        if (!SendData(str))
        {
            return str + ":send error";
        }
        return WaitReply(5000);
    }

    std::string CDobotMove::RelMovJUser(const CDescartesPoint &pt, int User)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "RelMovJUser(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ',' << std::to_string(User) << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::RelMovLUser(const CDescartesPoint &pt, int User)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "RelMovLUser(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ',' << std::to_string(User) << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::RelMovJTool(const CDescartesPoint &pt, int Tool)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "RelMovJTool(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ',' << std::to_string(Tool) << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::RelMovLTool(const CDescartesPoint &pt, int Tool)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "RelMovLTool(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ',' << std::to_string(Tool) << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::RelJointMovJ(const CDescartesPoint &pt)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "RelJointMovJ(" << pt.x << ',' << pt.y << ',' << pt.z << ',' << pt.rx << ',' << pt.ry << ',' << pt.rz << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    std::string CDobotMove::MovJExt(float offset)
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }

        std::ostringstream oss;
        oss << "MovJExt(" << std::to_string(offset) << ')';
        std::string str = oss.str();
        if (!SendData(str))
        {
            return str + ":send error";
        }

        return WaitReply(5000);
    }

    /*
        std::string CDobotMove::SyncAll()
        {
            if (!IsConnected())
            {
                return "device does not connected!!!";
            }
            std::string str = "SyncAll()";
            if (!SendData(str))
            {
                return str + ":send error";
            }
            return WaitReply(5000);
        }
    */

    std::string CDobotMove::wait()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }
        std::string str = "wait()";
        if (!SendData(str))
        {
            return str + ":send error";
        }
        return WaitReply(5000);
    }

    std::string CDobotMove::pause()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }
        std::string str = "pause()";
        if (!SendData(str))
        {
            return str + ":send error";
        }
        return WaitReply(5000);
    }

    std::string CDobotMove::Continue()
    {
        if (!IsConnected())
        {
            return "device does not connected!!!";
        }
        std::string str = "continue()";
        if (!SendData(str))
        {
            return str + ":send error";
        }
        return WaitReply(5000);
    }
}
