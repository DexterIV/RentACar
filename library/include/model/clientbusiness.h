#ifndef CLIENTBUSINESS_H_
#define CLIENTBUSINESS_H_

#include <iostream>
#include "clienttype.h"
#include "typedefs.h"

class ClientBusiness: public ClientType
{

	public:
	ClientBusiness(Client* client);
	virtual ~ClientBusiness();
	
	void calculate_discount();

};

#endif
