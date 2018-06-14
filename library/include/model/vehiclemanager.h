#ifndef VEHICLEMANAGER_H_
#define VEHICLEMANAGER_H_

#include "vehicle.h"
#include "vehiclerepository.h"

class VehicleManager
{
	private:
		VehicleRepository vehicleRep;
	public:
		VehicleManager();
		~VehicleManager();
		void createVehicle(string id, float baseRentPrice);
		void createBicycle(string id, float baseRentPrice);
		void createCar(string id, float baseRentPrice, int engineDisplacement, char segment);
		void createMope(string id, int baseRentPrice, int engineDisplacement);
		void removeVehicle(string id);
		//Metody potrzebne do testow
		VehicleRepository get_vehicleRep();
};


#endif
