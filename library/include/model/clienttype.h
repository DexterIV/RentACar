#ifndef CLIENTTYPE_H_
#define CLIENTTYPE_H_

#include <iostream>
#include "typedefs.h"

class Client;

class ClientType
{
	protected:
	
	int maxVehicles = 1;
	float discount = 0;
	Client* client = nullptr;
	
	public:
	
	ClientType(Client* client);
	virtual ~ClientType();

	virtual void calculate_discount();
	
	int get_maxVehicles();
	float get_discount();
};

#endif
