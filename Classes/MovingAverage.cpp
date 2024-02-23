#ifndef MOVINGAVERAGE_CPP
#define MOVINGAVERAGE_CPP

class MovingAverage {
private:
	enum IndicatorDirection {
		BULL,
		BEAR,
		NEUTRAL,
		NONE
	};

	int length;
	double average;
	IndicatorDirection currentDirection;

	void update(double currentPrice);

public:
	MovingAverage(int length) {
		this->length = length;
		this->average = 0.0;
		this->currentDirection = NONE;
	}

	~MovingAverage() {
		
	}
};

#endif 
