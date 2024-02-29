#include "Classes\Trade.cpp"
#include "Classes\MovingAverage.cpp"
#include "Classes\Portfolio.cpp"
#include "Classes\Simulation.cpp"
#include "Classes\Dataset.cpp"
#include "test\test.cpp"
#include "Classes\Paramaterization.cpp"

#include <iostream>
#include <chrono>
#include <cmath>

int main() {
	// Tests
	Test test;

	// Start timer
	auto start = chrono::high_resolution_clock::now();

	// Setup data
	Dataset dataset("BTC-USD-Daily-Yahoo.csv", true, false);

	// Get the cleaned data
	vector<string> cleanedData = dataset.getCleanedFilePaths();

	// Create parameters for moving average crossover lengths
	Paramaterization params(1000);
	vector<pair<int, int>> testingValues = params.getTestingValues();

	for (size_t i = 0; i < cleanedData.size(); i++) {
		// Run simulation trading on each time frame section
		Simulation sim(cleanedData[i]);
		sim.run();
	}

	// End timer
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "Run time: " << duration.count() << " milliseconds : " << duration.count() / 1000<< " seconds" << endl;

	return 0;
}
