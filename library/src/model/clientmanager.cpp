#include "clientmanager.h"

ClientManager::ClientManager(){}

ClientManager::~ClientManager(){}

void ClientManager::createClient(string firstName, string lastName, string personalID, char type)
{
	ClientPtr client(new Client(firstName, lastName, personalID, type));
	if(clientRep.find(client) == true)
		throw ClientException(clientExists);

	clientRep.create(client);
}

void ClientManager::removeClient(string personalID)
{
	ClientPtr client(new Client("", "", personalID, 'S'));
	clientRep.remove(client);
}

ClientRepository ClientManager::get_clientRep()
{
	return clientRep;
}