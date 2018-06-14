#include "clientstandard.h"


ClientStandard::ClientStandard(Client* client): ClientType(client)
{
	maxVehicles = 5;
	discount = 0;
}

ClientStandard::~ClientStandard()
{
	
}

void ClientStandard::calculate_discount()
{
	this->discount = 0.05;
}
