#ifndef PARAMATERIZATION_H
#define PARAMATERIZATION_H

#include <iostream>
#include <vector>

#include "MovingAverageLengths.cpp"

using namespace std; 

class Paramaterization {

	// notes for htis class:
	// 1. This class will be used to store the paramaterization of the moving average crossover
	// which then can be passed into the ma for testing later
	// so this needs to be able to loop through and give the correct paramaterization to the ma
	// the input will be the tested values
private:
    vector<MovingAverageLengths> testingValues;

	void setTestingValues(int testingSize) {
		// built for parameterization of moving average crossover
		for(int i = 1; i < testingSize; i++) {
			for(int j = 1; j < testingSize; j++) {
				if(i < j) {
					int slow = j;
					int fast = i;
					testingValues.push_back(MovingAverageLengths(slow, fast));
				}
			}
		}	
		// cout << "Parameterization values created for: " << testingSize << endl;
	}

public:
	Paramaterization(int testingSize) {
		setTestingValues(testingSize);
	}

	vector<MovingAverageLengths> getTestingValues() {
		return this->testingValues;
	}

};

#endif 
