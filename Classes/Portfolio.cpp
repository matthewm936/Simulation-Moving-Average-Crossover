#ifndef PORTFOLIO_CPP
#define PORTFOLIO_CPP

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
};

#endif 
