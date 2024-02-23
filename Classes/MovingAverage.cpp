#ifndef MOVINGAVERAGE_CPP
#define MOVINGAVERAGE_CPP

#include <deque>
#include <cassert>


using namespace std;

class MovingAverage {
private:
	int length;
	int size;

	double average;
	double sum;

	deque<double> values;

public:
	MovingAverage(int length) {
		length = length;
		size = 0;
		average = 0.0;
		sum = 0.0;

		values = deque<double>();
	}

	void update(double currentPrice) {
		assert(length >= size);

		if (size == length) {
			sum -= values.back();
			values.pop_back();

			size--;
		}

		values.push_front(currentPrice);
		sum += currentPrice; 

		size++;
		average = sum / size;
	}

	double getAverage() {
		return average;
	}

	deque<double> getValues() {
		return values;
	}

	int getLength() {
		return length;
	}

	~MovingAverage() {
		
	}
};

#endif 
