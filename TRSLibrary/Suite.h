#ifndef SUITE_H_
#define SUITE_H_
#include "TRSInfo.h"
#include "TRSTest.h"
#include <list>
#include <istream>

class Suite:public TRSInfo
{
	std::list<TRSTest> testList;
public:
	Suite(char*TestName,char*Description,char*DirName);
	~Suite();
	bool addTest(TRSTest&);
	bool removeTest(char*name);
	std::list<TRSTest>& getList();

	friend std::ostream& operator<<(std::ostream &, Suite);
};
#endif