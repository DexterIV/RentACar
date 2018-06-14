#include "clientexception.h"
	
	
ClientException::ClientException(string whatarg) : logic_error (whatarg)
{
}

ClientException::~ClientException()
{
	
}
