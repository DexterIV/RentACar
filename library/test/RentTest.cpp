#include <boost/test/unit_test.hpp>
#include "rent.h"
#include "vehicle.h"
#include "client.h"
#include <string>
#include <algorithm>
#include <exception>
#include "rentexception.h"
#include "rentsmanager.h"
#include "car.h"
#include <sstream>

BOOST_AUTO_TEST_SUITE(RentTest)

BOOST_AUTO_TEST_CASE(RentTestRentDuration) { // TC3
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 999));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime pt(date(2017, Oct, 19), hours(17)+minutes(5));
	local_date_time rentalDate(pt, utc);
	//
	RentPtr testrent(new Rent(client, vehicle, &rentalDate));
	
	//sprawdzanie czy liczba dni przed zwroceniem pojazdu rowna jest 0
	BOOST_REQUIRE_EQUAL(testrent->rentDuration(), 0);
}

BOOST_AUTO_TEST_CASE(RentTestRentExist) { 
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 999));

	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime pt(date(2017, Oct, 19), hours(17)+minutes(5));
	local_date_time rentalDate(pt, utc);
	//
	
	RentPtr testrent(new Rent(client, vehicle, &rentalDate));

	//sprawdzenie czy client ma to wypozyczenie
	vector<RentPtr> tmp = client->get_rents();
	//vector<RentPtr>::iterator i = find(tmp.begin(), tmp.end(), testrent);
	
	BOOST_REQUIRE_EQUAL(tmp.size(), 1);
}

BOOST_AUTO_TEST_CASE(RentTestDurationExist) {
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546", 'S'));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 999));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime pt(date(2017, Oct, 19), hours(17)+minutes(5));
	local_date_time rentalDate(pt, utc);
	//
	RentPtr testrent(new Rent(client, vehicle, &rentalDate));
	
	testrent->returnVehicle();
	
	//sprawdzenie czy po zwroceniu, dlugosc wypozyczenia jest rozna od 0
	BOOST_REQUIRE(testrent->rentDuration() != 0);
}

BOOST_AUTO_TEST_CASE(RentTestAfterReturn) // <----------
{
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 999));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime pt(date(2017, Oct, 19), hours(17)+minutes(5));
	local_date_time rentalDate(pt, utc);
	//
	RentPtr testrent(new Rent(client, vehicle, &rentalDate));
	
	testrent->returnVehicle();
	
	//sprawdzanie czy client ma to wypozyczenie po zwroceniu pojazdu

	vector<RentPtr> tmp = client->get_rents();
	bool found = false;

	for (auto i: tmp)
		if(*testrent == *i)
			found = true;
	
	BOOST_REQUIRE(found == true);
}

BOOST_AUTO_TEST_CASE(TC2)
{
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 999));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime pt(date(2017, Oct, 19), hours(17)+minutes(5));
	local_date_time rentalDate(pt, utc);
	//
	RentPtr rent1(new Rent(client, vehicle, &rentalDate));
	RentPtr rent2(new Rent(client, vehicle, &rentalDate));
	RentPtr rent3(new Rent(client, vehicle, &rentalDate));
	RentPtr rent4(new Rent(client, vehicle, &rentalDate));
	RentPtr rent5(new Rent(client, vehicle, &rentalDate));
	RentPtr rent6(new Rent(client, vehicle, &rentalDate));
	RentPtr rent7(new Rent(client, vehicle, &rentalDate));
	RentPtr rent8(new Rent(client, vehicle, &rentalDate));
	RentPtr rent9(new Rent(client, vehicle, &rentalDate));
	RentPtr rent10(new Rent(client, vehicle, &rentalDate));
	
	vector<RentPtr> tmp = client->get_rents();
	for(int i=0; i<10; i++)
	{
		for(int k=0; k<10; k++)
		{
			if(k != i)
			{
				BOOST_REQUIRE(tmp[i]->get_uuid() != tmp[k]->get_uuid());
			}
		}
	}
}

