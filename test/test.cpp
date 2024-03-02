#include <deque>
#include <iostream>
#include <cassert>
#include <vector>

#include "..\Classes\Paramaterization.cpp"
#include "..\Classes\MovingAverage.cpp"
#include "..\Classes\MovingAverageCrossover.cpp"
#include "..\Classes\Dataset.cpp"
#include "..\Classes\Simulation.cpp"

#include "testSMA.cpp"
#include "testMAC.cpp"

using namespace std;

class Test {
	public:
		Test() {
			testSMA();
			testMAC();

			testParameterization();
			testPrameterizationSize();
			testMovingAverageCrossover();
		}

	private:
		void testMovingAverageCrossover() {
			vector<string> rawDataFiles = { 
				"./Raw Data/BTC-USD-Monthly-Yahoo.csv"
			};

			Dataset dataset(rawDataFiles, rawDataFiles);
			vector<string> cleanedData = dataset.getCleanedFilePaths();

			Paramaterization params(5);
			vector<MovingAverageCrossover> MAC = params.getTestingValues();

			for (size_t i = 0; i < cleanedData.size(); i++) {
				Simulation sim(cleanedData[i], MAC);
				sim.run();
			}
		}

		void testParameterization() {
			int size = 5;
			Paramaterization params(size);
			vector<MovingAverageCrossover> MAC = params.getTestingValues();
			for(auto& lengths : MAC) {
				assert(lengths.slow.getLength() > lengths.fast.getLength());
			}
			assert(MAC.size() < size * size);
		}

		void testPrameterizationSize() {
			for (int size = 5; size <= 40; size++) {
				Paramaterization params(size);
				vector<MovingAverageCrossover> MAC = params.getTestingValues();
				assert(MAC.size() < (size * size) / 2);
			}
		}
};

int main() {
	Test test;
	return 0;
}