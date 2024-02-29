#ifndef MovingAverageLengths_CPP
#define MovingAverageLengths_CPP

using namespace std;

class MovingAverageLengths {
private:
	int slow;
	int fast;

public:
	MovingAverageLengths(int slow, int fast) : slow(slow), fast(fast) {}

	int getSlow() const {
		return slow;
	}

	int getFast() const {
		return fast;
	}
};

#endif