BOOST_AUTO_TEST_CASE(TC4)
{
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 999));
	//wypozyczenie poniezej doby
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime start;
	ptime now = second_clock::local_time();
	start = now - hours(12);
	local_date_time rentalDate(start, utc);
	//
	RentPtr rent(new Rent(client, vehicle, &rentalDate));
	
	rent->returnVehicle();
	
	BOOST_REQUIRE(rent->rentDuration() == 1);
	
	//wypozyczenie kilka dni
	
	start = now - days(7) - hours(1);
	local_date_time rentalDate2(start, utc);
	RentPtr rent2(new Rent(client, vehicle, &rentalDate2));
	
	rent2->returnVehicle();
	
	BOOST_REQUIRE(rent2->rentDuration() == 7);
}

BOOST_AUTO_TEST_CASE(TC6) // <---------
{
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546", 'S'));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 200));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime start;
	ptime now = second_clock::local_time();
	start = now - days(6) - hours(2);
	local_date_time rentalDate(start, utc);
	//
	
	RentPtr rent(new Rent(client, vehicle, &rentalDate));
	
	// Przed zwroceniem pojazdu koszt powinien wynosi 0

	BOOST_REQUIRE(rent->get_cost() == 0);
	
	//Zwrocenie pojazdu
	rent->returnVehicle();
	BOOST_REQUIRE(rent->get_cost() != 0);
}

BOOST_AUTO_TEST_CASE(TC5)
{
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 200));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime start(date(2017, Oct, 20), hours(13)+minutes(40));
	local_date_time rentalDate(start, utc);
	//
	
	RentPtr rent(new Rent(client, vehicle, &rentalDate));
	
	rent->returnVehicle();
	ptime end = rent->get_returnDate()->local_time();
	
	BOOST_REQUIRE(start < end);
}

BOOST_AUTO_TEST_CASE(TC1)
{
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR 77FX", 200));
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime pt(date(2017, Oct, 19), hours(17)+minutes(5));
	local_date_time rentalDate(pt, utc);
	
	//dwa nullpointery
	try
	{
		Rent rent1(nullptr, nullptr, &rentalDate);
	}
	catch (logic_error err)
	{
		BOOST_REQUIRE_EQUAL(err.what(), isNullptr);
	}
	//client nullptr
	try
	{
		Rent rent2(nullptr, vehicle, &rentalDate);
	}
	catch (logic_error err)
	{
		BOOST_REQUIRE_EQUAL(err.what(), isNullptr);
	}
	//vehicle nullptr
	try
	{
		Rent rent3(client, nullptr, &rentalDate);
	}
	catch (logic_error err)
	{
		BOOST_REQUIRE_EQUAL(err.what(), isNullptr);
	}
	// brak nullptr
	try
	{
		Rent rent1(client, vehicle, &rentalDate);
	}
	catch (logic_error err)
	{
		BOOST_REQUIRE(err.what() != isNullptr);
	}
}

BOOST_AUTO_TEST_CASE(RentOperator)
{
	ClientPtr client(new Client("Xiao", "Zhung", "67042587546"));
	VehiclePtr vehicle(new Vehicle("KGR77FX", 200));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime start(date(2017, Oct, 20), hours(13)+minutes(40));
	local_date_time rentalDate(start, utc);

	//
	
	RentPtr rent(new Rent(client, vehicle, &rentalDate));
	stringstream sstr;
	sstr << rentalDate;
	string tmps;
	tmps = sstr.str();
	string tmp = "Xiao Zhung KGR77FX 200 ";
	tmp += tmps;
	std::istringstream ic(tmp);

	ic >> *rent; //OPERATOR

	stringstream datestr;
	datestr << rentalDate.local_time();
	tmp.clear();
	tmp = datestr.str();

	BOOST_REQUIRE(*(rent->get_vehicle()) == *vehicle);
	BOOST_REQUIRE(*(rent->get_client())== *client);
	BOOST_REQUIRE_EQUAL(rent->getstring_rentDate(), tmp);

}

BOOST_AUTO_TEST_SUITE_END()
