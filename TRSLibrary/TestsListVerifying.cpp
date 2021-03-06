#include "stdafx.h"
#include "TestsListVerifying.h"

int TestPosition(std::vector<TRSTest*> coll, char* testName)
{
	for (int i = 0; i < coll.size(); ++i)
	{
		if (!strncmp(coll[i]->getName(),testName,strlen(testName)))
		{
			return i;
		}
	}
}

bool ExistTest(std::vector<TRSTest*> coll, char* testName)
{
	for (int i = 0; i < coll.size(); ++i)
	{
		if (!strncmp(coll[i]->getName(), testName, strlen(testName)))
		{
			return true;
		}
	}
	return false;
}

bool VerifyWaitForList(std::vector<TRSTest*>coll, std::vector<char*> waitColl)
{
	bool check = true;
	for (int i = 0; i < waitColl.size(); ++i)
	{
		for (int j = 0; j < coll.size(); ++j)
		{
			if (!strncmp(waitColl[i], coll[j]->getName(), strlen(waitColl[i])))
			{
				check = false;
			}
		}
		if (check)
		{
			return false;
		}
	}
	return true;
}

bool VerifyTestsList(std::vector<TRSTest*>coll, int size, std::vector<char*>nameColl, int firstelem )
{
	if (size)
	{
		if (coll[firstelem]->getWaitFor())
		{
			for (int i = 0; i < nameColl.size(); ++i)
			{
				if (coll[firstelem]->getName() == nameColl[i])
				{
					return false;
				}
			}
			nameColl.push_back(coll[firstelem]->getName());
			if (ExistTest(coll, coll[firstelem]->getWaitFor()))
			{
				if (!strncmp(coll[firstelem]->getName(), coll[TestPosition(coll, coll[firstelem]->getWaitFor())]->getName(), strlen(coll[firstelem]->getName())))
				{
					return false;
				}
				else
				{
					return VerifyTestsList(coll, coll.size() - 1, nameColl, TestPosition(coll, coll[firstelem]->getWaitFor()));
				}
			}
			
		}
		else
		{
			return true;
		}
	}
	else
	{
		for (int i = 0; i < nameColl.size(); ++i)
		{
			if (coll[firstelem]->getName() == nameColl[i])
			{
				return false;
			}
		}
		return true;
	}
}