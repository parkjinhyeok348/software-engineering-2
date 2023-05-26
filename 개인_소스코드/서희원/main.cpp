//헤더 선언함
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "BoundaryClass.h"
#include "EntityClass.h"
#include "ControlClass.h"

using namespace std;

// 상수 선언함
#define MAX_STRING 32
#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 클래스&함수 선언함
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

// 변수 선언함
ifstream readFile;
ofstream writeFile;
string user_id;
ApplierInfoCollection* applierInfoCollection;
EmployInfoCollection* employInfoCollection;
ApplyInfoCollection* applyInfoCollection;


//채용 정보 검색 기능을 지원하는 함수임
void searchEmployment() {
	string companyName;
	readFile >> companyName;
	SearchEmployUI searchEmployUI;
	searchEmployUI.startInterface();
	searchEmployUI.searchEmployInfo(companyName);
}

// 채용 지원 기능을 수행하는 함수임
void applyEmployment() {
	int businessNumber;
	readFile >> businessNumber;
	ApplyEmployUI applyEmployUI;
	applyEmployUI.startInterface();
	applyEmployUI.apply(businessNumber);
}

//지원 정보 통계를 출력하는 함수임
void printApplyStatistic() {

}

//종료 문구 출력 및 입출력 끝내기
void program_exit() {
	writeFile << "6.1. 종료" << endl;
	readFile.close();
	writeFile.close();
}



//채용 시스템 수행함
void doTask() {
	// 메뉴 파싱을 위한 level 구분을 위한 변수 선언함
	int menu_level_1 = 0, menu_level_2 = 0;
	int is_program_exit = 0;

	while (!is_program_exit) {
		// 입력파일에서 메뉴 숫자 2개 읽음
		readFile >> menu_level_1 >> menu_level_2;

		// 메뉴 구분 및 해당 연산 수행
		switch (menu_level_1) {
		case 4: {
			switch (menu_level_2) {
			case 1: // "4.1. 채용 정보 검색" 부분임
				searchEmployment();
				break;
			case 2: // "4.2. 채용 지원" 부분임
				applyEmployment();
				break;
			}
			break;
		}
		case 5: {
			switch (menu_level_2) {
			case 1: // "5.1. 지원 정보 통계 " 부분임
				printApplyStatistic();
				break;
			}
			break;
		}
		case 6: {
			switch (menu_level_2) {
			case 1: // "6.1. 종료" 부분임
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
	//파일 입출력을 위한 초기화
	readFile.open(INPUT_FILE_NAME);
	writeFile.open(OUTPUT_FILE_NAME);

	doTask();

	return 0;
}
