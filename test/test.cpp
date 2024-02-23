#include <deque>

#include "Classes\MovingAverage.cpp"
#include <cassert>

using namespace std;

void testSMAUpdate() {
	MovingAverage ma = MovingAverage(5);
	ma.update(1);
	ma.update(2);
	ma.update(3);
	ma.update(4);
	ma.update(5);
	ma.update(6);
	ma.update(7);
	ma.update(8);
	ma.update(9);
	ma.update(10);
	deque<double> values = ma.getValues();
	assert(values.size() == 5);
	assert(values[0] == 10);
	assert(values[1] == 9);
	assert(values[2] == 8);
	assert(values[3] == 7);
	assert(values[4] == 6);
	assert(ma.getAverage() == 8);
}