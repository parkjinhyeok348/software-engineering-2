#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PrintApplierNum
{
public:
	string printApplierNumber(string user_id);
	void populateApplierInfoCollection();
};

class SearchEmploy {
public:
	SearchEmploy() {};
	~SearchEmploy() {};
	string showEmployInfo(const string& companyName);
};

class ApplyEmploy {
public:
	string doApply(int businessNumber);
};