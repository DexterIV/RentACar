#include <string>
#include <memory>
#include <sstream>
#include "motorvehicle.h"
#include "vehicleexception.h"


Motorvehicle::Motorvehicle(string id, float baseRentPrice, int engineDisplacement) : Vehicle(id, baseRentPrice)
{
	this->engineDisplacement = engineDisplacement;
	modify_actualRentPrice();
}

void Motorvehicle::modify_actualRentPrice()
{
	
	
	// Jesli pojemnosc <1000 to 1.0
	if(engineDisplacement < 1000 && engineDisplacement > 0)
	{
		unique_ptr<float> tmp3 (new float(get_baseRentPrice()));
		actualRentPrice=*tmp3;
	}
	
	// Jesli pojemnosc <1000, 2000> to 1.0-1.5   wzor -> y=0.0005*x + 0.5
	else if((engineDisplacement >= 1000) & (engineDisplacement <= 2000))
	{
		
		unique_ptr<float> tmp2 (new float (get_baseRentPrice() * (0.0005*engineDisplacement + 0.5)));
		actualRentPrice=*tmp2;
	}
	
	// Jesli pojemnosc >2000 to 1.5
	else if(engineDisplacement > 2000)
	{
		unique_ptr<float> tmp1 (new float (get_baseRentPrice() * 1.5));
		actualRentPrice=*tmp1;
	}
	else throw VehicleException(VehicleBadValue);
	
	
}


Motorvehicle::~Motorvehicle()
{
}

istringstream & operator>>(istringstream & istr, Motorvehicle & motorvehicle)
{
	Vehicle& tmp1 = motorvehicle;

	istr >> tmp1;
	istr >> motorvehicle.engineDisplacement;

	return istr;
}

int Motorvehicle::get_engineDisplacement()
{
	return engineDisplacement;
}