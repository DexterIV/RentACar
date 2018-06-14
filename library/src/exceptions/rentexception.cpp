#include "rentexception.h"

RentException::RentException(string whatarg) : logic_error(whatarg)
{
}

RentException::~RentException()
{
}
