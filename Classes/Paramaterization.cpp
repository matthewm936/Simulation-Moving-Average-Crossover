#ifndef PARAMATERIZATION_H
#define PARAMATERIZATION_H

#include <iostream>
#include <vector>

#include "MovingAverageCrossover.cpp"

using namespace std; 

class Paramaterization {

private:
    vector<MovingAverageCrossover> movingAverageCrossoverObjects;

	void setTestingValues(int testingSize) {
		// built for parameterization of moving average crossover
		for(int i = 1; i < testingSize; i++) {
			for(int j = 1; j < testingSize; j++) {
				if(i < j) {
					int slow = j;
					int fast = i;
					movingAverageCrossoverObjects.push_back(MovingAverageCrossover(slow, fast));
				}
			}
		}	
	}

public:
	Paramaterization(int testingSize) {
		setTestingValues(testingSize);
	}

	vector<MovingAverageCrossover> getTestingValues() {
		return this->movingAverageCrossoverObjects;
	}

};

#endif 
