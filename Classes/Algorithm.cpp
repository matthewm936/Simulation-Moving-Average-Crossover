#ifndef ALGORITHM_CPP
#define ALGORITHM_CPP

#include <string>

using namespace std;

class Algorithm {
private:
	double entryPrice;
	double currentPrice;

	enum IndicatorDirection {
		BULL,
		BEAR,
		NEUTRAL,
		NONE
	};

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
		Algorithm(string name) {

		}

		~Algorithm() {
			
		}
};

#endif 