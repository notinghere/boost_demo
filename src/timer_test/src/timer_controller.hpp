#include <iostream>
#include <time.h>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>
#include <boost/function.hpp>
#include <boost/date_time/posix_time/posix_time.hpp>

using namespace boost::asio::placeholders;
using namespace std;

//超时控制器类
class TimerController
{
public:

    /**
     * 超时控制器构造函数
     * @param ios 异步I/O对象
     * @param callbackFunc 超时处理回调函数
     * @param uiWaitSec 定时器间隔等待时间，单位：秒
     */
    explicit TimerController(boost::asio::io_service& ios, boost::function<void()> callbackFunc, unsigned int uiWaitSec) :
            m_timer(ios, boost::posix_time::seconds(uiWaitSec))
    {
        cout << "construct" << "-----" << time(NULL) << endl;
        m_timeoutHandle = callbackFunc;
        m_uiWaitSec = uiWaitSec;
        m_timer.async_wait(boost::bind(&TimerController::onTime, this, boost::asio::placeholders::error));
    }

    ~TimerController()
    {
        m_timer.cancel();
    }

    void onTime(const boost::system::error_code& ec)
    {
        if (ec.value() == boost::system::errc::success)
        {
            cout << "timeout" << "-----" << time(NULL) << std::endl;
            m_timeoutHandle();
            m_timer.expires_at(m_timer.expires_at() + boost::posix_time::seconds(m_uiWaitSec));
        }

        m_timer.async_wait(boost::bind(&TimerController::onTime, this, boost::asio::placeholders::error));
    }

    void Reset(unsigned int seconds) {

        m_uiWaitSec = seconds;
        m_timer.expires_from_now(boost::posix_time::seconds(m_uiWaitSec));
    }

private:
    unsigned int                    m_uiWaitSec;                //定时间间隔等待时间
    boost::asio::deadline_timer     m_timer;                    //asio定时器
    boost::function<void()>         m_timeoutHandle;            //超时处理回调函数
};

// 构造函数
class CmdQueueManager
{
public:
    CmdQueueManager(boost::asio::io_service* io)
    {
        m_pTimer = new TimerController(*io, boost::bind(&CmdQueueManager::SendProcess, this), 2);
    }

    void SendProcess()
    {
        cout << "func callback" << "-----" << time(NULL) << endl;
    }

    void ResetTimer(unsigned int seconds) {
        m_pTimer->Reset(seconds);
    }

    TimerController* m_pTimer;
};
