#include "CppTimer.h"
#include <math.h>
#include <utility>

CppTimer::CppTimer(int exponent){
	exp = exponent;
	beginTime = Clock::now();
}
Timer::milliseconds CppTimer::getTime(){
	elapsedTime = std::chrono::duration_cast<std::chrono::nanoseconds>(Clock::now() - beginTime).count();
	return std::make_pair(time/(int)(pow(10, 9-exp)),exp);
}
