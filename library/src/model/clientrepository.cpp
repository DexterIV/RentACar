#include "clientrepository.h"

using namespace std;

ClientRepository::ClientRepository()
{
}

ClientRepository::~ClientRepository()
{
}

void ClientRepository::create(ClientPtr client)
{
	clients.push_back(client);
}

void ClientRepository::remove(ClientPtr client)
{
	int tmp_i=0;
	for (auto i : clients)
	{
		if(*i == *client)
		{
			clients.erase(clients.begin()+tmp_i);
		}
		tmp_i++;
	}
}

void ClientRepository::remove(int index)
{
	int tmp_i = 0;
	for (auto i : clients)
	{
		if(tmp_i == index)
		{
			clients.erase(clients.begin()+tmp_i);
		}
		tmp_i++;
	}
}

void ClientRepository::changeClientType(ClientPtr client, char type)
{
	client->set_ClientType(type);
}

vector <ClientPtr> ClientRepository::getAll()
{
	return clients;
}

bool ClientRepository::find(ClientPtr client)
{
	for (auto i : clients)
	{
		if (*i == *client)
			return true;
	}
	return false;
}


