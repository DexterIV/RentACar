#include <iostream>
#include <string>
#include <map>
#include <exception>
#include "client.h"
#include "rent.h"
#include "vehicle.h"
#include "motorvehicle.h"
#include "car.h"
#include "bicycle.h"
#include "mope.h"
#include "rentsrepository.h"
#include "vehiclerepository.h"
#include "rentsmanager.h"
#include "typedefs.h"
#include "clientmanager.h"
#include <sstream>

using namespace std;

int main()
{
	//data
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	ptime pt(date(2017, Oct, 20), hours(13)+minutes(40));
	local_date_time rentDate(pt, utc);
	//
	
	AddressPtr registeredAddress(new Address("Zamkowa ", "52"));
	AddressPtr address(new Address("Zamkowa ", "51"));


	ClientPtr client2(new Client("Jan", "Kowalski", "1234", 'S')); //utworzenie parametrowo
	ClientPtr client1(new Client("Ola","Kowalska","91249",'P'));

	client2->set_client_address(address);
	client2->set_client_registeredAddress(registeredAddress);

	CarPtr pojazd = make_shared<Car>("EPA 12A54", 560.0, 3000, 'E');
	CarPtr pojazd1 = make_shared<Car>("EPA AAA54", 570.0, 1000, 'C');
	RentPtr testrent1 = make_shared<Rent>(client2, pojazd1, &rentDate);
	RentPtr testrent = make_shared<Rent>(client1, pojazd, &rentDate);

	RentsRepository rep;

	rep.create(testrent);
	rep.create(testrent1);


	cout << endl;
	rep.getClientForRentedVehicle(pojazd1);
	cout << endl;
	rep.rentReport();





	/*
	DO ZROBIENIA:
	- Dodac funktory
	- Przeciazyc operator <<
	*/

	return 0;
}
