#include <iostream>
#include <string>
#include <sstream>
#include "rent.h"
#include "client.h"
#include "vehicle.h"
#include <exception>
#include "rentexception.h"
#include <algorithm>

using namespace std;
using namespace boost::local_time;
using namespace boost::posix_time;

Rent::Rent(ClientPtr client, VehiclePtr vehicle, local_date_time *rentalDateTime)
{	
	
	if (vehicle == nullptr || client == nullptr)
	{
		throw RentException(isNullptr);
	}
	else 
	{
		this->client = client;
		this->vehicle = vehicle;
		this->rentalDateTime = rentalDateTime;
		this->returnDateTime = nullptr;
		//uuid
		boost::uuids::random_generator gen;
		this->uuid = gen();
		client->get_clientType()->calculate_discount();
		this->rentDiscount = client->get_clientType()->get_discount();
		cost = 0;
		client->set_rent(*this);
	}
	//
}

Rent::Rent(RentPtr rent)
{
	client = rent->client;
	vehicle = rent->vehicle;
	rentalDateTime = rent->rentalDateTime;
	returnDateTime = rent->returnDateTime;
	uuid = rent->uuid;
	cost = rent->cost;
}

Rent::~Rent()
{
}

void Rent::rentInfo()
{
	cout << *this;
	cout << "Klient: \n\n";
	client->clientInfo();
	cout << "\n";
}

ostream & operator<<(ostream & os, const Rent & rent)
{
	os << "UUID: " << to_string(rent.uuid) 
	   << "\nData poczatkowa: " << rent.getstring_rentDate()
	   << "\nData koncowa: " << rent.getstring_returnDate()
	   << "\nLiczba dni wypozyczenia: " << rent.rentDuration() 
	   << "\nKoszt wypozyczenia: " << rent.cost
	   << "\n";
	return os;
}

int Rent::rentDuration() const
{
	if(returnDateTime == nullptr)
		return 0;
	
	ptime start = rentalDateTime->local_time();
	ptime now = second_clock::local_time();
	time_period period(start, now);
	stringstream stream;
	stream << period.length();
	double tmp;
	stream >> tmp;
	tmp = tmp/24;
	int tmp_int = tmp;
	double check = tmp / tmp_int;
	if(check == 1.0)
		return tmp_int; //zwraca ilosc dni od daty wypozyczenia do teraz
	else
		return tmp_int + 1;
}

void Rent::returnVehicle()
{
	ptime now = second_clock::local_time();
	ptime end;
	ptime start = rentalDateTime->local_time();
	time_period period (start, now);
	end = start;
	stringstream stream;
	long len;
	stream << period.length();
	stream >> len;
	end = end + hours(len);
	time_zone_ptr utc(new posix_time_zone("UTC+1:00:00"));
	returnDateTime = new local_date_time(end, utc);
	client->get_clientType()->calculate_discount();
	set_cost(client->get_clientType()->get_discount());
}

string Rent::get_uuid()
{
	stringstream ss;
	ss << uuid;
	string tmp = ss.str();

	return tmp;
}

float Rent::get_cost()
{
	return cost;
}

void Rent::set_cost()
{
	this->cost = rentDuration() * vehicle->get_actualRentPrice();
}

void Rent::set_cost(float discount)
{
	this->cost = rentDuration() * vehicle->get_actualRentPrice() * (1-discount);
}

local_date_time* Rent::get_returnDate()
{
	return returnDateTime;
}

ClientPtr Rent::get_client()
{
	return client;
}

VehiclePtr Rent::get_vehicle()
{
	return vehicle;
}

bool Rent::operator==(const Rent& rent) const
{

	if(this->uuid == rent.uuid)
		return true;

	return false;
}

void Rent::set_rentDiscount()
{
	rentDiscount = client->get_clientType()->get_discount();
}

float Rent::get_rentDiscount()
{
	return rentDiscount;
}

string Rent::getstring_rentDate() const
{
	stringstream ss;
	ss << rentalDateTime->local_time();

	return ss.str();
}

string Rent::getstring_returnDate() const
{
	stringstream ss;
	if(returnDateTime == nullptr)
		return "-----";
	else
	{
		ss << returnDateTime->local_time();
		return ss.str();
	}
}

istringstream & operator>>(istringstream & istr, Rent & rent)
{
	istr >> *(rent.client);
	istr >> *(rent.vehicle);
	istr >> *(rent.rentalDateTime);
	return istr;
}