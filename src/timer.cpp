#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

#include "timer.hpp"

void Timer::start()
{
    if (!m_bRunning)
    {
        // If the timer is not running, resume from the previous stop time
        auto currentTime = std::chrono::system_clock::now();
        m_StartTime += (currentTime - m_StopTime);
        m_bRunning = true;
    }
    else
    {
        // If the timer is already running, do nothing
    }
}

void Timer::stop()
{
    if (m_bRunning)
    {
        // If the timer is running, record the current time as the stop time
        m_StopTime = std::chrono::system_clock::now();
        m_bRunning = false;
    }
    else
    {
        // If the timer is already stopped, do nothing
    }
}

float Timer::elapsedMilliseconds()
{
    std::chrono::time_point<std::chrono::system_clock> endTime;

    if (m_bRunning)
    {
        endTime = std::chrono::system_clock::now();
    }
    else
    {
        endTime = m_StopTime;
    }

    return std::chrono::duration_cast<std::chrono::milliseconds>(endTime - m_StartTime).count();
}

float Timer::elapsedSeconds()
{
    return elapsedMilliseconds() / 1000.0;
}

void Timer::resetMilliseconds(float ms)
{
    stop(); // Stop the timer

    // Set everything to 0
    m_StartTime = std::chrono::system_clock::now();
    m_StopTime = m_StartTime;
    m_bRunning = false;

    // Start the timer again if the provided milliseconds are greater than 0
    if (ms > 0)
    {
        m_StopTime += std::chrono::milliseconds(static_cast<long long>(ms));
        m_bRunning = true;
    }
}

long Timer::fibonacci(unsigned n)
{
    if (n < 2)
        return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}
