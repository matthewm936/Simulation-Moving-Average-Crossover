#ifndef SIMULATION_CPP
#define SIMULATION_CPP

#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Simulation {
private:
	string fileName;

public:
	Simulation(const string& fileName) {
		this->fileName = fileName;
	}

	~Simulation() {
		
	}
};

#endif 
