#include "vehiclemanager.h"
#include "vehicleexception.h"

VehicleManager::VehicleManager(){}

VehicleManager::~VehicleManager(){}

void VehicleManager::createVehicle(string id, float baseRentPrice)
{
	VehiclePtr vehicle(new Vehicle(id, baseRentPrice));
	if(vehicleRep.find(vehicle) == true)
		throw VehicleException(vehicleExists);

	vehicleRep.create(vehicle);
}

void VehicleManager::createCar(string id, float baseRentPrice, int engineDisplacement, char segment)
{
	VehiclePtr vehicle(new Car(id, baseRentPrice, engineDisplacement, segment));
	if(vehicleRep.find(vehicle) == true)
		throw VehicleException(vehicleExists);

	vehicleRep.create(vehicle);
}

void VehicleManager::createBicycle(string id, float baseRentPrice)
{
	VehiclePtr vehicle(new Bicycle(id, baseRentPrice));
	if(vehicleRep.find(vehicle) == true)
		throw VehicleException(vehicleExists);

	vehicleRep.create(vehicle);
}

void VehicleManager::createMope(string id, int baseRentPrice, int engineDisplacement)
{
	VehiclePtr vehicle(new Mope(id, baseRentPrice, engineDisplacement));
	if(vehicleRep.find(vehicle) == true)
		throw VehicleException(vehicleExists);

	vehicleRep.create(vehicle);
}

void VehicleManager::removeVehicle(string id)
{
	VehiclePtr vehicle(new Vehicle(id, 333));
	if(vehicleRep.find(vehicle) == true)
		vehicleRep.remove(vehicle);
}

VehicleRepository VehicleManager::get_vehicleRep()
{
	return vehicleRep;
}