#ifndef RENTSMANAGER_H_
#define RENTSMANAGER_H_

#include <string>
#include "rentsrepository.h"
#include "clientrepository.h"
#include "typedefs.h"
#include "client.h"
#include "vehicle.h"
#include <vector>
class RentsManager
{
	private:

		ClientRepository clientRepository;
		RentsRepository rentsRep;
		
	public:
	
		
		RentsManager();
		virtual ~RentsManager();
		
		void rentVehicle(RentPtr rent);
		void rentVehicle(ClientPtr client, VehiclePtr vehicle, local_date_time *rentalDateTime);
		void returnVehicle(VehiclePtr vehicle);
		vector<RentPtr> getAllClientRents(ClientPtr client);
		float checkClientRentBalance(ClientPtr client);
		RentPtr find_rent(VehiclePtr vehicle);
};
#endif