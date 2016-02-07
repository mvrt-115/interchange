#ifndef __INTERCHANGE_CPPTIMER_H
#define __INTERCHANGE_CPPTIMER_H

#include "Timer.h"
#include <chrono>

class CppTimer : public Timer{
public:
	CppTimer(int exponent);
	Timer::chronon getTime();
	typedef std::chrono::high_resolution_clock Clock;

private:
	int exp;
	Clock::time_point beginTime;
	int elapsedTime;
};
#endif
