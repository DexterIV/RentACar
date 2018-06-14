#ifndef BICYCLE_H_
#define BICYCLE_H_

#include <iostream>
#include <string>
#include "vehicle.h"


class Bicycle
	: public Vehicle
{
	public:
	
		Bicycle(string id, int baseRentPrice);
		virtual ~Bicycle();
};

#endif
