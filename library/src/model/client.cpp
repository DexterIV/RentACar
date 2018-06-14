#include "client.h"
#include "clientstandard.h"
#include "clientbusiness.h"
#include "clientpremium.h"
#include "clientexception.h"
#include <string>
#include <sstream>

using namespace std;

//konstruktor

Client::Client()
{
	this->firstName="Brak";
	this->lastName="Brak";
	this->personalID="Brak";
}

Client::Client(string firstName, string lastName, string personalID, char type)
{	

	switch (type)
	{
		case 'S':
			this->clienttype=new ClientStandard(this);
			break;
			
		case 'P':
			this->clienttype=new ClientPremium(this);
			break;
			
		case 'B':
			this->clienttype=new ClientBusiness(this);
			break;
			
		default: 
			this->clienttype=new ClientType(this);
			break;
	}
	
	this->firstName=firstName;
	this->lastName=lastName;
	this->personalID=personalID;
	this->rentCount = 0;
	this->vehicleCount = 0;
	
}

Client::Client(string firstName, string lastName, string personalID)
{	
	this->firstName=firstName;
	this->lastName=lastName;
	this->personalID=personalID;
	this->rentCount = 0;
	this->vehicleCount = 0;
	this->clienttype=new ClientType(this);
}

Client::~Client()
{
}

void Client::clientInfo()
{
	cout << *this;
}

ostream & operator<<(ostream & os, const Client & client)
{
	os << "Imie: " << client.firstName
	   << "\nNazwisko: " << client.lastName
	   << "\nPESEL: " << client.personalID;
	if(client.address != nullptr)
		os << "\nAdres: " << client.address->get_address();
	if(client.registeredAddress != nullptr)
		os << "\nAdres zameldowania: " << client.registeredAddress->get_address();
	os << "\n";

	return os;
}
string Client::clientFullInfo()
{
	string tmp;
	tmp = "Imie: " + firstName + "  Nazwisko: " + lastName + "  PESEL: " + personalID;
	
	if(address != nullptr)
		tmp += " Adres: " + address->get_address();
	
	if(registeredAddress != nullptr)
		tmp += " Adres zameldowania: " + registeredAddress->get_address();
	
	if(rents.size() > 0)
	{
		tmp += "\nWypozyczenia: ";
		//for (auto i: rents)
		//tmp += "\n" + i->Rent::rentInfo2();
	}
	
	return tmp;
}
void Client::set_client_address(AddressPtr address)
{
	this->address = address;
}
void Client::set_client_registeredAddress(AddressPtr registeredAddress)
{
	this->registeredAddress = registeredAddress;
}
void Client::set_client_info(string firstName, string lastName, string personalID)
{

		this->firstName=firstName;
		this->lastName=lastName;
		
		if(personalID!="Brak")  //zakladam ze personalID powinien byc niezmienny
			this->personalID=personalID;
}

vector<RentPtr> Client::get_rents()
{
	return rents;
}

void Client::set_rent(Rent rent)
{
	RentPtr tmp = make_shared<Rent>(rent);
	rents.push_back(tmp);
}

string Client::get_personalID()
{
	return personalID;
}

void Client::set_ClientType(char choice)
{
	if(choice == 'S' || choice == 'B' || choice == 'P')
	{
		clienttype = NULL;
		switch (choice)
		{
			case 'S':
				this->clienttype = new ClientStandard(this);
				break;
			case 'B':
				this->clienttype = new ClientBusiness(this);
				break;
			case 'P':
				this->clienttype = new ClientPremium(this);
				break;
		} 
	}	else throw 6;
}

int Client::get_rentCount()
{
	return rentCount;
}

int Client::get_vehicleCount()
{
	return vehicleCount;
}

void Client::countUp()
{
	this->rentCount+=1;
}

void Client::countVehicle(bool option)
{
	if (option==true)
		vehicleCount++;
	
	if (option==false && vehicleCount!=0)
		vehicleCount--;
	
}

ClientType* Client::get_clientType()
{
	return clienttype;
}

bool Client::operator==(const Client& client)
{
		if(this->personalID == client.personalID)
			return true;

		return false;
}
void Client::update_discount()
{
	this->clienttype->calculate_discount();
}

istringstream & operator>>(istringstream & istr, Client & client)
{
	client.firstName.clear();
	client.lastName.clear();
	client.personalID.clear();
	istr >> client.firstName >> client.lastName >> client.personalID;
	//istr >> *(client.address);
	//istr >> *(client.registeredAddress);
	return istr;
}