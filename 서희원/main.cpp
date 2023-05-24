//��� ������
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

// ��� ������
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// Ŭ����&�Լ� ������
class ApplierInfo;
class ApplierInfoCollection;
class PrintApplierNumUI;
class PrintApplierNum;
class EmployInfo;
class EmployInfoCollection;
class ApplyInfo;
class ApplyInfoCollection;
class SearchEmployUI;
class SearchEmploy;
class ApplyEmployUI;
class ApplyEmploy;
void doTask();
void searchEmployment();
void applyEmployment();
void program_exit();

// ���� ������
ifstream readFile;
ofstream writeFile;
string user_id;
ApplierInfoCollection* applierInfoCollection;
EmployInfoCollection* employInfoCollection;
ApplyInfoCollection* applyInfoCollection;

//
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

//
class ApplierInfoCollection
{
private:
	vector<ApplierInfo> applierInfoList;
public:
	void addApplierInfo(const ApplierInfo& applierInfo);
	string findApplierInfo(string companyName);
};

//
class PrintApplierNumUI
{
public:
	void startInterface();
	void clickApplierNumberPrintButton(string user_id);
};

//
class PrintApplierNum
{
public:
	string printApplierNumber(string user_id);
	void populateApplierInfoCollection();
};

//
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

//
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

//
class SearchEmploy {
public:
	SearchEmploy() {};
	~SearchEmploy() {};
	string showEmployInfo(const string& companyName);
};

//
class SearchEmployUI {
public:
	void startInterface();
	void searchEmployInfo(const string& companyName);
};

//
class ApplyEmploy {
public:
	string doApply(int businessNumber);
};

//
class ApplyEmployUI {
public:
	void startInterface();
	void apply(int businessNumber);
};




//
string ApplierInfo::getCompanyName() const {
	return companyName;
}

//
string ApplierInfo::getApplierInfo() const {
	string applierInfo = work + " " + to_string(applierNumber);
	return applierInfo;
}

//
void ApplierInfoCollection::addApplierInfo(const ApplierInfo& applierInfo) {
	applierInfoList.push_back(applierInfo);
}

//
string ApplierInfoCollection::findApplierInfo(string companyName) {
	for (const auto& applierInfo : applierInfoList) {
		if (applierInfo.getCompanyName() == companyName) {
			return applierInfo.getApplierInfo();
		}
	}
	return "";
}

//
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

//
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
//
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

//
string SearchEmploy::showEmployInfo(const string& companyName) {
	EmployInfo employInfo = employInfoCollection->findEmployInfo2(companyName);
	return employInfo.getEmployInfoDetails(companyName);
}

//
void SearchEmployUI::startInterface() {}

//
void SearchEmployUI::searchEmployInfo(const string& companyName) {
	SearchEmploy searchEmploy;
	string employInfoDetails = searchEmploy.showEmployInfo(companyName);
	// Output format
	writeFile << "4.1. ä�� ���� �˻�" << endl;
	writeFile << employInfoDetails << endl;
}

//
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

//
void ApplyEmployUI::startInterface() {}

//
void ApplyEmployUI::apply(int businessNumber) {
	ApplyEmploy applyEmploy;
	string applyInfoDetails;
	applyInfoDetails = applyEmploy.doApply(businessNumber);
	// Output format
	writeFile << "4.2. ä�� ����" << endl;
	writeFile << applyInfoDetails << endl;
}

//ä�� ���� �˻� ����� �����ϴ� �Լ���
void searchEmployment() {
	string companyName;
	readFile >> companyName;
	SearchEmployUI searchEmployUI;
	searchEmployUI.startInterface();
	searchEmployUI.searchEmployInfo(companyName);
}

// ä�� ���� ����� �����ϴ� �Լ���
void applyEmployment() {
	int businessNumber;
	readFile >> businessNumber;
	ApplyEmployUI applyEmployUI;
	applyEmployUI.startInterface();
	applyEmployUI.apply(businessNumber);
}

//���� ���� ��踦 ����ϴ� �Լ���
void printApplyStatistic() {

}

//���� ���� ��� �� ����� ������
void program_exit() {
	writeFile << "6.1. ����" << endl;
	readFile.close();
	writeFile.close();
}



//ä�� �ý��� ������
void doTask() {
	// �޴� �Ľ��� ���� level ������ ���� ���� ������
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit) {
		// �Է����Ͽ��� �޴� ���� 2�� ����
		readFile >> menu_level_1 >> menu_level_2;

		// �޴� ���� �� �ش� ���� ����
		switch (menu_level_1) {
		case 4: {
			switch (menu_level_2) {
			case 1: // "4.1. ä�� ���� �˻�" �κ���
				searchEmployment();
				break;
			case 2: // "4.2. ä�� ����" �κ���
				applyEmployment();
				break;
			}
			break;
		}
		case 5: {
			switch (menu_level_2) {
			case 1: // "5.1. ���� ���� ��� " �κ���
				printApplyStatistic();
				break;
			}
			break;
		}
		case 6: {
			switch (menu_level_2) {
			case 1: // "6.1. ����" �κ���
				program_exit();
				is_program_exit = 1;
				break;
			}
			break;
		}
		}
	}
}

int main() {
	//���� ������� ���� �ʱ�ȭ
	readFile.open(INPUT_FILE_NAME);
	writeFile.open(OUTPUT_FILE_NAME);

	doTask();

	return 0;
}
