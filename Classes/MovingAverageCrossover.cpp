#ifndef MOVINGAVERAGECROSSOVER_CPP
#define MOVINGAVERAGECROSSOVER_CPP

#include "MovingAverage.cpp"
#include "Portfolio.cpp"
#include "IndicatorDirection.cpp"

class MovingAverageCrossover {
private:

public:
	MovingAverage fast;
	MovingAverage slow;

	Portfolio portfolio = Portfolio();

	MovingAverageCrossover(int fastLength, int slowLength) : fast(fastLength), slow(slowLength) {
	}

	void updateMovingAverageCrossover(double currentPrice) {
		fast.update(currentPrice);
		slow.update(currentPrice);

		portfolio.updatePortfolio(getSignal(), currentPrice);		
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
