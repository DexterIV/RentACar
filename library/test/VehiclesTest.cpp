#include <boost/test/unit_test.hpp>
#include <string>
#include "rent.h"
#include "vehicle.h"
#include "client.h"
#include "motorvehicle.h"
#include "car.h"
#include "bicycle.h"
#include "mope.h"
#include "segmentMap.h"
#include "vehicleexception.h"
#include <exception>

BOOST_AUTO_TEST_SUITE(VehiclesTest)

BOOST_AUTO_TEST_CASE(Motorvehicle_creation)
{
	Motorvehicle moto("EPA 213", 200, 500);
	BOOST_REQUIRE(moto.get_id() == "EPA 213");
	BOOST_REQUIRE(moto.get_baseRentPrice() == 200);
	BOOST_REQUIRE(moto.get_actualRentPrice() == 200);
}

BOOST_AUTO_TEST_CASE(Motorvehicle_actualRentPrice)
{
	Motorvehicle moto1("KGR 16FX", 200, 500);
	Motorvehicle moto2("KGR 16FX", 200, 1000);
	Motorvehicle moto3("KGR 16FX", 200, 1300);
	Motorvehicle moto4("KGR 16FX", 200, 2000);
	Motorvehicle moto5("KGR 16FX", 200, 2500);
	
	BOOST_REQUIRE(moto1.get_actualRentPrice() == 200);
	BOOST_REQUIRE(moto2.get_actualRentPrice() == 200);
	BOOST_REQUIRE(moto3.get_actualRentPrice() == 230);
	BOOST_REQUIRE(moto4.get_actualRentPrice() == 300);
	BOOST_REQUIRE(moto5.get_actualRentPrice() == 300);
}

BOOST_AUTO_TEST_CASE(Car_creation)
{
	Car car("KGR 16FX", 200, 2500, 'E');
	BOOST_REQUIRE(car.get_id() == "KGR 16FX");
	BOOST_REQUIRE(car.get_baseRentPrice() == 200);
	BOOST_REQUIRE(car.get_actualRentPrice() == 450);
	BOOST_REQUIRE(car.get_segment() == 'E');
}
BOOST_AUTO_TEST_CASE(Car_actualRentPrice)
{
	Car car1("KGR 16FX", 200, 500, 'A');
	Car car2("KGR 16FX", 200, 1000, 'B');
	Car car3("KGR 16FX", 200, 1300, 'C');
	Car car4("KGR 16FX", 200, 2000, 'D');
	Car car5("KGR 16FX", 200, 2500, 'E');
	
	BOOST_REQUIRE(car1.get_actualRentPrice() == 200);
	BOOST_REQUIRE(car2.get_actualRentPrice() == 220);
	BOOST_REQUIRE(car3.get_actualRentPrice() == 276);
	BOOST_REQUIRE(car4.get_actualRentPrice() == 390);
	BOOST_REQUIRE(car5.get_actualRentPrice() == 450);
}

BOOST_AUTO_TEST_CASE(Bicycle_creation)
{
	Bicycle bicycle("KGR 16FX", 150);
	BOOST_REQUIRE(bicycle.get_id() == "KGR 16FX");
	BOOST_REQUIRE(bicycle.get_baseRentPrice() == 150);
}

BOOST_AUTO_TEST_CASE(Mope_creation)
{
	Mope mope("KGR 16FX", 200, 2500);
	
	BOOST_REQUIRE(mope.get_id() == "KGR 16FX");
	BOOST_REQUIRE(mope.get_baseRentPrice() == 200);
	BOOST_REQUIRE(mope.get_actualRentPrice() == 300);
}

BOOST_AUTO_TEST_CASE(Vehicle_badValue)
{
	try
	{
		Mope mope("KGR 16FX", -200, 2500);
	}
	catch (logic_error err)
	{
		BOOST_REQUIRE_EQUAL(err.what(), VehicleBadValue);
	}
	try
	{
		Car car1("KGR 16FX", 200, -500, 'A');
	}
	catch (logic_error err)
	{
		BOOST_REQUIRE_EQUAL(err.what(), VehicleBadValue);
	}
}

BOOST_AUTO_TEST_CASE(VehicleOperatorOverloaded)
{
	Vehicle vehicle1("KGR 77FX", 200);
	Vehicle vehicle2("KGR 77FX", 200);

	BOOST_REQUIRE_EQUAL((vehicle1 == vehicle2), true);
}


BOOST_AUTO_TEST_CASE(RentOperatorOverloaded)
{
	ClientPtr clientX(new Client("Xiao", "Zhung", "67042587546"));
	CarPtr vehicleX(new Car("KGR 77FX", 200, 2500, 'E'));
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime now = second_clock::local_time();
	ptime start = now - hours(13);
	local_date_time rentalDateX(start, utc);
	//
	Rent rent1(clientX, vehicleX, &rentalDateX);
	Rent rent2(clientX, vehicleX, &rentalDateX);

	BOOST_REQUIRE_EQUAL((rent1 == rent2), false);
}

BOOST_AUTO_TEST_CASE(Vehicleoperator)
{
	Vehicle vehtest;
	string tmp = "EPAAPE 3525";
	std::istringstream ik(tmp);
	ik>>vehtest;

	BOOST_REQUIRE(vehtest.get_id() == "EPAAPE");
	BOOST_REQUIRE(vehtest.get_baseRentPrice() == 3525);

	Car cartest("asd",1000,1000,'A');
	tmp = "EPAAPE 3525 3000 E";
	std::istringstream ic(tmp);
	ic>>cartest;

	BOOST_REQUIRE(cartest.get_id() == "EPAAPE");
	BOOST_REQUIRE(cartest.get_baseRentPrice() == 3525);
	BOOST_REQUIRE_EQUAL(cartest.get_segment() , 'E');
	BOOST_REQUIRE_EQUAL(cartest.get_engineDisplacement() , 3000);
}
BOOST_AUTO_TEST_SUITE_END()
