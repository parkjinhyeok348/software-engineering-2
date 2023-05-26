#define _CRT_SECURE_NO_WARNINGS
// ��� ����
#include "stdcol.h"
#include "entity.h"
#include "control.h"
#include "boundary.h"

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void run();
void program_exit();
vector<string> split(string str,char dlim);

//Ŭ���� ����
EmployInfoCollection employInfoCollection;

//���� ����
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

    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {

        in_fp >> menu_level_1 >> menu_level_2;

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1){
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // 1.1. ȸ������
            {
                Join* join = new Join;
                join->run();
                break;
            }
            case 2: // 1.2 ȸ�� Ż��
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
            case 1://2.1 �α���
            {
                Login* login = new Login;
                login->run();
                break;
            }
            case 2: //2.2 �α׾ƿ�
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
            case 1://3.1 ä�� ���� ���
            {             
                RegisterEmployInfoUI* registerEmployInfoUI = new RegisterEmployInfoUI;
                registerEmployInfoUI->inputEmployInfo();
                break;
            }
            case 2: //3.2 ��ϵ� ä�� ���� ��ȸ
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
            case 1://4.1 ä�� ���� �˻�
            {
                SearchEmploy* searchEmploy = new SearchEmploy;
                searchEmploy->start();
                break;
            }
            case 2: //4.2 ä�� ����
            {
                ApplyEmploy* applyEmploy = new ApplyEmploy;
                applyEmploy->start();
                break;
            }
            case 3: //4.3 ���� ���� ��ȸ
            {
                ShowApplyInfoUI* boundary = new ShowApplyInfoUI();
                boundary->clickApplyInfo();
                break;
            }
            case 4: //4.4 ���� ���
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
            case 1://5.1 ���� ���� ���
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
            case 1:   // "6.1. ���ᡰ �޴� �κ�
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
     out_fp << "6.1.����" << endl;
     in_fp.close();
     out_fp.close();
}
 
 //input.txt���� ���� string ' ' ������ �߶� �����ϴ� �Լ�
 vector<string> split(string str, char dlim) {
     vector<string> result;
     stringstream ss(str);
     string buffer;
     while (getline(ss, buffer, dlim)) {
         result.push_back(buffer);
     }
     return result;
 }