#include <boost/test/unit_test.hpp>
#include "clientstandard.h"
#include "clienttype.h"
#include "client.h"
#include "typedefs.h"
BOOST_AUTO_TEST_SUITE(ClientTypeTest)

BOOST_AUTO_TEST_CASE(TypeTest)
{

}

BOOST_AUTO_TEST_CASE(ClientOperatorOverloaded)
{
	Client client1("Jan", "Kowalski", "12345");
	Client client2("Marcin", "Nowak", "12345");
	Client client3("Jan", "Kowalski", "54321");

	BOOST_REQUIRE_EQUAL((client1 == client2), true);
	BOOST_REQUIRE_EQUAL((client2 == client3), false);
}

BOOST_AUTO_TEST_SUITE_END()
