#ifndef REPORTMANAGER_H_
#define REPORTMANAGER_H_

#ifdef TRSLibrary_EXPORT
#define ReportManager_API __declspec(dllexport)
#else
#define ReportManager_API  __declspec(dllimport) 
#endif

#include "TRSReport.h"
#include <list>

class ReportManager_API ReportManager
{
public:
	ReportManager();
	~ReportManager();
	void Begin();
	void End();
	void addReporter(TRSReport* pReporter);
	void beforeExecution(TRSInfo pInfo);
	void afterExecution(TRSInfo pInfo,TRSResult pResult);
	void errorOutput(TRSResult& res,char* mess );
	void errorMessage(char* mes);
private:
	std::list<TRSReport*> reportList;
	CRITICAL_SECTION critical_section_;
};

#endif