#ifndef CLIENTEXCEPTION_H_
#define CLIENTEXCEPTION_H_

#include <exception>
#include <stdexcept>
#include <string>

using namespace std;

const string ClientBadValue = "\nClientException: Podano nieprawidlowa wartosc";
const string tooMuchVehicles = "\nClientException: Przekroczono maksymalna ilosc wypozyczen\n";
const string clientNotFound = "\nClientException: Nie znaleziono klienta\n";
const string clientExists = "\nClientException: Klient jest juz w bazie\n";
class ClientException : public logic_error
{
	private:
	
	string whatarg;
	
	public:
	
	ClientException(string whatarg);
	~ClientException();
	
};

#endif
