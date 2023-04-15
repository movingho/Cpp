#include <iostream>
#include <string>

using namespace std;

int main() {
    string str_ex("One program a day: The simpler, the better. Blank what you learned. Blank with your peers.");
    string str_get;
    string str_chg ("Blank");
    cout << "다음 문자열을 입력하세요" << endl << str_ex << endl << endl;
    getline(cin, str_get);
    
    if(str_ex != str_get)
        cout << "잘못 입력하였습니다." << endl;
    else {
        size_t found = str_get.find(str_get);
        if (found != string::npos)
            str_get.replace(str_get.find(str_chg), str_chg.length(), "Organize");
        found = str_get.find(str_chg, found+1);
        if (found != string::npos)
            str_get.replace(str_get.find(str_chg), str_chg.length(), "Communicate");

    }
    cout << "\n변경된 문장: " << str_get << endl;
}
