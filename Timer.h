
template <class T>
class Timer{
public:
	typedef T timestamp;

	virtual timestamp getTime() = 0;
};
