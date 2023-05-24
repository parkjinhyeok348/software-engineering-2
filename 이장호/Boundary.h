class JoinUI {
public:

    void startInterface(Join* join, FILE* in_fp, FILE* out_fp);

    void selectMemberType();

    void submitMemberInfo();

private:
    // 이 Boundary를 사용중인 Control의 포인터
    Join* join;
    // 파일 입출력 주소
    FILE* in_fp;
    FILE* out_fp;
};

class LoginUI {
private:
    Login* login;
    FILE* in_fp;
    FILE* out_fp;
public:
    // 사용자 인터페이스(파일 입/출력)의 시작을 위해 실행되는 함수.
    void startInterface(Login* login, FILE* in_fp, FILE* out_fp);
    // 사용자가 정보(ID, Password)를 입력하여 제출할 때 사용되는 함수.
    void submitInfo();
};

class LogoutUI {
private:
    Logout* logout;
    FILE* in_fp;
    FILE* out_fp;

public:
    // 사용자 인터페이스(파일 입/출력)의 시작을 위해 실행되는 함수.
    void startInterface(Logout* logout, FILE* in_fp, FILE* out_fp);
    // 사용자의 로그아웃을 확정하는 함수.
    void confirmLogout();
};

class WithdrawUI {
private:
    Withdraw* withdraw;
    FILE* in_fp;
    FILE* out_fp;

public:

    void startInterface(Withdraw* withdraw, FILE* in_fp, FILE* out_fp);

    void confirmWithdrawal();
};