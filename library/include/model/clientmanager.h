#ifndef CLIENTMANAGER_H_
#define CLIENTMANAGER_H_

#include "client.h"
#include "clientrepository.h"

class ClientManager
{
	private:
		ClientRepository clientRep;
	public:
		ClientManager();
		~ClientManager();
		void createClient(string firstName, string lastName, string personalID, char type);
		void removeClient(string personalID);

		//Metody do testow
		ClientRepository get_clientRep();
};

#endif
