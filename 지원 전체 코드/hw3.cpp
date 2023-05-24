#define _CRT_SECURE_NO_WARNINGS
// 헤더 선언
#include "stdcol.h"
#include"EmployInfo.h"
#include"EmployInfoCollection.h"
#include"RegisterEmployInfo.h"
#include"RegisterEmployInfoUI.h"
#include"AskEmployInfoUI.h"

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void run();
void program_exit();
vector<string> split(string str,char dlim);

//클래스 선언
RegisterEmployInfoUI registerEmployInfoUI;
AskEmployInfoUI askEmployInfoUI;


int main()
{
     run();

     return 0;
}






void run()
{
    ofstream out_fp(OUTPUT_FILE_NAME);
    ifstream in_fp(INPUT_FILE_NAME);

    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        string input;
        getline(in_fp, input);

        vector<string> inputString = split(input, ' ');

        menu_level_1 = stoi(inputString[0]);
        menu_level_2 = stoi(inputString[1]);

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1){
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // 1.1. 회원가입
            {

                break;
            }
            case 2: // 1.2 회원 탈퇴
            {
                break;
            }
            }
            break;
        }
        case 2:
        {
            switch (menu_level_2) {
            case 1://2.1 로그인
            {
                break;
            }
            case 2: //2.2 로그아웃
            {
                break;
            }
            }
            break;
        }
        case 3:
        {
            switch (menu_level_2) {
            case 1://3.1 채용 정보 등록
            {   
                cout << "3.1. 채용 정보 등록\n";
                string work = inputString[2];
                int employCount=stoi(inputString[3]);
                string deadline=inputString[4];
                registerEmployInfoUI.inputEmployInfo(work,employCount,deadline);
                break;
            }
            case 2: //3.2 등록된 채용 정보 조회
            {
                cout << "3.2. 등록된 채용 정보 조회\n" ;
                askEmployInfoUI.ask();
                break;
            }
            }
            break;
        }
        case 4:
        {
            switch (menu_level_2) {
            case 1://4.1 채용 정보 검색
            {
                break;
            }
            case 2: //4.2 채용 지원
            {
                break;
            }
            case 3: //4.3 지원 정보 조회
            {
                break;
            }
            case 4: //4.4 지원 취소
            {
                break;
            }
            }
            break;
        }
        case 5:
        {
            switch (menu_level_2) {
            case 1://5.1 지원 정보 통계
            {
                break;
            }
            }
            break;
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1:   // "6.1. 종료“ 메뉴 부분
            {
                program_exit();
                is_program_exit = 1;
                break;;
            }
            }
        }

        }
    }
}

 void program_exit()
{
            
}
 
 //input.txt에서 받은 string ' ' 단위로 잘라서 저장하는 함수
 vector<string> split(string str, char dlim) {
     vector<string> result;
     stringstream ss(str);
     string buffer;
     while (getline(ss, buffer, dlim)) {
         result.push_back(buffer);
     }
     return result;
 }