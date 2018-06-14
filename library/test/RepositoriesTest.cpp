#include <boost/test/unit_test.hpp>
#include <string>
#include <exception>
#include <iostream>
#include "rentsmanager.h"
#include "rentsrepository.h"
#include "vehiclerepository.h"
#include "vehicle.h"
#include "rent.h"
#include "clientmanager.h"
#include "rentexception.h"
#include "clientexception.h"
#include "vehicleexception.h"
#include <sstream>

BOOST_AUTO_TEST_SUITE(RepositoriesTest)

BOOST_AUTO_TEST_CASE(InitVectorVRep)
{
	VehicleRepository vrep;
	
	for (int i = 1; i<10; i++)
	BOOST_REQUIRE(vrep.find(i)!=nullptr);
	
}

BOOST_AUTO_TEST_CASE(VRepAddGetVehicle)
{
	VehiclePtr vehicle(new Vehicle("KGR 16FX", 200));
	VehicleRepository vrep;
	vrep.create(vehicle);
	Vehicle tmp = *(vrep.find(11));
	
	
	BOOST_REQUIRE(vehicle->get_id()==tmp.get_id());
}


BOOST_AUTO_TEST_CASE(RRepAddRent)
{
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 999));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime pt(date(2017, Oct, 19), hours(17)+minutes(5));
	local_date_time rentalDate(pt, utc);
	//
	RentPtr testrent(new Rent(client, vehicle, &rentalDate));
	
	RentsRepository rrep;
	
	rrep.create(testrent);

	BOOST_REQUIRE(rrep.find(testrent) == true);
}
/*
BOOST_AUTO_TEST_CASE(RRepGetClient)
{
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 999));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime pt(date(2017, Oct, 19), hours(17)+minutes(5));
	local_date_time rentalDate(pt, utc);
	//
	RentPtr testrent (new Rent(client, vehicle, &rentalDate));
	
	RentsRepository rrep;
	rrep.create(testrent);

	stringstream stmp;
	stmp<<client;
	string tmp = stmp.str();
	
	BOOST_REQUIRE_EQUAL(rrep.getClientForRentedVehicle(vehicle),tmp);
}
*/


BOOST_AUTO_TEST_SUITE_END()
