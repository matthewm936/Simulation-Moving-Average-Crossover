#include "Classes\Algorithm.cpp"
#include "Classes\MovingAverage.cpp"
#include "Classes\Portfolio.cpp"
#include "Classes\Simulation.cpp"
#include "Classes\Dataset.cpp"
#include "test\test.cpp"


#include <iostream>
#include <chrono>

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
	int simSize = 150;

	for (size_t i = 0; i < cleanedData.size(); i++) {
		// Run simulation trading on each time frame
		Simulation sim(cleanedData[i], simSize);
		sim.run();
	}

	// Algorithm myAlgorithm;
	// MovingAverage myMovingAverage;
	// Portfolio myPortfolio;
	// Simulation mySimulation("data.txt"); // Assuming data.txt is the file name

	// // Use the classes as needed
	// // For example:
	// myAlgorithm.enterLong();
	// myAlgorithm.exitShort();
	// myMovingAverage.update(100.0);
	// myPortfolio.updateProfit(500.0);
	// mySimulation.run();


	// End timer
	auto end = chrono::high_resolution_clock::now();
	auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
	cout << "Time taken by program: " << duration.count() << " milliseconds" << endl;

	return 0;
}
