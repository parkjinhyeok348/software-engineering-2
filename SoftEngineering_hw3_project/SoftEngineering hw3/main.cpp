#define _CRT_SECURE_NO_WARNINGS
// 헤더 선언
#include "stdcol.h"
#include "entity.h"
#include "control.h"
#include "boundary.h"

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void run();
void program_exit();
vector<string> split(string str,char dlim);

//클래스 선언
EmployInfoCollection employInfoCollection;

//변수 선언
ofstream out_fp;
ifstream in_fp;


int main()
{
     run();

     return 0;
}






void run()
{
    out_fp.open(OUTPUT_FILE_NAME);
    in_fp.open(INPUT_FILE_NAME);

    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {

        in_fp >> menu_level_1 >> menu_level_2;

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1){
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // 1.1. 회원가입
            {
                Join* join = new Join;
                join->run();
                break;
            }
            case 2: // 1.2 회원 탈퇴
            {
                Withdraw* withdraw = new Withdraw;
                withdraw->run();
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
                Login* login = new Login;
                login->run();
                break;
            }
            case 2: //2.2 로그아웃
            {
                Logout* logout = new Logout;
                logout->run();
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
                RegisterEmployInfoUI* registerEmployInfoUI = new RegisterEmployInfoUI;
                registerEmployInfoUI->inputEmployInfo();
                break;
            }
            case 2: //3.2 등록된 채용 정보 조회
            {                
                AskEmployInfoUI askEmployInfoUI;
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
                SearchEmploy* searchEmploy = new SearchEmploy;
                searchEmploy->start();
                break;
            }
            case 2: //4.2 채용 지원
            {
                ApplyEmploy* applyEmploy = new ApplyEmploy;
                applyEmploy->start();
                break;
            }
            case 3: //4.3 지원 정보 조회
            {
                ShowApplyInfoUI* boundary = new ShowApplyInfoUI();
                boundary->clickApplyInfo();
                break;
            }
            case 4: //4.4 지원 취소
            {
                CancelApplyInfoUI* boundary = new CancelApplyInfoUI();
                boundary->selectCancelApply();
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
                ShowApplyStats* showApplyStats = new ShowApplyStats;
                showApplyStats->run();
                delete showApplyStats;
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
     out_fp << "6.1.종료" << endl;
     in_fp.close();
     out_fp.close();
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