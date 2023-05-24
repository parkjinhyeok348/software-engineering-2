#ifndef _MEMBER_H
#define _MEMBER_H


#include <string>
#include <sstream>



using namespace std;

class Member {
public: 
    
bool isPasswordCorrect(string password);
        
void setLoginStatus(bool loginStatus);

static Member** getCurrentMember();
static void setCurrentMember(Member** newCurrentMember);
string getID();
string getPassword();
virtual string getMemberInfo();
void setId(string id);
void setPassword(string password);

private: 
    static Member** currentMember;
    string id;
    string password;
    bool loginStatus;
};

#endif //_MEMBER_H