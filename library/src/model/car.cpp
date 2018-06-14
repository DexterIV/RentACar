#include <iostream>
#include <memory>
#include "car.h"
#include "segmentMap.h"
#include <sstream>
#include <fstream>
#include <cstring>

using namespace std;

Car::Car(string id, float baseRentPrice, int engineDisplacement, char segment) : Motorvehicle(id, baseRentPrice, engineDisplacement)
{
	this->segment = segment;
	modify_actualRentPrice();
}



Car::~Car()
{
}

char Car::get_segment()
{
	return segment;
}

void Car::modify_actualRentPrice()
{

	unique_ptr<float> seg (new float(secondValue(segment)));
	unique_ptr<float> tmp (new float(actualRentPrice * (*seg)));
	actualRentPrice = *tmp;
	
}

istringstream & operator>>(istringstream & istr, Car & car)
{
	Motorvehicle& tmp1 = car;
	istr >> tmp1;

	string tmp = "";
	istr >> tmp;
	char* str = new char [1];
  	strncpy(str,tmp.c_str(),1);
  	
  	
	car.segment = tmp[0];

	delete [] str;
	return istr;
}