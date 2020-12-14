/*

문자열 알고리즘에서, 대문자, 소문자를 쉽게 변환해주는 헤더 정보

*/

#include <iostream>
#include <string>
#include <cctype>
#include <algorithm>


using namespace std;

void solution(){

    //가장 중요한 대문자화, 소문자화

    string ss = "test";

    // string에서 대문자를 변경

    char a = 'a';

    a = toupper(a);



    // 이 char가 대문자냐?

    if (isupper(a)){
        cout << "upper" << '\n';
    }

    // 이 char가 소문자냐?
    else if(islower(a)){
        cout << "lower" << '\n';
    }



    // string에 있는 모든 문자열을 대문자로 변환 ::를 쓰는 이유는 namespace 이유?? ::가 없으면 vscode에서 컴파일이 안됨.
    transform(ss.begin(), ss.end(), ss.begin(), ::toupper);

    // string에 있는 모든 문자열을 소문자로 변환 ::tolower쓰는 이유는 namespace 이유?
    transform(ss.begin(), ss.end(), ss.begin(), ::tolower);



    // !<-- 아래코드는 vscode 에서 안돌아감) -->

    //transform(s.begin(), s.end(), s.begin(), toupper);

    // string에서 소문자로 변경
    //transform(s.begin(), s.end(), s.begin(), tolower);
}

int main(){


    solution();

    return 0;
}