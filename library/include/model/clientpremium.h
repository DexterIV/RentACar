#ifndef CLIENTPREMIUM_H_
#define CLIENTPREMIUM_H_

#include <iostream>
#include "clienttype.h"
#include "typedefs.h"

class ClientPremium: public ClientType
{
	private:
	
	
	
	public:
	
	ClientPremium(Client* client);
	virtual ~ClientPremium();
	
	void calculate_discount();

};

#endif
