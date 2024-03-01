#ifndef Trade_CPP
#define Trade_CPP

#include <string>


#include "IndicatorDirection.cpp"

using namespace std;

class Trade {
private:
	double entryPrice;

	IndicatorDirection currentDirection;

	public:
		Trade() {

		}

	void enterLong(double price) {
		entryPrice = price;
	}

	void enterShort(double price) {
		entryPrice = price;
	}

	double exitLong(double price) {
		return (price - entryPrice) / entryPrice;
	}

	double exitShort(double price) {
		return (entryPrice - price) / entryPrice;
	}
};

#endif 