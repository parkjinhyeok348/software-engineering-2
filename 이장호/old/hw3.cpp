#define _CRT_SECURE_NO_WARNINGS
// 헤더 선언
#include <stdio.h>
#include <string.h>
#include "Join.h"
#include "Withdraw.h"
#include "Login.h"
#include "Logout.h"
#include "Member.h"
#include "MemberList.h"

// 상수 선언
#define MAX_STRING 32

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// 함수 선언
void run();
void program_exit();

// 변수 선언
FILE* in_fp, * out_fp;

int main()
{
    // 파일 입출력을 위한 초기화
    in_fp = fopen(INPUT_FILE_NAME, "r+");
    out_fp = fopen(OUTPUT_FILE_NAME, "w+");


    run();

    return 0;
}


void run()
{
    // 메뉴 파싱을 위한 level 구분을 위한 변수
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;


    while (!is_program_exit)
    {
        // 입력파일에서 메뉴 숫자 2개를 읽기
        fscanf(in_fp, "%d %d ", &menu_level_1, &menu_level_2);
        

        // 메뉴 구분 및 해당 연산 수행
        switch (menu_level_1)
        {
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // 1.1. 회원가입
            {
                // Register Control 객체를 생성 후, run 함수 실행.
                Join * join = new Join;
                join->run(in_fp, out_fp);
                break;
            }
            case 2: // 1.2 회원 탈퇴
            {
                // Withdraw Control 객체 생성 후, run 함수 실행.
                Withdraw* withdraw = new Withdraw;
                withdraw->run(in_fp, out_fp);
                break;
            }
            }
        }
        case 2:
        {
            switch (menu_level_2) {
            case 1://2.1 로그인
            {
                Login* login = new Login;
                login->run(in_fp, out_fp);
            }
            case 2: //2.2 로그아웃
            {
                Logout* logout = new Logout;
                logout->run(in_fp, out_fp);
            }
            }
        }
        case 3:
        {
            switch (menu_level_2) {
            case 1://3.1 채용 정보 등록
            {
            }
            case 2: //3.2 등록된 채용 정보 조회
            {
            }
            }
        }
        case 4:
        {
            switch (menu_level_2) {
            case 1://4.1 채용 정보 검색
            {
            }
            case 2: //4.2 채용 지원
            {
            }
            case 3: //4.3 지원 정보 조회
            {
            }
            case 4: //4.4 지원 취소
            {
            }
            }

        }
        case 5:
        {
            switch (menu_level_2) {
            case 1://5.1 지원 정보 통계
            {
            }
            }
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

        return;
    }
}

void program_exit()
{
    fprintf(out_fp, "6.1. 종료");
    fclose(in_fp);
    fclose(out_fp);
}