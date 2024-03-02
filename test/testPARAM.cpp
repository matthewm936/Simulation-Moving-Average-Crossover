#ifndef TESTPARAMETERIZATION_CPP
#define TESTPARAMETERIZATION_CPP

#include "..\Classes\Paramaterization.cpp"

void testParameterization() {
	for(int i = 0; i < 100; i++) {
		Paramaterization params = Paramaterization(i);
		vector<MovingAverageCrossover> MAC = params.getTestingValues();
		for(auto& lengths : MAC) {
			assert(lengths.slow.getLength() > lengths.fast.getLength());
		}
		assert(MAC.size() == static_cast<std::size_t>(((i - 1) * i) / 2));
		assert(MAC[i].slow.getLength() > MAC[i].fast.getLength());
	}
	cout << "PASSED: Paramaterization" << endl;
}

#endif 