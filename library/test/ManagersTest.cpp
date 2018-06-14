#include <boost/test/unit_test.hpp>
#include "clientmanager.h"
#include "vehiclemanager.h"
#include "rentsmanager.h"
#include <iostream>
#include <cmath>

BOOST_AUTO_TEST_SUITE(ManagersTest)

BOOST_AUTO_TEST_CASE(VehicleManagerTest)
{
	VehicleManager* vehicleMan = new VehicleManager();
	VehiclePtr vehicle(new Vehicle("1234", 333));
	
	vehicleMan->createVehicle("1234", 333);
	BOOST_REQUIRE(vehicleMan->get_vehicleRep().find(vehicle) == true);
	vehicleMan->removeVehicle("1234");
	BOOST_REQUIRE(vehicleMan->get_vehicleRep().find(vehicle) == false);
	delete vehicleMan;
}

BOOST_AUTO_TEST_CASE(CarManagerTest)
{
	VehicleManager* vehicleMan = new VehicleManager();
	CarPtr vehicle(new Car("1234", 333, 123, 'E'));

	vehicleMan->createCar("1234", 333, 123, 'E');
	BOOST_REQUIRE(vehicleMan->get_vehicleRep().find(vehicle) == true);
	vehicleMan->removeVehicle("1234");
	BOOST_REQUIRE(vehicleMan->get_vehicleRep().find(vehicle) == false);
	delete vehicleMan;
}

BOOST_AUTO_TEST_CASE(MopeManagerTest)
{
	VehicleManager* vehicleMan = new VehicleManager();
	MopePtr vehicle(new Mope("1234", 333, 123));

	vehicleMan->createMope("1234", 333, 123);
	BOOST_REQUIRE(vehicleMan->get_vehicleRep().find(vehicle) == true);
	vehicleMan->removeVehicle("1234");
	BOOST_REQUIRE(vehicleMan->get_vehicleRep().find(vehicle) == false);

	delete vehicleMan;
}

BOOST_AUTO_TEST_CASE(BicycleManagerTest)
{
	VehicleManager* vehicleMan = new VehicleManager();
	BicyclePtr vehicle(new Bicycle("1234", 333));

	vehicleMan->createVehicle("1234", 333);
	BOOST_REQUIRE(vehicleMan->get_vehicleRep().find(vehicle) == true);
	vehicleMan->removeVehicle("1234");
	BOOST_REQUIRE(vehicleMan->get_vehicleRep().find(vehicle) == false);
	delete vehicleMan;
}

BOOST_AUTO_TEST_CASE(ClientManagerTest)
{
	ClientManager* clientMan = new ClientManager();
	ClientPtr client(new Client("Jan", "Kowalski", "1234", 'S'));

	clientMan->createClient("Jan", "Kowalski", "1234", 'S');
	BOOST_REQUIRE(clientMan->get_clientRep().find(client) == true);
	clientMan->removeClient("1234");
	BOOST_REQUIRE(clientMan->get_clientRep().find(client) == false);
	delete clientMan;
}

BOOST_AUTO_TEST_CASE(RentsManagerBalanceTest)
{
	RentsManager rentman;
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546", 'S'));
	CarPtr vehicle1(new Car("KGR 77FX", 200, 2500, 'E'));
	CarPtr vehicle2(new Car("KGR 77FX", 200, 2500, 'E'));
	CarPtr vehicle3(new Car("KGR 77FX", 200, 2500, 'E'));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime now = second_clock::local_time();
	ptime start = now - hours(13);
	local_date_time rentalDate(start, utc);
	//

	rentman.rentVehicle(client, vehicle1, &rentalDate);
	rentman.rentVehicle(client, vehicle2, &rentalDate);
	rentman.rentVehicle(client, vehicle3, &rentalDate);

	rentman.returnVehicle(vehicle1);
	rentman.returnVehicle(vehicle2);
	rentman.returnVehicle(vehicle3);

	float epsilon = 0.001;

	BOOST_REQUIRE_EQUAL(fabs(rentman.checkClientRentBalance(client) - 1282.5) < epsilon, true);
}

BOOST_AUTO_TEST_CASE(ClientStandardDiscount)
{
	RentsManager rentman;
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546", 'S'));
	VehiclePtr vehicle(new Car("KGR 77FX", 200, 2500, 'E'));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime now = second_clock::local_time();
	ptime start = now - hours(13);
	local_date_time rentalDate(start, utc);
	//

	rentman.rentVehicle(client, vehicle, &rentalDate);
	rentman.returnVehicle(vehicle);
	RentPtr testrent1(new Rent(rentman.find_rent(vehicle)));

	float cost = 427.5;

	BOOST_REQUIRE(testrent1->get_cost() == cost);
}

BOOST_AUTO_TEST_CASE(ClientPremiumDiscount)
{
	RentsManager rentman;
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546", 'P'));
	VehiclePtr vehicle1(new Car("KGR 78FX", 200, 2500, 'E')); // koszt 450 za 1 dzien
	VehiclePtr vehicle2(new Car("KGR 77FX", 200, 2500, 'E'));
	VehiclePtr vehicleX(new Vehicle("KGR 77FX", 200));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime now = second_clock::local_time();
	ptime start = now - hours(13);
	local_date_time rentalDate(start, utc);
	//
	float tmp = 0;

	BOOST_REQUIRE(client->get_clientType()->get_discount() == tmp);

	rentman.rentVehicle(client, vehicle1, &rentalDate);
	rentman.rentVehicle(client, vehicle2, &rentalDate);

	tmp = 0.02;

	float epsilon = 0.001;

	BOOST_REQUIRE_EQUAL((fabs(client->get_clientType()->get_discount() - tmp) < epsilon), true);

	rentman.returnVehicle(vehicle1);
	rentman.returnVehicle(vehicle2);

	BOOST_REQUIRE_EQUAL(fabs(rentman.checkClientRentBalance(client) - 886.5) < epsilon, true); //pierwsze auto ma znizke 0.01 a drugie juz 0.02 dlatego nie 882 tylko 886.5

}

BOOST_AUTO_TEST_CASE(ClientBusinessDiscount)
{
	RentsManager rentman;
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546", 'B'));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime now = second_clock::local_time();
	ptime start = now - hours(13);
	local_date_time rentalDate(start, utc);
	//

	vector<VehiclePtr> vehicles;

	VehiclePtr vehicle1(new Car("KGR 77FX", 200, 2500, 'E')); // koszt 450 za 1 dzien

	for (int i = 0; i<60; i++)
	{
		vehicles.push_back(make_shared<Car> ("KGR 77FX", 200, 2500, 'E'));
		rentman.rentVehicle(client, vehicles[i], &rentalDate);
	}

	float tmp_float;
	tmp_float = 0.5;
	float epsilon = 0.001;

	BOOST_REQUIRE_EQUAL((fabs(client->get_clientType()->get_discount() - tmp_float) < epsilon), true);
	BOOST_REQUIRE(client->get_rentCount() == 60);
	BOOST_REQUIRE(client->get_vehicleCount() == 60);

}
BOOST_AUTO_TEST_SUITE_END()