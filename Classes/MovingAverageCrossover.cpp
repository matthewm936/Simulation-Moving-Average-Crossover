#ifndef MOVINGAVERAGECROSSOVER_CPP
#define MOVINGAVERAGECROSSOVER_CPP

#include "MovingAverage.cpp"

class MovingAverageCrossover {
private:
	MovingAverage fast;
	MovingAverage slow;

public:
	MovingAverageCrossover(int fastLength, int slowLength) : fast(fastLength), slow(slowLength) {
	}

	void update(double currentPrice) {
		fast.update(currentPrice);
		slow.update(currentPrice);
	}

	string getSignal() {
		if(fast.getAverage() > slow.getAverage()) {
			return "long";
		} else if(fast.getAverage() < slow.getAverage()) {
			return "short";
		} else {
			return "NONE";
		}
	}
};












#endif 
