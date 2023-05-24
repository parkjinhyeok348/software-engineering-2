#define _CRT_SECURE_NO_WARNINGS
// ��� ����
#include "stdcol.h"
#include"EmployInfo.h"
#include"EmployInfoCollection.h"
#include"RegisterEmployInfo.h"
#include"RegisterEmployInfoUI.h"
#include"AskEmployInfoUI.h"

#define INPUT_FILE_NAME "input.txt"
#define OUTPUT_FILE_NAME "output.txt"

// �Լ� ����
void run();
void program_exit();
vector<string> split(string str,char dlim);

//Ŭ���� ����
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

    // �޴� �Ľ��� ���� level ������ ���� ����
    int menu_level_1 = 0, menu_level_2 = 0;
    int is_program_exit = 0;

    while (!is_program_exit)
    {
        // �Է����Ͽ��� �޴� ���� 2���� �б�
        string input;
        getline(in_fp, input);

        vector<string> inputString = split(input, ' ');

        menu_level_1 = stoi(inputString[0]);
        menu_level_2 = stoi(inputString[1]);

        // �޴� ���� �� �ش� ���� ����
        switch (menu_level_1){
        case 1:
        {
            switch (menu_level_2)
            {
            case 1:   // 1.1. ȸ������
            {

                break;
            }
            case 2: // 1.2 ȸ�� Ż��
            {
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
                break;
            }
            case 2: //2.2 �α׾ƿ�
            {
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
                cout << "3.1. ä�� ���� ���\n";
                string work = inputString[2];
                int employCount=stoi(inputString[3]);
                string deadline=inputString[4];
                registerEmployInfoUI.inputEmployInfo(work,employCount,deadline);
                break;
            }
            case 2: //3.2 ��ϵ� ä�� ���� ��ȸ
            {
                cout << "3.2. ��ϵ� ä�� ���� ��ȸ\n" ;
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
                break;
            }
            case 2: //4.2 ä�� ����
            {
                break;
            }
            case 3: //4.3 ���� ���� ��ȸ
            {
                break;
            }
            case 4: //4.4 ���� ���
            {
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