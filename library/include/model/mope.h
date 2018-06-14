#ifndef MOPE_H_
#define MOPE_H_

#include <iostream>
#include <string>
#include "motorvehicle.h"

class Mope : public Motorvehicle
{
	public:
	Mope(string id, int baseRentPrice, int engineDisplacement);
	virtual ~Mope();
	friend istringstream & operator>>(istringstream & istr, Mope & mope);
};

#endif
