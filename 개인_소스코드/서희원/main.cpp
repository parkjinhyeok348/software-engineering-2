//��� ������
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BoundaryClass.h"
#include "EntityClass.h"
#include "ControlClass.h"

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
