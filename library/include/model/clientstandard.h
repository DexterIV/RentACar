#ifndef CLIENTSTANDARD_H_
#define CLIENTSTANDARD_H_

#include <iostream>
#include "clienttype.h"
#include "typedefs.h"

class ClientStandard: public ClientType
{
	private:
	
	
	public:
	
	ClientStandard(Client* client);
	virtual ~ClientStandard();
	
	void calculate_discount();

};

#endif
