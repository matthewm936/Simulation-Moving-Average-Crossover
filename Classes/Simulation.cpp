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

public:
	Simulation(const string& fileName) {
		this->fileName = fileName;
	}

	void run() {
		cout << "Running simulation on: " << this->fileName << endl;
		// MovingAverageCrossover mac = MovingAverageCrossover(i, j);

	}
};

#endif 
