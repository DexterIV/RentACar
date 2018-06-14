#ifndef VEHICLEEXCEPTION_H_
#define VEHICLEEXCEPTION_H_

#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

const string VehicleBadValue = "\nVehicleException: Podano nieprawidlowa wartosc\n";
const string isOccupied = "\nVehicleException: Pojazd jez juz wypozyczony!\n";
const string VehicleIsNullptr = "\nVehicleException: Podano nullptr";
const string vehicleNotFound = "\nVehicleException: Nie znaleziono pojazdu!\n";
const string vehicleExists = "\nVehicleException: Pojazd jest juz w repozytorium!\n";

class VehicleException : public logic_error
{
	private: 
	
		string whatarg;
	
	public:
	
	VehicleException(string whatarg);
	~VehicleException();
};





#endif
