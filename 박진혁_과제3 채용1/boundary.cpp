#include "stdcol.h"
#include "boundary.h"
#include "control.h"

#define OUTPUT_FILE_NAME "output.txt"

//클래스 선언
AskEmployInfo askEmployInfo;

AskEmployInfoUI::AskEmployInfoUI() {}//생성자

AskEmployInfoUI::~AskEmployInfoUI() {}//소멸자
ofstream out_fp(OUTPUT_FILE_NAME);


//control 클래스에 회사회원이 등록한 채용 정보 리스트 요청하여 출력함
void AskEmployInfoUI::ask() {
    vector<string>detailList;
    out_fp << "3.2 채용 정보 조회" << endl;
    detailList = askEmployInfo.showEmployInfo();
    for (int i = 0; i < detailList.size(); i++) {
        out_fp << detailList[i] << endl;
    }
}


//클래스 선언
RegisterEmployInfo registerEmployInfo;


RegisterEmployInfoUI::RegisterEmployInfoUI() {//생성자

}
RegisterEmployInfoUI::~RegisterEmployInfoUI() {//소멸자

}

//업무,지원수,신청 마감일 입력 받음
void RegisterEmployInfoUI::inputEmployInfo(string work, int employCount, string deadline) {
    createNewEmployInfo(work, employCount, deadline);
}

//control 클래스에 업무,지원수, 신청 마감일을 전달 후 output.txt 에 출력함
void RegisterEmployInfoUI::createNewEmployInfo(string work, int employCount, string deadline) {
    registerEmployInfo.registerEmpolyInfo(work, employCount, deadline);
    out_fp << "3.1 채용 정보 등록" << endl;
    out_fp << ">" << work << " " << employCount << " " << deadline << endl;
}