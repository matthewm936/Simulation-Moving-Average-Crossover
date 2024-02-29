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
		while (getline(file, filetext)) {
			std::vector<std::string> row;
			std::stringstream ss(filetext);
			std::string field;

			while (std::getline(ss, field, ',')) {
				row.push_back(field);
			}

			// Now you can access individual fields in the row.
			for (const auto& field : row) {
				// std::cout << field << ' ';
			}
			// std::cout << '\n';
		}

	}
};

#endif 
