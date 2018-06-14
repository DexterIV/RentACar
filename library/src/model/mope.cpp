#include "mope.h"
#include <sstream>

using namespace std;

Mope::Mope(string id, int baseRentPrice, int engineDisplacement) : Motorvehicle(id, baseRentPrice, engineDisplacement)
{
	//
}

Mope::~Mope()
{
}

istringstream & operator>>(istringstream & istr, Mope & mope)
{
	Motorvehicle& tmp1 = mope;
	istr >> tmp1;

	return istr;
}