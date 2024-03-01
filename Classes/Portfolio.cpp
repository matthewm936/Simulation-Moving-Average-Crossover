#ifndef PORTFOLIO_CPP
#define PORTFOLIO_CPP

#include "IndicatorDirection.cpp"

class Portfolio {
private:
	double profit;
	double winPercentage;
	int trades;
	int longs;
	int shorts;

public:
	Portfolio() {
		this->profit = 0.0;
		this->winPercentage = 0.0;
		this->trades = 0;
		this->longs = 0;
		this->shorts = 0;
	}

	void addTradeCount(IndicatorDirection direction) {
		if (direction == IndicatorDirection::LONG) {
			this->longs++;
		} else if (direction == IndicatorDirection::SHORT) {
			this->shorts++;
		}
		this->trades++;
	}

	void addProfit(double profit) {
		this->profit += profit;
	}
};

#endif 
