#ifndef Trade_CPP
#define Trade_CPP

#include <string>


#include "IndicatorDirection.cpp"

using namespace std;

class Trade {
private:
	double entryPrice;
	double currentPrice;

	IndicatorDirection currentDirection;


	void enterLong() {
		// Enter long implementation
	}

	void enterShort() {
		// Enter short implementation
	}

	void exitLong() {
		// Exit long implementation
	}

	void exitShort() {
		// Exit short implementation
	}

	public:
		Trade() {

		}

};

#endif 