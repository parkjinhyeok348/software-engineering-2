#include "stdcol.h"
#include "AskEmployInfoUI.h"
#include "AskEmployInfo.h"

#define OUTPUT_FILE_NAME "output.txt"

//클래스 선언
AskEmployInfo askEmployInfo;

AskEmployInfoUI::AskEmployInfoUI(){}//생성자

AskEmployInfoUI::~AskEmployInfoUI(){}//소멸자
ofstream out_fp(OUTPUT_FILE_NAME);


//control 클래스에 회사회원이 등록한 채용 정보 리스트 요청하여 출력함
void AskEmployInfoUI::ask() {
    vector<string>detailList;
    out_fp << "3.2 채용 정보 조회" << endl;
    detailList= askEmployInfo.showEmployInfo();
    for (int i = 0; i < detailList.size(); i++) {
        out_fp << detailList[i] << endl;
    }
}