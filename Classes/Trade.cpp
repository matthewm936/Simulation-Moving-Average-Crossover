#ifndef Trade_CPP
#define Trade_CPP

#include <string>
#include <iostream>

#include "IndicatorDirection.cpp"

using namespace std;

class Trade {
private:
	double entryPrice;

	int trades = 0;
	int shorts = 0;
	int longs = 0;

	int longsClosed = 0;
	int shortsClosed = 0;

	IndicatorDirection currentDirection;

	public:
		Trade() {

		}

	void enterLong(double price) {
		longs++;
		trades++;
		entryPrice = price;
	}

	void enterShort(double price) {
		shorts++;
		trades++;
		entryPrice = price;
	}

	double exitLong(double price) {
		longsClosed++;
		return (price - entryPrice) / entryPrice;
	}

	double exitShort(double price) {
		shortsClosed++;
		return (entryPrice - price) / entryPrice;
	}

	int getTrades() {
		return trades;
	}

	int getShorts() {
		return shorts;
	}

	int getLongs() {
		return longs;
	}

	int getShortsClosed() {
		return shortsClosed;
	}

	int getLongsClosed() {
		return longsClosed;
	}
};

#endif 