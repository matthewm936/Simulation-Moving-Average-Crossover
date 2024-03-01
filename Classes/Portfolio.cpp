#ifndef PORTFOLIO_CPP
#define PORTFOLIO_CPP

#include "IndicatorDirection.cpp"
#include "Trade.cpp"

class Portfolio {
private:
	int trades;
	int longs;
	int shorts;

	double returns;
	double positiveReturnTrade;

	IndicatorDirection currentDirection = IndicatorDirection::NONE;
	Trade currentTrade = Trade();

	void addTradeCount(IndicatorDirection direction) {
		if (direction == IndicatorDirection::LONG) {
			this->longs++;
		} else if (direction == IndicatorDirection::SHORT) {
			this->shorts++;
		}
		this->trades++;
	}

	void totalReturns(double tradeReturn) {
		if(tradeReturn > 0) {
			this->positiveReturnTrade++;
		}
		this->returns *= (1 + tradeReturn);
	}

public:
	Portfolio() {
		this->positiveReturnTrade = 0.0;
		this->trades = 0;
		this->longs = 0;
		this->shorts = 0;
		this->returns = 1;
	}

	void updatePortfolio(IndicatorDirection incomingDirection, double currentPrice) {
		if(currentDirection == incomingDirection || incomingDirection == IndicatorDirection::NEUTRAL) {
			return;
		}

		if (currentDirection == IndicatorDirection::LONG && incomingDirection == IndicatorDirection::SHORT) {
			totalReturns(currentTrade.exitLong(currentPrice));
			currentTrade.enterShort(currentPrice);
		} else if (currentDirection == IndicatorDirection::SHORT && incomingDirection == IndicatorDirection::LONG) {
			totalReturns(currentTrade.exitShort(currentPrice));
			currentTrade.enterLong(currentPrice);
		} else if (currentDirection == IndicatorDirection::NONE) {
			if (incomingDirection == IndicatorDirection::LONG) {
				currentTrade.enterLong(currentPrice);
			} else if (incomingDirection == IndicatorDirection::SHORT) {
				currentTrade.enterShort(currentPrice);
			}
		}
		this->addTradeCount(incomingDirection);
		this->currentDirection = incomingDirection;
	}

	double getTotalReturns() {
		return this->returns;
	}
};

#endif 
