#ifndef MOVINGAVERAGECROSSOVER_CPP
#define MOVINGAVERAGECROSSOVER_CPP

#include "MovingAverage.cpp"
#include "Portfolio.cpp"
#include "IndicatorDirection.cpp"

class MovingAverageCrossover {
private:
	MovingAverage fast;
	MovingAverage slow;

	Portfolio portfolio;

public:
	MovingAverageCrossover(int fastLength, int slowLength) : fast(fastLength), slow(slowLength) {
		Portfolio portfolio;
	}

	void calculateMovingAverage(double currentPrice) {
		fast.update(currentPrice);
		slow.update(currentPrice);
	}

	IndicatorDirection getSignal() {
		if(fast.getAverage() > slow.getAverage()) {
			return IndicatorDirection::LONG;
		} else if(fast.getAverage() < slow.getAverage()) {
			return IndicatorDirection::SHORT;
		} else {
			return IndicatorDirection::NEUTRAL;
		}
	}
};

#endif 
