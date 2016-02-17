#include "CppTimer.h"
#include <math.h>
#include <utility>

CppTimer::CppTimer(){
	exp = exponent;
	beginTime = Clock::now();
}
Timer::milliseconds CppTimer::getTime(){
	return std::chrono::duration_cast<std::chrono::milliseconds>((Clock::now() - beginTime).count());
}
