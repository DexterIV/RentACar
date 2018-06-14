#ifndef CLIENT_H_
#define CLIENT_H_

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "rent.h"
#include "address.h"
#include "clienttype.h"
#include "typedefs.h"
#include "clientexception.h"

using namespace std;

class Client
{
	private:
		
		vector <RentPtr> rents;
		string firstName;
		string lastName;
		string personalID;
		AddressPtr registeredAddress = nullptr;
		AddressPtr address = nullptr;
		ClientType* clienttype;
		int rentCount = 0;			// ilosc wypozyczen ogolnie
		int vehicleCount = 0;		// ilosc aktualnych wypozyczen
		
	public:
	
		Client();
		virtual ~Client();
		
		void clientInfo();
		string clientFullInfo();
		void set_client_address(AddressPtr address);
		void set_client_registeredAddress(AddressPtr registeredAddress);
		void set_client_info(string firstName, string lastName, string personalID);
		Client(string firstName, string lastName, string personalID, char type);
		Client(string firstName, string lastName, string personalID);
		vector<RentPtr> get_rents();
		void set_rent(Rent rent);
		string get_personalID();
		void set_ClientType(char type);
		int get_rentCount();
		int get_vehicleCount();
		void countUp();
		void countVehicle(bool option);
		void update_discount();
		ClientType* get_clientType();
		bool operator==(const Client& client);
		friend ostream & operator<<(ostream & os, const Client & client);
		friend istringstream & operator>>(istringstream & istr, Client & client);
};

#endif
