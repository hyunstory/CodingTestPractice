/*
MARK: - string라이브러리에서 to_string은 int -> string으로 변환해준다.
char에서 string 변환은 string선언 시, string str(캐릭터형); 을 넣어주면 변환된다. 
반대로 string에서 int 변환은 stoi()
*** char에서 int는 atoi -> atoi가 용어가 약간 헷갈린다.

정리
to_string(int) : int -> string
string str(char) : char -> string
stoi(), stof(), stoll  : string -> int, float, long long
atoi() : char -> int

*/

#include <iostream>
#include <string>


using namespace std;


void solution(){
    int n;
    cin >> n;
    int result = 0;

    for (int i = 1; i <= n; i++){
        string s = to_string(i);

        if (s.length() == 1) result++;


        else {
            int diff = s[0] - s[1];

            bool ok = true;
            for (int j = 2; j < s.length(); j++){
                if ((s[j - 1] - s[j]) != diff) ok = false;
                
            }

            if (ok) result++;
        }

    }

    cout << result << '\n';

}
int main(){


    solution();

    return 0;
}