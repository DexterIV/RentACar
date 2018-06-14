#ifndef RENT_H_
#define RENT_H_

#include "vehicle.h"
#include "client.h"
#include <string>
#include <boost/uuid/uuid.hpp>
#include <boost/uuid/uuid_generators.hpp>
#include <boost/uuid/uuid_io.hpp>
#include "boost/date_time/local_time/local_time.hpp"
#include "boost/date_time/posix_time/posix_time.hpp"
#include "boost/date_time/gregorian/gregorian.hpp"
#include "typedefs.h"


using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;
using namespace boost::gregorian;

class Rent
{
	private:
	
		boost::uuids::uuid uuid;
		local_date_time *rentalDateTime;
		local_date_time *returnDateTime;
		float rentDiscount = 0;
		float cost; 
		ClientPtr client = nullptr;
		VehiclePtr vehicle = nullptr;
		string string_uuid;

		friend class Client;
		friend class vehicle;
	
	public:
	
		Rent(ClientPtr client, VehiclePtr vehicle, local_date_time *rentalDateTime);
		Rent(RentPtr rent);
		virtual ~Rent();
		
		void rentInfo();
		int rentDuration() const;
		void returnVehicle();
		string get_uuid();
		float get_cost();
		boost::uuids::uuid get_boost_uuid() const { return uuid; }
		void set_cost();
		void set_cost(float discount);
		ClientPtr get_client();
		VehiclePtr get_vehicle();
		local_date_time *get_returnDate();
		bool operator==(const Rent& rent) const;
		float get_rentDiscount();
		void set_rentDiscount();
		string getstring_rentDate() const;
		string getstring_returnDate() const;
		friend ostream & operator<<(ostream & os, const Rent & rent);		
		friend istringstream & operator>>(istringstream & istr, Rent & rent);
	
};




#endif
