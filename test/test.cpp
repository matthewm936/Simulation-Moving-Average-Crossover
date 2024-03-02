#include <deque>
#include <iostream>
#include <cassert>
#include <vector>

#include "..\Classes\Paramaterization.cpp"
#include "..\Classes\MovingAverage.cpp"
#include "..\Classes\MovingAverageCrossover.cpp"
#include "..\Classes\Dataset.cpp"
#include "..\Classes\Simulation.cpp"

using namespace std;

class Test {
	public:
		Test() {
			testSMAUpdate();
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
				// Run simulation trading on each time frame section
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
			// cout << "TEST: Parameterization" << endl;
			// cout << "Params Size: " << size << endl;
			cout << MAC.size() << endl;
			assert(MAC.size() < size * size);
		}

		void testPrameterizationSize() {
			for (int size = 5; size <= 40; size++) {
				Paramaterization params(size);
				vector<MovingAverageCrossover> MAC = params.getTestingValues();
				assert(MAC.size() < (size * size) / 2);
			}
			cout << "TEST: Parameterization Size" << endl;
		}

		void testSMAUpdate() {
			MovingAverage ma = MovingAverage(3);

			// [1]
			ma.update(1);
			assert(ma.getAverage() == 1.0);
			assert(ma.getLength() >= ma.getSize());

			// [1, 2]
			ma.update(2);
			assert(ma.getAverage() == 1.5);
			assert(ma.getLength() >= ma.getSize());

			// [1, 2, 3]
			ma.update(3);
			assert(ma.getAverage() == 2.0);
			assert(ma.getLength() >= ma.getSize());

			// [2, 3, 4]
			ma.update(4);
			assert(ma.getAverage() == 3.0);
			assert(ma.getLength() >= ma.getSize());

			// [3, 4, 5]
			ma.update(5);
			assert(ma.getAverage() == 4.0);
			assert(ma.getLength() >= ma.getSize());

			// [4, 5, 6]
			ma.update(6);
			assert(ma.getAverage() == 5.0);
			assert(ma.getLength() >= ma.getSize());

			// [5, 6, 10]
			ma.update(10);
			assert(ma.getAverage() == 7.0);
			assert(ma.getLength() >= ma.getSize());

			// [6, 10, 11]
			ma.update(11);
			assert(ma.getAverage() == 9.0);
			assert(ma.getLength() >= ma.getSize());

			deque<double> values = ma.getValues();

			cout << "TEST: SMA update" << endl;
		}
};

int main() {
	Test test = Test();
	return 0;
}