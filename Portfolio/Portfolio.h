#ifndef PORTFOLIO_H
#define PORTFOLIO_H	

class Portfolio {
	private:
		double profit;
		double winPercentage;
		int trades;
		int longs;
		int shorts;
		
	public:
		Portfolio();

		~Portfolio();
};