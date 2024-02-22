#ifndef MOVINGAVERAGE_H
#define MOVINGAVERAGE_H

class MovingAverage {
	private:
		enum IndicatorDirection {
			BULL,
			BEAR,
			NEUTRAL
		}

		int length;
		double average;
		IndicatorDirection currentDirection;

		void update(double currentPrice);
	
	public:
		MovingAverage();

		~MovingAverage();

}