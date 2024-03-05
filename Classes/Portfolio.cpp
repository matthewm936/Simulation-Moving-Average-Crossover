#ifndef PORTFOLIO_CPP
#define PORTFOLIO_CPP

#include "IndicatorDirection.cpp"
#include "Trade.cpp"

#include <cmath>
 
class Portfolio {
private:
	double returns;
	double positiveReturnTrade;

	int durationLong = 0;
	int durationShort = 0;

	IndicatorDirection currentDirection = IndicatorDirection::NONE;
	Trade trades = Trade();

	void totalReturns(double tradeReturn) {
		if(tradeReturn > 0) {
			this->positiveReturnTrade++;
		}
		this->returns *= (1 + tradeReturn);
	}

	void updateDuration(IndicatorDirection incomingDirection) {
		if (incomingDirection == IndicatorDirection::LONG) {
			durationLong++;
		} else if (incomingDirection == IndicatorDirection::SHORT) {
			durationShort++;
		}
	}

public:
	Portfolio() {
		this->positiveReturnTrade = 0.0;
		this->returns = 1;
	}

	void updatePortfolio(IndicatorDirection incomingDirection, double currentPrice) {
		updateDuration(incomingDirection);

		if(currentDirection == incomingDirection || incomingDirection == IndicatorDirection::NEUTRAL) {
			return;
		}
		if (currentDirection == IndicatorDirection::LONG && incomingDirection == IndicatorDirection::SHORT) {
			totalReturns(trades.exitLong(currentPrice));
			trades.enterShort(currentPrice);
		} else if (currentDirection == IndicatorDirection::SHORT && incomingDirection == IndicatorDirection::LONG) {
			totalReturns(trades.exitShort(currentPrice));
			trades.enterLong(currentPrice);
		} else if (currentDirection == IndicatorDirection::NONE) {
			if (incomingDirection == IndicatorDirection::LONG) {
				trades.enterLong(currentPrice);
			} else if (incomingDirection == IndicatorDirection::SHORT) {
				trades.enterShort(currentPrice);
			}
		}
		this->currentDirection = incomingDirection;
	}

	void closePortfolio(double currentPrice) {
		if (currentDirection == IndicatorDirection::LONG) {
			totalReturns(trades.exitLong(currentPrice));
		} else if (currentDirection == IndicatorDirection::SHORT) {
			totalReturns(trades.exitShort(currentPrice));
		} 
	}

	string getTradeStats() {
		string stats = "Return in %: ";
    	stats += to_string(returns * 100);
		stats += " num trades: ";
		stats += to_string(trades.getTrades());
		stats += " Longs entered: ";
		stats += to_string(trades.getLongs());
		stats += " Shorts entereed: ";
		stats += to_string(trades.getShorts());
		stats += " win %: ";
    	stats += to_string(this->positiveReturnTrade / trades.getTrades() * 100.0);
		stats += "%";
		stats += " Duration Long: ";
		stats += to_string(durationLong);
		stats += " Duration Short: ";
		stats += to_string(durationShort);
		return stats;
	}
};

#endif 
