#include <iostream>
#include <boost/asio.hpp>
#include "printer.hpp"
#include "timer_controller.hpp"

void syn_timer()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer tm(io, boost::posix_time::seconds(3));

    tm.wait();
    std::cout << "3 seconds finished!\n";
}

void print(const boost::system::error_code& ec)
{
    if (ec.value() == boost::system::errc::operation_canceled)
    {
        std::cout << "timer is canceled\n";
        return;
    }

    if (ec.value() == boost::system::errc::success)
    {
        std::cout << "timer is success finished\n";
        return;
    }
}

void async_timer()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));

    timer.async_wait(&print);
    io.run();
}

void cancel_timer()
{
    boost::asio::io_service io;

    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(5));
    timer.async_wait(&print);

    boost::asio::deadline_timer timer2(io, boost::posix_time::seconds(2));
    timer2.wait();
    timer.cancel();

    io.run();
}


typedef std::function<void(const boost::system::error_code&)> timer_callback;

void change_timer()
{
    boost::asio::io_service io;
    boost::asio::deadline_timer timer(io, boost::posix_time::seconds(1));

    timer_callback callback = [&](const boost::system::error_code& err)
    {
        print(err);
        timer.expires_at(timer.expires_at() + boost::posix_time::seconds(1));
        timer.async_wait(callback);
    };

    timer.async_wait(callback);
    io.run();
}

void do_printer() {
    boost::asio::io_service io;
    printer p(io);
    io.run();
}

void do_timer_controller()
{
    boost::asio::io_service io;

    CmdQueueManager t(&io);

    io.run();
}

int main()
{
//    syn_timer();
//    async_timer();
//    cancel_timer();
//    change_timer();
//    do_printer();
    do_timer_controller();

    return 0;
}