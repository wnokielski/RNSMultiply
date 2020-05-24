#ifndef OPERATIONS_H_
#define OPERATIONS_H_

#include <vector>

using namespace std;

class Operations{

public:

	static vector<long> calculateIntermediateProduct(vector<long> x, vector<long> y, vector<long >modules);

	static vector<long> vectorSubtract(vector<long> x, vector<long> y, vector<long> modules);

	static vector<long> vectorMultiply(vector<long> x, vector<long> y, vector<long> modules);

	static void printVector(vector<long> vec);

};



#endif /* OPERATIONS_H_ */
