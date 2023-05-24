#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BoundaryClass.h"
#include "EntityClass.h"
#include "ControlClass.h"

using namespace std;

ifstream readFile;
ofstream writeFile;
string user_id;
ApplierInfoCollection* applierInfoCollection;
EmployInfoCollection* employInfoCollection;
ApplyInfoCollection* applyInfoCollection;

string PrintApplierNum::printApplierNumber(string user_id) {
	string applierNumberDetails = applierInfoCollection->findApplierInfo(user_id);
	return applierNumberDetails;
}
void PrintApplierNum::populateApplierInfoCollection() {
	for (const auto& applyInfo : applyInfoCollection->getApplyInfoList()) {
		ApplierInfo applierInfo(applyInfo.getCompanyName(), applyInfo.getWork(), "0");
		applierInfoCollection->addApplierInfo(applierInfo);
	}
}

string SearchEmploy::showEmployInfo(const string& companyName) {
	EmployInfo employInfo = employInfoCollection->findEmployInfo2(companyName);
	return employInfo.getEmployInfoDetails(companyName);
}

string ApplyEmploy::doApply(int businessNumber) {
	EmployInfo employInfo = employInfoCollection->findEmployInfo2(businessNumber);
	string details = employInfo.getEmployInfoDetails(businessNumber);
	string companyName = details.substr(0, details.find(" "));
	string number = details.substr(details.find(" ") + 1, details.find(" ") + 2);
	int bn = atoi(number.c_str());
	string work = details.substr(details.find(" ") + 2, details.find(" ") + 3);
	ApplyInfo applyInfo(companyName, bn, work);
	applyInfoCollection->addApplyInfo(applyInfo);
	string applyInfoDetails = companyName + " " + to_string(businessNumber) + " "
		+ work;
	return applyInfoDetails;
}