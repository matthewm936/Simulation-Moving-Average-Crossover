#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include "MovingAverage.cpp"
#include "MovingAverageCrossover.cpp"

#include <string>
#include <iostream> 
#include <vector>
#include <fstream>
#include <filesystem>

using namespace std;

class Simulation {
private:
	string fileName;
	vector<MovingAverageCrossover> movingAverageCrossovers;

public:
	Simulation(const string& fileName, vector<MovingAverageCrossover> movingAverageCrossovers) {
		this->fileName = fileName;
		this->movingAverageCrossovers = movingAverageCrossovers;
	}

	void run() {
		ifstream file(this->fileName);
		string filetext;

		if (!filesystem::exists(fileName)) {	
			cerr << "File does not exist: " << fileName << endl;
			return;
		}

		if(!file) {
			cerr << "Failed to open file: " << fileName << endl;
			return;
		}

		getline(file, filetext); // Skip the header

		for(auto& MAcrossover : movingAverageCrossovers) {
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
				MAcrossover.updateMovingAverageCrossover(stod(row[1]));
				MAcrossover.getSignal();
			}
			// cout << "--------------------------------" << endl 
			// 	<< "Fast length: " << MAcrossover.fast.getLength()
			// 	<< " Slow length: " << MAcrossover.slow.getLength()
			// 	<< endl
			// 	<< "Total returns: " 
			// 	<< MAcrossover.portfolio.getTotalReturns() << endl
			// 	<< "--------------------------------" << endl;
		}	
	}
};

#endif 
