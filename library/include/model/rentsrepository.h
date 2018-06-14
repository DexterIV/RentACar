#ifndef RENTSREPOSITORY_H_
#define RENTSREPOSITORY_H_

#include "rent.h"
#include "vehicle.h"
#include "client.h"
#include "typedefs.h"
#include "repository.h"
#include <string>
#include <vector>

using namespace std;

class RentsRepository : public Repository<RentPtr>
{
	private:
	
	vector <RentPtr> currentRents;
	vector <RentPtr> archiveRents;
	
	public:
	
		RentsRepository();
		virtual ~RentsRepository();
		
		void create(RentPtr rent);
		void remove(RentPtr rent);
		vector<RentPtr> getAll();
		bool find(RentPtr rent);

		void getClientForRentedVehicle(VehiclePtr vehicle);
		void rentReport();
		void makeArchive(RentPtr rent);
		
		vector<RentPtr> get_archiveRents();

};

#endif
