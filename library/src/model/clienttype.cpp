#include "clienttype.h"

ClientType::ClientType(Client* client)
{
	this->client=client;
}

ClientType::~ClientType()
{
	
}

int ClientType::get_maxVehicles()
{
	return maxVehicles;
}
float ClientType::get_discount()
{
	calculate_discount();
	return discount;
}

void ClientType::calculate_discount()
{
	
}