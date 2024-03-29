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
		for(int i = 1; i <= testingSize; i++) {
			for(int j = 1; j <= testingSize; j++) {
				if(i < j) {
					int slow = j;
					int fast = i;
					movingAverageCrossoverObjects.push_back(MovingAverageCrossover(fast, slow));
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
