#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "MovingAverage.cpp"
#include "MovingAverageCrossover.cpp"
#include "MovingAverageLengths.cpp"

#include <string>
#include <iostream> 
#include <vector>

using namespace std;

class Simulation {
private:
	string fileName;

public:
	Simulation(const string& fileName, vector<MovingAverageLengths> testingValues) {
		this->fileName = fileName;
	}

	void run() {
		cout << "Running simulation on: " << this->fileName << endl;

		// open the file...
		// loop through the file and update the moving average crossover on each testingValue

	}
};

#endif 
