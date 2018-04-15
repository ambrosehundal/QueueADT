#pragma once
#ifndef DOLLAR_H
#define DOLLAR_H

#include "Currency.h"

#include <iostream>


using namespace std;

class Dollar : public Currency {
private:
	bool DollarCreated = false;
public:
	//constructor
	Dollar(int initWhole, int initFractional) {
	    whole = initWhole;
		fraction = initFractional;
	}
	//destructor
	~Dollar() {
		whole = 0;
		fraction = 0;
	}


	friend ostream& operator<< (ostream&out, Dollar d);
};


#endif