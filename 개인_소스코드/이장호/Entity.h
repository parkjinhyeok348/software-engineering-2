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

class GeneralMember: public Member {
public:
    // 기본 생성자 (아래의 생성자 선언을 위해 만듦)
    GeneralMember();
    // 생성과 동시에 정보를 주입하는 생성자.
    GeneralMember(string id, string password, string name, int ssn);
    // 회원 정보 문자열을 반환하는 함수
    virtual string getMemberInfo();
private: 
    // 이름
    string name;
    // 주민등록번호
    int ssn;
};

class CompanyMember: public Member {
public:
    // 기본 생성자 (아래의 생성자 선언을 위해 만듦)
    CompanyMember();
    // 생성과 동시에 정보를 주입하는 생성자.
    CompanyMember(string id, string password, string companyName, int businessNum);
    // 회원 정보 문자열을 반환하는 함수
    virtual string getMemberInfo();
private: 
    // 회사 이름
    string companyName;
    // 사업자 등록 번호
    int businessNum;
};

class MemberList {
public: 
// Singleton design
static MemberList* getMemberList();
// ID를 통해 해당하는 Member의 포인터를 저장한 배열의 위치를 반환하는 함수
Member** findByID(string id);
    
// 목록에서 해당 회원을 지우는 함수
void deleteMember(Member** deletedMember);
    
// 일반 회원을 등록하는 함수. 추가된 회원의 index를 반환한다.
GeneralMember * addGeneralMember(string id, string password, string name, int ssn);

// 회사 회원을 등록하는 함수. 추가된 회원의 index를 반환한다.
CompanyMember * addCompanyMember(string id, string password, string companyName, int businessNum);

    
private: 
    // Singleton Design
    MemberList();
    static MemberList * memberList;
    // 회원 목록
    Member * members[MAX_MEMBER];
    // 배열 크기(현재 회원 수)
    int size = 0;
};
