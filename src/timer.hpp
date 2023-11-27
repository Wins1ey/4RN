#include <iostream>
#include <chrono>
#include <ctime>
#include <cmath>

class Timer
{
public:
    void start();
    void stop();
    void resetMilliseconds(float ms);
    
    float elapsedMilliseconds();
    float elapsedSeconds();

    long fibonacci(unsigned n);

private:
    std::chrono::time_point<std::chrono::system_clock> m_StartTime;
    std::chrono::time_point<std::chrono::system_clock> m_EndTime;
    std::chrono::time_point<std::chrono::system_clock> m_StopTime;
    bool                                               m_bRunning = false;
};