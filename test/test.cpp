#include "testSMA.cpp"
#include "testMAC.cpp"
#include "testPARAM.cpp"

using namespace std;

class Test {
	public:
		Test() {
			testSMA();
			testMAC();

			testParameterization();
		}

	private:
};

int main() {
	Test test;
	return 0;
}