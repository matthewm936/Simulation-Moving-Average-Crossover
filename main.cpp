#include "Classes\MovingAverage.cpp"
#include "Classes\Portfolio.cpp"
#include "Classes\Simulation.cpp"
#include "Classes\Dataset.cpp"
#include "Classes\Paramaterization.cpp"

#include <iostream>
#include <chrono>
#include <cmath>

int main(int argc, char* argv[]) {
	// Start timer
	auto start = chrono::high_resolution_clock::now();

	// Setup data
	vector<string> rawDataFiles = { 
		// "./Raw Data/BTC-USD-Daily-Yahoo.csv", 
		"./Raw Data/BTC-USD-Monthly-Yahoo.csv", 
		// "./Raw Data/BTC-USD-Weekly-Yahoo.csv" 
	};
	vector<string> subsectionDataFiles = { 
		"./Clean Data/Daily-2017-Feb-23-to-2017-Dec-17.csv", 
		"./Clean Data/Daily-2020-Nov-30-to-21-Apr-14.csv" 
	};
	
	Dataset dataset(rawDataFiles, subsectionDataFiles);

	// Get the cleaned data
	vector<string> cleanedData = dataset.getCleanedFilePaths();

	// Create parameters for moving average crossover lengths
	Paramaterization parameters(50);
	vector<MovingAverageCrossover> movingAverageCrossovers = parameters.getTestingValues();

	for (size_t i = 0; i < cleanedData.size(); i++) {
		// Run simulation trading on each time frame section
		Simulation sim(cleanedData[i], movingAverageCrossovers);
		sim.run();
	}

	// End timer
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "Run time: " << duration.count() << " milliseconds : " << duration.count() / 1000 << " seconds" << endl;

	return 0;
}
