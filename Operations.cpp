#include "Operations.h"
#include <vector>
#include <iostream>

void Operations::printVector(vector<long> vec){
	for(int i=0; i<vec.size(); i++){
		cout<<vec[i]<<" ";
	}
	cout<<"\n";
}

vector<long> Operations::calculateIntermediateProduct(vector<long> x, vector<long> y, vector<long >modules){

	vector<long> intermediateProduct;

	for(int i=0;i<modules.size();i++){
		intermediateProduct.push_back(x[i] * y[i] % modules [i]);
	}

	return intermediateProduct;

}

vector<long> Operations::vectorSubtract(vector<long> x, vector<long> y, vector<long> modules){

	vector<long> product;

	for(int i=0;i<modules.size();i++){
		long p = x[i] - y[i];
		if(p < 0) p += modules [i];
		product.push_back(p % modules [i]);
	}

	return product;

}

vector<long> Operations::vectorMultiply(vector<long> x, vector<long> y, vector<long> modules){

	vector<long> product;

	for(int i=0;i<modules.size();i++){
		//printf("X = %d, Y = %d, M = %d\n", x[i], y[i], modules[i]);
		product.push_back((x[i] * y[i]) % modules [i]);
	}

	return product;

}
