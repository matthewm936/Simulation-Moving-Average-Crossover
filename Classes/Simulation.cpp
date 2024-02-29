#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "MovingAverage.cpp"
#include "MovingAverageCrossover.cpp"
#include "MovingAverageLengths.cpp"

#include <string>
#include <iostream> 
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

class Simulation {
private:
	string fileName;

public:
	Simulation(const string& fileName, vector<MovingAverageLengths> testingValues) {
		this->fileName = fileName;
	}

	void run() {
		ifstream file(this->fileName);

		if (!std::filesystem::exists(fileName)) {	
			std::cerr << "File does not exist: " << fileName << std::endl;
			return;
		}

		if(!file) {
			cerr << "Failed to open file: " << fileName << endl;
			return;
		}

		string filetext;
		// loop through the file and update the moving average crossover on each testingValue
		while(getline(file, filetext)) {
			cout << filetext << endl;
		}

	}
};

#endif 
