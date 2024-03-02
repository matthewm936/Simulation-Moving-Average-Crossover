#include "..\Classes\MovingAverage.cpp"
#include "..\Classes\MovingAverageCrossover.cpp"

#ifndef TESTMAC_CPP
#define TESTMAC_CPP

const void assertLengthGreaterOrEqualSize(MovingAverageCrossover& mac) {
	assert(mac.slow.getLength() >= mac.slow.getSize());
	assert(mac.fast.getLength() >= mac.fast.getSize());
}

void testMAC() {
	MovingAverageCrossover mac = MovingAverageCrossover(3, 5);

	assert(mac.fast.speed == "fast");
	assert(mac.slow.speed == "slow");
	assert(mac.fast.getLength() < mac.slow.getLength());
	assert(mac.fast.getLength() == 3);
	assert(mac.slow.getLength() == 5);
	assert(mac.getSignal() == IndicatorDirection::NEUTRAL);

	// [1]
	mac.updateMovingAverageCrossover(1);
	assertLengthGreaterOrEqualSize(mac);

	// [1, 2]
	mac.updateMovingAverageCrossover(2);
	assertLengthGreaterOrEqualSize(mac);


	// [1, 2, 3]
	mac.updateMovingAverageCrossover(3);
	assertLengthGreaterOrEqualSize(mac);
	assert(mac.getSignal() == IndicatorDirection::NEUTRAL);

	// [1, 2, 3, 4]
	// [2, 3, 4]
	mac.updateMovingAverageCrossover(4);
	assert(mac.slow.getAverage() < mac.fast.getAverage());
	assert(mac.fast.getAverage() == 3.0);
	assert(mac.slow.getAverage() == 2.5);
	assertLengthGreaterOrEqualSize(mac);
	assert(mac.getSignal() == IndicatorDirection::LONG);


	// [1, 2, 3, 4, 5]
	// [3, 4, 5]
	mac.updateMovingAverageCrossover(5);
	assert(mac.slow.getAverage() < mac.fast.getAverage());
	assert(mac.fast.getAverage() == 4.0);
	assert(mac.slow.getAverage() == 3.0);
	assertLengthGreaterOrEqualSize(mac);
	assert(mac.getSignal() == IndicatorDirection::LONG);


	// [2, 3, 4, 5, 6]
	// [4, 5, 6]
	mac.updateMovingAverageCrossover(6);
	assert(mac.slow.getAverage() < mac.fast.getAverage());
	assert(mac.fast.getAverage() == 5.0);
	assert(mac.slow.getAverage() == 4.0);
	assertLengthGreaterOrEqualSize(mac);
	assert(mac.getSignal() == IndicatorDirection::LONG);


	// [3, 4, 5, 6, 10]
	// [5, 6, 10]
	mac.updateMovingAverageCrossover(10);
	assert(mac.slow.getAverage() < mac.fast.getAverage());
	assert(mac.fast.getAverage() == 7.0);
	assert(mac.slow.getAverage() == 28.0/5.0);
	assertLengthGreaterOrEqualSize(mac);
	assert(mac.getSignal() == IndicatorDirection::LONG);


	// [4, 5, 6, 10, 11]
	// [6, 10, 11]
	mac.updateMovingAverageCrossover(11);
	assert(mac.slow.getAverage() < mac.fast.getAverage());
	assert(mac.fast.getAverage() == 9.0);
	assert(mac.slow.getAverage() == 36.0/5.0);
	assertLengthGreaterOrEqualSize(mac);
	assert(mac.getSignal() == IndicatorDirection::LONG);

	// [5, 6, 10, 11, 1]
	// [10, 11, 1]
	mac.updateMovingAverageCrossover(1);
	assert(mac.slow.getAverage() < mac.fast.getAverage());
	assert(mac.fast.getAverage() == 22.0/3.0); //7.3
	assert(mac.slow.getAverage() == 6.6);
	assertLengthGreaterOrEqualSize(mac);
	assert(mac.getSignal() == IndicatorDirection::LONG);

	// [6, 10, 11, 1, 2]
	// [11, 1, 2]
	mac.updateMovingAverageCrossover(2);
	assert(mac.slow.getAverage() > mac.fast.getAverage());
	assert(mac.fast.getAverage() == 14.0/3.0); //4.67
	assert(mac.slow.getAverage() == 6.0);
	assertLengthGreaterOrEqualSize(mac);
	assert(mac.getSignal() == IndicatorDirection::SHORT);
	
	cout << "PASSED: MAC" << endl;
}

#endif