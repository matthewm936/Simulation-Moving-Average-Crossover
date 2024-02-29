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
	vector<MovingAverageLengths> testingValues;

public:
	Simulation(const string& fileName, vector<MovingAverageLengths> testingValues) {
		this->fileName = fileName;
		this->testingValues = testingValues;
	}

	void run() {
		ifstream file(this->fileName);

		if (!filesystem::exists(fileName)) {	
			cerr << "File does not exist: " << fileName << endl;
			return;
		}

		if(!file) {
			cerr << "Failed to open file: " << fileName << endl;
			return;
		}

		// create all the instances of the moving averages
		for (const auto& testingValue : testingValues) {
			MovingAverage slowMA(testingValue.getSlow());
			MovingAverage fastMA(testingValue.getFast());
		}

		string filetext;
		while (getline(file, filetext)) {
			vector<string> row;
			stringstream ss(filetext);
			string field;

			while (getline(ss, field, ',')) {
				row.push_back(field);
			}

			// CSV file layout
			// Date, Open, High, Low, Close, Adj Close, Volume
			// 0     1     2     3    4      5          6
			for (const auto& field : row) {
				cout << field << ' ';
			}
			cout << '\n';
		}
	}
};

#endif 
