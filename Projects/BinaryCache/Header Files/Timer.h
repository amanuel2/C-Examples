#pragma once
#include <chrono>
class Timer
{
public:
	Timer();
	~Timer();
	void Start();
    void Stop();
    void Reset();
    bool resettedCk();
    bool startedCk();
    bool stoppedCk();
    int getTimeHours();
    int getTimeMinutes();
    int getTimeSeconds();
    int getTimeMilliSeconds();
private:
    std::chrono::high_resolution_clock::time_point miniTimer,miniTimerEnd;
    bool started,stopped,reseted;
};
