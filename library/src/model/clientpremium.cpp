#include "clientpremium.h"
#include "client.h"

ClientPremium::ClientPremium(Client* client): ClientType(client)
{
	maxVehicles = 25;
	calculate_discount();
}

ClientPremium::~ClientPremium()
{
	
}

void ClientPremium::calculate_discount()
{
	int tmp = client->get_rentCount();

	this->discount = 1.0*(float)tmp/100.0;

}
