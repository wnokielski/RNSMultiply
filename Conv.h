#ifndef CONV_H_
#define CONV_H_

#include <vector>

using namespace std;

class Conv{

public:

	static long floatToMachineValue(float f, int fractionalModulesNumber, vector<long> modules);

	static vector<long> machineValueToRNS(long machineValue, vector<long> modules);

	static vector<long> intermediateProductToMRN(vector<long> number, vector<long> modules, int fractionalModulesNumber);

	static vector<long> getMultiplicativeInversion(long number, vector<long> modules);

};



#endif /* CONV_H_ */
