#include <pair>

class Timer{
public:
	typedef float milliseconds;
	virtual milliseconds getTime() = 0;
};
