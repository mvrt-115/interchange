#include <pair>

class Timer{
public:
	enum timeExponent {seconds = 0, deciseconds = 1, centiseconds = 2, milliseconds = 3, microseconds = 6, nanoseconds = 9};	
	typedef pair<int, timeExponent> chronon;  

	virtual chronon getTime() = 0;
};
