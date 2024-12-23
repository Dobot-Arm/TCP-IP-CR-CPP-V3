#pragma once

#include <thread>

#include "DobotClient.h"
#include "FeedbackData.h"
#include <condition_variable>

namespace Dobot
{
    class CFeedback : public CDobotClient
    {
    public:
        CFeedback();
        virtual ~CFeedback();

        const CFeedbackData& GetFeedbackData() const;
        inline bool IsDataHasRead() const{
            return m_IsDataHasRead;
        }
        inline void SetDataHasRead(bool bValue)
        {
            m_IsDataHasRead = bValue;
        }
        std::string ConvertRobotMode();

    protected:
        void OnConnected() override;
        void OnDisconnected() override;

        /// <summary>
        /// 接收返回的数据并解析处理
        /// </summary>
        void OnRecvData();

        /// <summary>
        /// 解析数据
        /// </summary>
        /// <param name="buffer">一包完整的数据</param>
        void ParseData(char* pBuffer,int bufferLength);

    private:
        void Run();
        void ForceRefreshData();
        std::thread m_thd;
        std::atomic<bool> m_isRunning;      // 控制数据接收标志位
        std::atomic<bool> m_shouldRun;      // 控制线程的生命周期
        bool m_forceRefresh{false};         // 标识是否需要刷新数据

        std::mutex m_mutex2;
        std::mutex m_mutex3;
        std::mutex m_mutex4;
        bool m_IsDataHasRead = false;
        std::condition_variable m_condVar;

        CFeedbackData m_feedbackData;
    };
}

