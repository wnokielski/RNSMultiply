#ifndef CONV_H_
#define CONV_H_

#include <vector>

using namespace std;

class Conv{

public:

	static long floatToMachineValue(float f, int fractionalModulesNumber, vector<long> modules, long Rf);

	static vector<long> machineValueToRNS(long machineValue, vector<long> modules);

	static vector<long> intermediateProductToMRN(vector<long> number, vector<long> modules, int fractionalModulesNumber, vector<long> PT);

	static vector<long> getMultiplicativeInversion(long number, vector<long> modules);

	static vector<long> truncatedMRNToRNS(vector<long> trunc, vector<long> PT, vector<long> modules, int fractionalModulesNumber);

};



#endif /* CONV_H_ */
