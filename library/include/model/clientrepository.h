#ifndef CLIENTREPOSITORY_H_
#define CLIENTREPOSITORY_H_

#include "client.h"
#include "clienttype.h"
#include "typedefs.h"
#include "repository.h"

#include <string>
#include <vector>

using namespace std;

class ClientRepository : public Repository<ClientPtr>
{
	private:
	
	vector <ClientPtr> clients;
	
	public:
	
		ClientRepository();
		virtual ~ClientRepository();
		
		void create(ClientPtr client);
		void remove(ClientPtr client);
		vector <ClientPtr> getAll();
		bool find(ClientPtr client);

		void remove(int index);
		void changeClientType(ClientPtr client, char type);
	
};

#endif
