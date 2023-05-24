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

void PrintApplierNumUI::startInterface() {}

//
void PrintApplierNumUI::clickApplierNumberPrintButton(string user_id) {
	PrintApplierNum printApplierNum;
	string applierNumberDetails;
	applierNumberDetails = printApplierNum.printApplierNumber(user_id);
	// Output format
	writeFile << "5.1." << endl;
	writeFile << "> " << applierNumberDetails << endl;
}

void SearchEmployUI::startInterface() {}

//
void SearchEmployUI::searchEmployInfo(const string& companyName) {
	SearchEmploy searchEmploy;
	string employInfoDetails = searchEmploy.showEmployInfo(companyName);
	// Output format
	writeFile << "4.1. 채용 정보 검색" << endl;
	writeFile << employInfoDetails << endl;
}

void ApplyEmployUI::startInterface() {}

//
void ApplyEmployUI::apply(int businessNumber) {
	ApplyEmploy applyEmploy;
	string applyInfoDetails;
	applyInfoDetails = applyEmploy.doApply(businessNumber);
	// Output format
	writeFile << "4.2. 채용 지원" << endl;
	writeFile << applyInfoDetails << endl;
}

