#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

deque<char> a;
deque<char> b;

void solution(){

    string one, two;

    cin >> one >> two;

    for (int i = 0; i < one.length(); i++){
        a.push_back(one[i]);

    }
    for (int i = 0; i < two.length(); i++){
        b.push_back(two[i]);
    }

    int result = __INT_MAX__;

    for (int i = 0; i <= b.size() - a.size(); i++){
        int cnt = 0;
        for (int j = 0; j < a.size(); j++){
            if(a[j] != b[i + j]) cnt++;
        }

        result = min(cnt, result);
    }

    cout << result << '\n';
    


}
int main(){

    solution();


    return 0;
}