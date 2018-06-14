#include "rentsmanager.h"
#include "vehicleexception.h"
#include "clientexception.h"
#include "rentexception.h"
RentsManager::RentsManager()
{
//
}

void RentsManager::rentVehicle(ClientPtr client, VehiclePtr vehicle, local_date_time *rentalDateTime)
{
	if((vehicle->get_availability() == true) && (client->get_vehicleCount() + 1 < client->get_clientType()->get_maxVehicles()))
	{
		client->countVehicle(true);
		client->countUp();
		client->get_clientType()->calculate_discount();
		RentPtr rent(new Rent(client, vehicle, rentalDateTime));
		rent->set_rentDiscount();
		rentsRep.create(rent);
	}
	else throw RentException(RentTooMuch);
}

RentsManager::~RentsManager()
{

}

void RentsManager::rentVehicle(RentPtr rent)
{
	if((rent->get_vehicle()->get_availability() == true) && (rent->get_client()->get_vehicleCount() + 1 < rent->get_client()->get_clientType()->get_maxVehicles()))
	{
		rent->get_client()->countVehicle(true);
		rent->get_client()->countUp();
		rent->get_client()->get_clientType()->calculate_discount();
		rent->set_rentDiscount();
		rentsRep.create(rent);
	}
	else throw RentException(RentTooMuch);
}

void RentsManager::returnVehicle(VehiclePtr vehicle)
{
//	RentPtr rent(new Rent(find_rent(vehicle)));
	if(find_rent(vehicle) == nullptr)
		throw VehicleException(VehicleIsNullptr);
	find_rent(vehicle)->returnVehicle();
	rentsRep.makeArchive(find_rent(vehicle));
	float tmp_discount = find_rent(vehicle)->get_rentDiscount();
	find_rent(vehicle)->set_cost(tmp_discount);
	find_rent(vehicle)->get_client()->countVehicle(false);
}

vector<RentPtr> RentsManager::getAllClientRents(ClientPtr client)
{
	vector<RentPtr> tmp;
	for(auto i: rentsRep.get_archiveRents())
		tmp.push_back(i);

	return tmp;
}

float RentsManager::checkClientRentBalance(ClientPtr client)
{
	if(client == nullptr)
		throw ClientException(clientNotFound);

	float balance = 0;

	vector<RentPtr> tmp = getAllClientRents(client);
	for(auto i: tmp)
		balance += i->get_cost();

	
	return balance;
}
RentPtr RentsManager::find_rent(VehiclePtr vehicle)
{
	for(auto i: rentsRep.getAll())
	{
		if(i->get_vehicle() == vehicle)
			return i;
	}
	for(auto j: rentsRep.get_archiveRents())
	{
		if(j->get_vehicle() == vehicle)
			return j;
	}
	return nullptr;
}
