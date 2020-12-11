#include <iostream>
#include <string>

using namespace std;


void solution(){

    string t;

    int result = 1;

    getline(cin, t, '\n');

    int t_size = t.size();

    if ((t[0] == '\n' || t[0] == ' ') && t.length() == 1){
        cout << 0 << '\n';
        return;
    }

    for (int i = 1; i < t_size - 1; i++){
        if(t[i] == ' ') result++;
    }

    cout << result << '\n';
}
int main(){

    solution();

    return 0;
}