#include "Operations.h"
#include "Conv.h"
#include <vector>
#include <iostream>

void Operations::printVector(vector<long> vec){
	for(int i=0; i<vec.size(); i++){
		cout<<vec[i]<<" ";
	}
	cout<<"\n";
}

long Operations::calculateRf(vector<long>modules, int fractionalModulesNumber){
	long Rf = 1;

	for(int i=0; i< fractionalModulesNumber; i++){
		Rf = Rf * modules[i];
	}

	return Rf;
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

vector<long> Operations::vectorAdd(vector<long> x, vector<long> y, vector<long> modules){

	vector<long> product;

	for(int i=0;i<modules.size();i++){
		product.push_back((x[i] + y[i]) % modules [i]);
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

vector<long> Operations::initializePowerTerms(vector<long> modules, int fractionalModulesNumber){

	vector<long> PT;

	PT.push_back(1);

	for(int i=1; i<fractionalModulesNumber; i++){		//initializing first part power terms
		PT.push_back(PT.back()*modules[i-1]);
	}

	PT.push_back(1);		

	for(int i=fractionalModulesNumber+1; i<18; i++){	//initializing second part of power terms
		PT.push_back(PT.back()*modules[i-1]);
	}

	return PT;
}

vector<long> Operations::compareAndRoundUp(vector<long> value, long Rf, vector<long> PT, vector<long> modules, int fractionalModulesNumber){

	long comparedValue;

	for(int i=fractionalModulesNumber; i<18; i++){
		comparedValue += PT[i] * value[i];
	}

	if(comparedValue > Rf/2){
		value = Operations::vectorAdd(value, Conv::machineValueToRNS(1, modules), modules);
		return value;
	}
	else return value;

}
