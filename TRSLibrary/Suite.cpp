
#include"stdafx.h"
#define TRSLibrary_EXPORT
#include "Suite.h"

using std::ostream;

Suite::Suite(char*TestName, char*Description, char* DirName_) :TRSInfo(TestName, Description)
{
	directoryName = DirName_;
}




Suite::~Suite()
{

}

bool Suite::addTest(TRSTest& currentTest)
{
	testList.push_back(currentTest);
	return true;
}

bool Suite::removeTest(char*testName)
{
	std::list<TRSTest>::iterator it= testList.begin();
	for (it; it != testList.end(); ++it)
	{
		if (!strncmp(testName, it->getName(), strlen(testName)))
		{
			testList.erase(it);
			return true;
		}
	}
	return false;
}

std::list<TRSTest>& Suite::getList()
{
	return testList;
}

ostream& operator<<(ostream& out, Suite instance)
{
	std::list<TRSTest> list = instance.getList();
	for each(auto val in list)
		out << val.getName()<<" ";
	return out;
}