#ifndef MOTORVEHICLE_H_
#define MOTORVEHICLE_H_

#include <iostream>
#include "vehicle.h"

using namespace std;

class Motorvehicle:public Vehicle
{
	protected:
		
		int engineDisplacement = 0;
		
	public:
	
		Motorvehicle(string id, float baseRentPrice, int engineDisplacement);
		virtual ~Motorvehicle();
		virtual void modify_actualRentPrice();
		friend istringstream & operator>>(istringstream & istr, Motorvehicle & motorvehicle);
		int get_engineDisplacement();

};

#endif
