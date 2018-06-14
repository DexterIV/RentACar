#ifndef VEHICLE_H_
#define VEHICLE_H_

#include <iostream>
#include <string>
#include "typedefs.h"

using namespace std;

class Vehicle
{
	private:
	
		string id;
		float baseRentPrice=0;
		bool available = true;
	
	protected:
		
		float actualRentPrice=0;
		
	public:
		
		virtual void vehicleInfo();
		Vehicle(string id, float baseRentPrice);
		Vehicle();
		virtual ~Vehicle();
		float get_baseRentPrice();
		float get_actualRentPrice();
		string get_id();
		void set_availability(bool option);
		bool get_availability();
		bool operator==(const Vehicle& vehicle);
		friend ostream & operator<<(ostream & os, const Vehicle& vehicle);
		friend istringstream & operator>>(istringstream & istr, Vehicle & vehicle);
		
};

#endif
