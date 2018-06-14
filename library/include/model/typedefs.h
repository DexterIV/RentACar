#include <iostream>
#include <memory>
#include <algorithm>

using namespace std;

//PREDECLARATIONS OF CLASSES
class Client;
class Vehicle;
class Address;
class Rent;
class Car;
class Mope;
class Bicycle;
class ClientRepository;
class RentsRepository;
class Rent;

//TYPEDEFS
typedef shared_ptr<Client> ClientPtr;
typedef shared_ptr<Vehicle> VehiclePtr;
typedef shared_ptr<Address> AddressPtr;
typedef shared_ptr<Car> CarPtr;
typedef shared_ptr<Bicycle> BicyclePtr;
typedef shared_ptr<Mope> MopePtr;
typedef shared_ptr<ClientRepository> ClientRepositoryPtr;
typedef shared_ptr<RentsRepository> RentsRepositoryPtr;
typedef shared_ptr<Rent> RentPtr;


//FUNKTORY

