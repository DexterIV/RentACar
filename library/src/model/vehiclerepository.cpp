#include "vehiclerepository.h"
#include <exception>
#include "vehicleexception.h"

using namespace std;

vector <VehiclePtr> init_VehicleRepository()
{
	vector <VehiclePtr> tmp_vr;
	
	BicyclePtr bicycle1(new Bicycle("EPA BIC1", 100.0));
	BicyclePtr bicycle2(new Bicycle("EPA BIC2", 110.0));
	MopePtr mope1(new Mope("EPA MOP1", 220.0, 1000));
	MopePtr mope2(new Mope("EPA MOP2", 240.0, 1500));
	MopePtr mope3(new Mope("EPA MOP3", 260.0, 1700));
	MopePtr mope4(new Mope("EPA MOP4", 280.0, 2500));
	CarPtr car1(new Car("EPA CAR1", 600.0, 1000, 'A'));
	CarPtr car2(new Car("EPA CAR2", 700.0, 1500, 'B'));
	CarPtr car3(new Car("EPA CAR3", 800.0, 2000, 'D'));
	CarPtr car4(new Car("EPA CAR4", 900.0, 2500, 'E'));
	
	tmp_vr.push_back(bicycle1);
	tmp_vr.push_back(bicycle2);
	tmp_vr.push_back(mope1);
	tmp_vr.push_back(mope2);
	tmp_vr.push_back(mope3);
	tmp_vr.push_back(mope4);
	tmp_vr.push_back(car1);
	tmp_vr.push_back(car2);
	tmp_vr.push_back(car3);
	tmp_vr.push_back(car4);

	return tmp_vr;
}
	

VehicleRepository::VehicleRepository()
{
	this->vehicles = init_VehicleRepository();
}

VehicleRepository::~VehicleRepository()
{
}

void VehicleRepository::vehicleReport()
{
	for (auto i : vehicles)
	{
		i->vehicleInfo();
		cout << endl;
	}
}

VehiclePtr VehicleRepository::find(int index)
{
	index--;
	return vehicles[index];
}

void VehicleRepository::create(VehiclePtr vehicle)
{
	if(vehicle == nullptr)
	{
		throw VehicleException(VehicleIsNullptr);
	}
	else
	{
		vehicles.push_back(vehicle);
	}

}

void VehicleRepository::remove(VehiclePtr vehicle)
{
	int tmp_i = 0;
	for (auto i : vehicles)
	{
		if(*i == *vehicle)
		{
			vehicles.erase(vehicles.begin()+tmp_i);
		}
		tmp_i++;
	}
}

bool VehicleRepository::find(VehiclePtr vehicle)
{
	VehicleFunctor Vfunctor;

		for (auto i : vehicles)
		{
			if (i->get_id() == Vfunctor(vehicle))
				return true;
		}
		
	return false;
}

vector <VehiclePtr> VehicleRepository::getAll()
{
	return this->vehicles;
}