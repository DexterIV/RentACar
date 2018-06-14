#ifndef VEHICLEREPOSITORY_H_
#define VEHICLEREPOSITORY_H_

#include <vector>
#include <string>
#include "vehicle.h"
#include "bicycle.h"
#include "mope.h"
#include "car.h"
#include "typedefs.h"
#include "repository.h"

using namespace std;

vector <VehiclePtr> init_VehicleRepository();


class VehicleRepository : public Repository<VehiclePtr>
{
	private:
	
		vector <VehiclePtr> vehicles;
	
	public:
	
		VehicleRepository();
		virtual ~VehicleRepository();
		
		void vehicleReport();


		void create(VehiclePtr vehicle);
		void remove(VehiclePtr vehicle);
		bool find (VehiclePtr vehicle);
		VehiclePtr find(int index);
		vector <VehiclePtr> getAll();
};

class VehicleFunctor
{
	public:

		VehicleFunctor(){};
		~VehicleFunctor(){};
		string operator()(VehiclePtr vehicle){return vehicle->get_id();}

};

#endif
