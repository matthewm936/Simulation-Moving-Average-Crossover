#include "Classes\Trade.cpp"
#include "Classes\MovingAverage.cpp"
#include "Classes\Portfolio.cpp"
#include "Classes\Simulation.cpp"
#include "Classes\Dataset.cpp"
#include "test\test.cpp"

#include <iostream>
#include <chrono>
#include <cmath>

int main() {
	// Tests
	Test test;
	test.testSMAUpdate();

	// Start timer
	auto start = chrono::high_resolution_clock::now();

	// Setup data
	Dataset dataset("BTC-USD-Daily-Yahoo.csv", true, false);

	// Get the cleaned data
	vector<string> cleanedData = dataset.getCleanedData();

	// Set hyperparameters to analyze
	int exponent = 3;
	int simSize = 10;

	simSize = pow(simSize, exponent);

	for (size_t i = 0; i < cleanedData.size(); i++) {
		// Run simulation trading on each time frame section
		Simulation sim(cleanedData[i], simSize);
		sim.run();
	}

	// End timer
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "Run time: " << duration.count() << " milliseconds : " << duration.count() / 1000<< " seconds" << endl;

	return 0;
}
