#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include <vector>

using namespace std;

class Operations{

public:

	static vector<long> calculateIntermediateProduct(vector<long> x, vector<long> y, vector<long >modules);

	static vector<long> vectorSubtract(vector<long> x, vector<long> y, vector<long> modules);

	static vector<long> vectorAdd(vector<long> x, vector<long> y, vector<long> modules);

	static vector<long> vectorMultiply(vector<long> x, vector<long> y, vector<long> modules);

	static void printVector(vector<long> vec);

	static long calculateRf(vector<long> modules, int fractionalModulesNumber);

	static vector<long> initializePowerTerms(vector<long> modules, int fractionalModulesNumber);

	static vector<long> compareAndRoundUp(vector<long> value, long Rf, vector<long> PT, vector<long> modules, int fractionalModulesNumber);

};



#endif /* OPERATIONS_H_ */
