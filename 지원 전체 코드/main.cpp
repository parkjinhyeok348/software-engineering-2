#define _CRT_SECURE_NO_WARNINGS
// #pragma once

// 헤더 선언
#include <stdio.h>
#include <string.h>
#include <string>
#include <iostream>
#include <vector>
#include "BoundaryClass.h"

// 상수 선언
#define MAX_STRING 32

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

using namespace std;

// 함수 선언
void run();
void Register();
void program_exit();

// 변수 선언
FILE* in_fp = NULL;
FILE* out_fp;
int businessNumber = 0;

// 클래스 선언


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
            Register();
            break;
          }
        }
        break;
      }
      case 4:
      {
        switch (menu_level_2) {
          case 3: //4.3 지원 정보 조회
          {
            ShowApplyInfoUI* boundary = new ShowApplyInfoUI();
            boundary->clickApplyInfo(out_fp);
            break;
          }
          case 4: //4.4 지원 취소
          {
            CancelApplyInfoUI* boundary = new CancelApplyInfoUI();
            boundary->selectCancelApply(in_fp,out_fp, businessNumber);
            break;
          }
        }
        break;
      }
        case 5:
        {
            switch (menu_level_2) {
            case 1: //5.1 지원 정보 통계
            {
              PrintApplyNumUI* boundary = new PrintApplyNumUI();
              boundary->clickApplyNum(out_fp);
              break;
            }
            }
             break;
        }
        case 6:
        {
            switch (menu_level_2)
            {
            case 1: // 6.1. 종료 메뉴 부분
            {

                program_exit();
                is_program_exit = 1;
                break;
            }
            }
             break;
        }
      }
    }
}


void Register() {
  char user_type[MAX_STRING], name[MAX_STRING], SSN [MAX_STRING], address[MAX_STRING], ID[MAX_STRING], password[MAX_STRING];

  // 입력 형식 : 이름, 주민번호, ID, Password를 파일로부터 읽음
  fscanf(in_fp, "%s %s %s %s", &name, &SSN, &ID, &password);

  // 해당 기능 수행
            
  // 출력 형식
  fprintf(out_fp, "1.1. 회원가입\n");
  fprintf(out_fp, "%s %s %s %s\n", name, SSN, ID, password);
}


void program_exit()
{
  fprintf(out_fp,"6.1. 종료");
}