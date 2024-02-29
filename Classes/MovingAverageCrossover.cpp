#ifndef MOVINGAVERAGECROSSOVER_CPP
#define MOVINGAVERAGECROSSOVER_CPP

#include "MovingAverage.cpp"

class MovingAverageCrossover {
private:
	MovingAverage fast;
	MovingAverage slow;

	enum IndicatorDirection {
		LONG,
		SHORT,
		NEUTRAL,
		NONE
	};

public:
	MovingAverageCrossover(int fastLength, int slowLength) : fast(fastLength), slow(slowLength) {
	}

	void calculateMovingAverage(double currentPrice) {
		fast.update(currentPrice);
		slow.update(currentPrice);
	}

	IndicatorDirection getSignal() {
		if(fast.getAverage() > slow.getAverage()) {
			return LONG;
		} else if(fast.getAverage() < slow.getAverage()) {
			return SHORT;
		} else {
			return NEUTRAL;
		}
	}
};












#endif 
