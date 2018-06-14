#ifndef RENTEXCEPTION_H_
#define RENTEXCEPTION_H_

#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

const string RentBadValue = "\nRentException: Podano nieprawidlowa wartosc\n";
const string isNullptr = "\nRentException: Podano nullptr\n";
const string operatorNullptr = "\nRentException: Porownanie nullptr i nullptr\n";
const string rentNotFound = "\nRentException: Nie znaleziono wypozyczenia\n";
const string RentTooMuch = "\n RentException: Za duzo wypozyczen / pojazd nie dostepny\n";

class RentException : public logic_error
{
	private: 
	
		string whatarg;
	
	public:
	
	RentException(string whatarg);
	~RentException();
};





#endif
