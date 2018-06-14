#include "clientbusiness.h"
#include "client.h"

ClientBusiness::ClientBusiness(Client* client): ClientType(client)
{
	maxVehicles=125;
}

ClientBusiness::~ClientBusiness()
{
	
}

void ClientBusiness::calculate_discount()
{
		int tmp = client->get_rentCount();
		if(tmp <= 50)
			discount = (float)tmp/100.;
		else
			discount = 0.5;
}
