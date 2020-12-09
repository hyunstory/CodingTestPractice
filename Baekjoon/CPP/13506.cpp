#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPI(string s){
    int idx = 0;
    int s_len = s.length();

    vector<int> nested(s_len, 0);

    for (int i = 1; i < s_len; i++){
        while(idx > 0){
            if (s[i] == s[idx]) break;
            idx = nested[idx - 1];
        }

        if (s[i] == s[idx]) nested[i] = ++idx;
    }

    return nested;

}
void solution(){

    string s;

    cin >> s;

    int s_len = s.length();

    vector<int> nested = getPI(s);


    

    int pre_size = nested[s_len - 1];
    
    bool ok = false;

    while(pre_size){
        for (int i = 1; i < s_len - 1; i++){
            if (nested[i] == pre_size){
                for (int j = 0; j < pre_size; j++){
                    cout << s[j];
                }
                ok = true;
                break;
                
            }
        }
        if (ok) break;
        pre_size = nested[pre_size - 1];
    }

    


    if (!ok) cout << -1 << '\n';
    


}

int main(){

    solution();

    return 0;
}