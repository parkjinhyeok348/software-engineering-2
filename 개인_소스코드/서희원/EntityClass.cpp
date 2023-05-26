#include <iostream>
#include <string>
#include <vector>
#include "EntityClass.h"
using namespace std;

ifstream readFile;
ofstream writeFile;
string user_id;
ApplierInfoCollection* applierInfoCollection;
EmployInfoCollection* employInfoCollection;
ApplyInfoCollection* applyInfoCollection;

string EmployInfo::getEmployInfo() const {
	string employInfo = companyName + " " + to_string(businessNumber) + " "
		+ work + " " + to_string(employCount) + " " + deadLine;
	return employInfo;
}

//
string EmployInfo::getEmployInfoDetails(const string& companyName) {
	string employInfoDetails = employInfoCollection->findEmployInfo(companyName);
	return employInfoDetails;
}

//
string EmployInfo::getEmployInfoDetails(int businessNumber) {
	string employInfoDetails = employInfoCollection->findEmployInfo(businessNumber);
	return employInfoDetails;
}

//
string EmployInfo::getCompanyName() const {
	return companyName;
}

//
int EmployInfo::getBusinessNumber() const {
	return businessNumber;
}

//
void EmployInfoCollection::addEmployInfo(const EmployInfo& employInfo) {
	employInfoList.push_back(employInfo);
}

//
string EmployInfoCollection::findEmployInfo(const string& companyName) {
	for (const auto& employInfo : employInfoList) {
		if (employInfo.getCompanyName() == companyName) {
			return employInfo.getEmployInfo();
		}
	}
	return "";
}

//
EmployInfo EmployInfoCollection::findEmployInfo2(const string& companyName) {
	for (const auto& employInfo : employInfoList) {
		if (employInfo.getCompanyName() == companyName) {
			return employInfo;
		}
	}
}

//
string EmployInfoCollection::findEmployInfo(int businessNumber) {
	for (const auto& employInfo : employInfoList) {
		if (employInfo.getBusinessNumber() == businessNumber) {
			return employInfo.getEmployInfo();
		}
	}
}

//
EmployInfo EmployInfoCollection::findEmployInfo2(int businessNumber) {
	for (const auto& employInfo : employInfoList) {
		if (employInfo.getBusinessNumber() == businessNumber) {
			return employInfo;
		}
	}
}

//
int ApplyInfo::getBusinessNumber() const {
	return businessNumber;
}

//
void ApplyInfoCollection::addApplyInfo(const ApplyInfo& ApplyInfo) {
	applyInfoList.push_back(ApplyInfo);
}

