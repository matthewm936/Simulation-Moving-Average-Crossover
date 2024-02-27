#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "MovingAverage.cpp"
#include "MovingAverageCrossover.cpp"

#include <string>
#include <iostream> 
#include <vector>

using namespace std;

class Simulation {
private:
	string fileName;
	int simSize;

public:
	Simulation(const string& fileName, int simSize) {
		this->fileName = fileName;
		this->simSize = simSize;
		cout << "Simulation size: " << this->simSize << endl;
	}

	void run() {
		cout << "Running simulation on: " << this->fileName << endl;
		for(int i = 1; i < simSize; i++) {
			for(int j = 1; j < simSize; j++) {
				if(i < j) {
					MovingAverageCrossover mac = MovingAverageCrossover(i, j);
					
				}
			}
		}
	}
};

#endif 
