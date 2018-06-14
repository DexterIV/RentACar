#include "vehicle.h"
#include "rentexception.h"
#include "vehicleexception.h"
#include <sstream>

using namespace std;

Vehicle::Vehicle(string id, float baseRentPrice)
{
	if (baseRentPrice<0)
		throw VehicleException(VehicleBadValue);
	this->id=id;
	this->baseRentPrice=baseRentPrice;
	this->actualRentPrice=baseRentPrice;
}

Vehicle::Vehicle(){}

Vehicle::~Vehicle()
{
}

void Vehicle::vehicleInfo()
{
	cout << *this;
}

ostream & operator<<(ostream & os, const Vehicle& vehicle)
{
	os << "Numer rejestracyjny: " << vehicle.id
	   << "\nCena: " << vehicle.baseRentPrice;
	return os;
}

float Vehicle::get_baseRentPrice()
{ 
	return baseRentPrice; 
}

float Vehicle::get_actualRentPrice()
{ 
	return actualRentPrice; 
}

string Vehicle::get_id()
{
	return id;
}

void Vehicle::set_availability(bool option)
{
	this->available = option;
}

bool Vehicle::get_availability()
{
	return available;
}

bool Vehicle::operator==(const Vehicle& vehicle)
{
	if(this->id == vehicle.id)
		return true;

	return false;
}

istringstream & operator>>(istringstream & istr, Vehicle & vehicle)
{
	vehicle.id.clear();
	istr >> vehicle.id >> vehicle.baseRentPrice;
	return istr;
}