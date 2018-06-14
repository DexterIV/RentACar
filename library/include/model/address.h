#ifndef ADDRESS_H_
#define ADDRESS_H_

#include <iostream>
#include <string>
#include "typedefs.h"
#include <sstream>

using namespace std;

class Address{

	private:
		string street;
		string number;
		
	public:

		Address();
		virtual ~Address();
		
		Address(string street, string number);
		string get_address();
		void set_address(string street, string number);
		friend istringstream & operator>>(istringstream & istr, Address & adr);
		friend ostream & operator<<(ostream & istr, Address & adr);
};

#endif
