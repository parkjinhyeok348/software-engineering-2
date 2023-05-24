#include <iostream>
#include <string>
#include <vector>
using namespace std;

class PrintApplierNumUI
{
public:
	void startInterface();
	void clickApplierNumberPrintButton(string user_id);
};

class SearchEmployUI {
public:
	void startInterface();
	void searchEmployInfo(const string& companyName);
};

class ApplyEmployUI {
public:
	void startInterface();
	void apply(int businessNumber);
};
