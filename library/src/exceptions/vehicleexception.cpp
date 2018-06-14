#include "vehicleexception.h"

VehicleException::VehicleException(string whatarg) : logic_error(whatarg)
{
}

VehicleException::~VehicleException()
{
}
