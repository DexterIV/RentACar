#ifndef CAR_H_
#define CAR_H_

#include <map>
#include "motorvehicle.h"

class Car:public Motorvehicle
{
	private:
	
		char segment;
	
	public:
	
		Car(string id, float baseRentPrice, int engineDisplacement, char segment);
		virtual ~Car();
		char get_segment();
		virtual void modify_actualRentPrice();
		friend istringstream & operator>>(istringstream & istr, Car & car);
};

#endif
