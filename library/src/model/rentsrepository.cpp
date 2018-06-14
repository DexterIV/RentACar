#include "rentsrepository.h"
#include <exception>
#include "rentexception.h"
using namespace std;

RentsRepository::RentsRepository()
{
	
}

RentsRepository::~RentsRepository()
{
}
		
void RentsRepository::create(RentPtr rent)
{
	if (rent == nullptr)
	{
		throw RentException(isNullptr);
	}
	else
	{
		currentRents.push_back(rent);

	}
}

void RentsRepository::remove(RentPtr rent)
{
	std::vector<RentPtr>::iterator j = std::find(currentRents.begin(), currentRents.end(), rent);
	currentRents.erase(j);
}

void RentsRepository::getClientForRentedVehicle(VehiclePtr vehicle)
{
	VehiclePtr tmp_v = make_shared<Vehicle>();
	ClientPtr tmp_c = make_shared<Client>();

	for(auto i : currentRents)
	{
		tmp_v = i->Rent::get_vehicle();
		if (tmp_v->get_id() == vehicle->get_id())
		{
			tmp_c = i->Rent::get_client();
			tmp_c->clientInfo();
			break;
		}	
	}
	cout << "Brak klienta przypisanego do podanego pojazdu \n";
}

void RentsRepository::rentReport()
{
	
	for(auto i : currentRents)
		i->rentInfo();
	
}

void RentsRepository::makeArchive(RentPtr rent)
{
	remove(rent);
	archiveRents.push_back(rent);
}

vector<RentPtr> RentsRepository::getAll()
{
	return currentRents;
}

vector<RentPtr> RentsRepository::get_archiveRents()
{
	return archiveRents;
}

bool RentsRepository::find(RentPtr rent)
{
	for (auto i : currentRents)
		{
			if (*i == *rent)
				return true;
		}
	return false;
}