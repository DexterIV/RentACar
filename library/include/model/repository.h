#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include <string>
#include <vector>

using namespace std;


template<class OBJ>
class Repository
{
	public:
	virtual void	create(OBJ obj) = 0;
	virtual void	remove(OBJ obj) = 0;
	virtual vector<OBJ>	getAll() = 0;
	virtual bool	find(OBJ obj) = 0;
};








#endif
