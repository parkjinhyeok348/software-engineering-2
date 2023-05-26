#include <iostream>
#include <string>
#include <vector>
using namespace std;

ifstream readFile;
ofstream writeFile;
string user_id;
ApplierInfoCollection* applierInfoCollection;
EmployInfoCollection* employInfoCollection;
ApplyInfoCollection* applyInfoCollection;

class ApplierInfo
{
private:
	string companyName;
	string work;
	int applierNumber;
public:
	ApplierInfo(string companyName, string work, int applierNumber)
		: companyName(companyName), work(work), applierNumber(applierNumber) {}
	string getCompanyName() const;
	string getApplierInfo() const;
};

class ApplierInfoCollection
{
private:
	vector<ApplierInfo> applierInfoList;
public:
	void addApplierInfo(const ApplierInfo& applierInfo);
	string findApplierInfo(string companyName);
};


class EmployInfo {
private:
	string companyName;
	int businessNumber;
	string work;
	int employCount;
	string deadLine;

public:
	EmployInfo() {};
	EmployInfo(const string& companyName, int businessNumber, const string& work, int employCount, const string& deadLine)
		: companyName(companyName), businessNumber(businessNumber), work(work), employCount(employCount), deadLine(deadLine) {}

	string getEmployInfo() const;
	string getEmployInfoDetails(const string& companyName);
	string getEmployInfoDetails(int businessNumber);
	string getCompanyName() const;

	int getBusinessNumber() const;
};

//
class EmployInfoCollection {
private:
	vector<EmployInfo> employInfoList;

public:
	void addEmployInfo(const EmployInfo& employInfo);
	string findEmployInfo(const string& companyName);
	EmployInfo findEmployInfo2(const string& companyName);
	string findEmployInfo(int businessNumber);
	EmployInfo findEmployInfo2(int businessNumber);
};


class ApplyInfo {
private:
	string companyName;
	int businessNumber;
	string work;

public:
	ApplyInfo() {};
	~ApplyInfo() {};
	ApplyInfo(const std::string& name, int businessNumber, const std::string& work)
		: companyName(name), businessNumber(businessNumber), work(work) {}

	int getBusinessNumber() const;
};

//
class ApplyInfoCollection {
private:
	vector<ApplyInfo> applyInfoList;

public:
	void addApplyInfo(const ApplyInfo& ApplyInfo);
	void getApplyInfoList();

};