#include "Conv.h"
#include "Operations.h"
#include <vector>
#include <iostream>
#include <algorithm>

enum compareFlag{
	LESS, EQUAL, GREATER
};

long Conv::floatToMachineValue(float f, int fractionalModulesNumber, vector<long> modules, long Rf){

	return f * Rf;

}

vector<long> Conv::machineValueToRNS(long machineValue, vector<long> modules){

	vector<long> intermediateProduct;

	for(int i=0; i<modules.size(); i++){
		intermediateProduct.push_back(machineValue % modules[i]);
	}

	return intermediateProduct;

}

vector<long> Conv::getMultiplicativeInversion(long number, vector<long> modules){

	int u, w, x, z, q;

	vector<long> inversion;

	for(int i=0; i<modules.size();i++){

		  u = 1; w = number;
		  x = 0; z = modules[i];
		  while( w )
		  {
		    if( w < z )
		    {
		      q = u; u = x; x = q;
		      q = w; w = z; z = q;
		    }
		    q = w / z;
		    u -= q * x;
		    w -= q * z;
		  }
		  if( z == 1 )
		  {
		    if( x < 0 ) x += modules[i];
		    inversion.push_back(x);
		  }
		  else
			  inversion.push_back(0);

	}

	return inversion;

}

vector<long> Conv::intermediateProductToMRN(vector<long> number, vector<long> modules, int fractionalModulesNumber, vector<long> PT){


	vector<long> MRC = number;
	reverse(MRC.begin(), MRC.end());

	vector<long> modulesRev = modules;
	reverse(modulesRev.begin(), modulesRev.end());

	vector<long> zeroVector = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0};	//zero vector for comparison
	vector<long> MRN;

	long ACC = 0;

	compareFlag cFlag = EQUAL;

	vector<long> d;		//d[i] in RNS
	vector<long> m;		//multiplicative inversion of module

	vector<long> c;		//rounding constants

	for(int i=0; i< fractionalModulesNumber; i++){		//initializing rounding constants
		c.push_back(modules[i]/2);
	}

	int i = 0;

	while(MRC != zeroVector){

		MRN.push_back(MRC[MRC.size()-i-1]);

		d = Conv::machineValueToRNS(MRN.back(), modules);
		m = Conv::getMultiplicativeInversion(modulesRev[modulesRev.size()-i-1], modules);
		reverse(m.begin(), m.end());
		reverse(d.begin(), d.end());

		MRC = Operations::vectorSubtract(MRC, d, modulesRev);
		MRC = Operations::vectorMultiply(MRC, m, modulesRev);

		for(int k=0; k<=i; k++){
			MRC[MRC.size()-k-1] = 0;
		}

		if(i<fractionalModulesNumber){
			if(MRN.back() < c[i])
				cFlag = LESS;
			if(MRN.back() > c[i])
				cFlag = GREATER;
			if(MRN.back() == c[i])
				cFlag = EQUAL;
		}

		if(i>=fractionalModulesNumber){
			ACC += PT[i] * MRN.back();
		}

		i++;


	};

	for(i; i<18; i++){
		MRN.push_back(0);
	}

	if(cFlag == EQUAL || cFlag == GREATER)
		ACC += 1;

	return MRN;

}

vector<long> Conv::truncatedMRNToRNS(vector<long> trunc, vector<long> PT, vector<long> modules, int fractionalModulesNumber){

	vector<long> rns;
	long value = 0;

	for(int i=fractionalModulesNumber; i<18; i++){
		value += PT[i] * trunc[i];
	}

	rns = Conv::machineValueToRNS(value, modules);

	return rns;

}

