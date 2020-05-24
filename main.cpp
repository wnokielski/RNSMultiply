#include <iostream>
#include <vector>
#include "Conv.h"
#include "Operations.h"

using namespace std;

vector<long> modules = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
int fractionalModulesNumber = 7;

float x, y;

vector<long> xMVRNS, yMVRNS;

long xMachineValue, yMachineValue;

vector<long> intermediateProduct;

int main(){

	cout<< "Podaj x: ";
	cin >> x;
	cout<<endl<<"Podaj y:";
	cin>>y;

	xMachineValue = Conv::floatToMachineValue(x, 7, modules);
	yMachineValue = Conv::floatToMachineValue(y, 7, modules);

	xMVRNS = Conv::machineValueToRNS(xMachineValue, modules);
	yMVRNS = Conv::machineValueToRNS(yMachineValue, modules);

	intermediateProduct = Operations::calculateIntermediateProduct(xMVRNS, yMVRNS, modules);

//	printVector(intermediateProduct);
	cout<<endl;
	Operations::printVector(Conv::intermediateProductToMRN(intermediateProduct, modules, fractionalModulesNumber));
	cout<<endl;
	Operations::printVector(Conv::machineValueToRNS(13376954, modules));

	cin>>y;

	return 1;
}
