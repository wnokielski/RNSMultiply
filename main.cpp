#include <iostream>
#include <vector>
#include "Conv.h"
#include "Operations.h"

using namespace std;

vector<long> modules = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61};
int fractionalModulesNumber = 7;

float x, y;

long xMachineValue, yMachineValue;

long Rf;

vector<long> xMVRNS, yMVRNS;

vector<long> intermediateProduct;

vector<long> powerTerms;

vector<long> result;

int main(){

	cout<<"Mnożenie liczb stałoprzecinkowych wymiernych w RNS"<<endl;
	cout<<"Projekt OIaK"<<endl<<endl;
	cout<<"Autorzy:"<<endl;
	cout<<"Wojciech Nokielski 241312"<<endl;
	cout<<"Szymon Tusznio 241131"<<endl<<endl;

	cout<< "Podaj x: ";
	cin >> x;
	cout<<endl<<"Podaj y: ";
	cin>>y;

	powerTerms = Operations::initializePowerTerms(modules, fractionalModulesNumber);

	Rf = Operations::calculateRf(modules, fractionalModulesNumber);

	xMachineValue = Conv::floatToMachineValue(x, 7, modules, Rf);
	yMachineValue = Conv::floatToMachineValue(y, 7, modules, Rf);

	xMVRNS = Conv::machineValueToRNS(xMachineValue, modules);
	yMVRNS = Conv::machineValueToRNS(yMachineValue, modules);

	intermediateProduct = Operations::calculateIntermediateProduct(xMVRNS, yMVRNS, modules);

	result = Conv::intermediateProductToMRN(intermediateProduct, modules, fractionalModulesNumber, powerTerms);

	result = Conv::truncatedMRNToRNS(result, powerTerms, modules, fractionalModulesNumber);

	result = Operations::compareAndRoundUp(result, Rf, powerTerms, modules, fractionalModulesNumber);

	cout<<endl<<x<<" * "<<y<<" = "<<endl<<endl;

	Operations:: printVector(result);

	cout<<endl<<"w systemie RNS o modułach"<<endl<<endl;

	Operations::printVector(modules);

	cin>>y;

	return 1;
}
