#include "address.h"
#include <sstream>

using namespace std;

Address::Address()
{
}

Address::Address(string street, string number)
{
	this->street=street;
	this->number=number;
}

Address::~Address()
{
}

string Address::get_address()
{
	string tmp;
	string street = this->street;
	string number = this->number;
	tmp = street + " " + number;
	return tmp;
}


void Address::set_address(string street, string number)
{
	this->street = street;
	this->number = number;
}

istringstream & operator>>(istringstream & istr, Address & adr)
{
	adr.number.clear();
	adr.street.clear();
	istr >> adr.street >> adr.number;

	return istr;
}
ostream & operator<<(ostream & os, Address & adr)
{
	os << adr.street << " " << adr.number;

	return os;
}