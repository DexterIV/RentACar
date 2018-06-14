#include "segmentMap.h"

using namespace std;

float secondValue(char segment)
{
	map<char, float> segmentMap = 
{
	{'A', 1.0},
	{'B', 1.1},
	{'C', 1.2},
	{'D', 1.3},
	{'E', 1.5}
};

	return segmentMap.find(segment)->second;

}
