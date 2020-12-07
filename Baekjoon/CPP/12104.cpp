#include <iostream>
#include <vector>
#include <string>
#include <deque>

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

    string p;
    string s;

    getline(cin, s, '\n');
    getline(cin, p, '\n');

    deque<char> dq;

    int s_len = s.length();
    int p_len = p.length();

    for (int i = 0; i < p_len; i++){
        dq.push_back(p[i]);
    }
    for (int i = 0; i < p_len - 1; i++){
        dq.push_back(p[i]);
    }

    //for (int i = 0; i < dq.size(); i++){
    //    cout << dq[i] << ' ';
    //}

    vector<int> nested = getPI(s);

    
    int idx = 0;
    vector<int> ans;

    int dq_size = dq.size();

    for (int i = 0; i < dq_size; i++){
        while(idx > 0){
            if (dq[i] == s[idx]) break;
            idx = nested[idx - 1];
        }

        if (dq[i] == s[idx]){
            if (idx == s_len - 1){
                ans.push_back(i - (s_len - 1));
                idx = nested[idx];
            }
            else idx++;
        }
    }

    
    int ans_size = ans.size();

    cout << ans_size << '\n';


}

int main(){


    solution();

    return 0;
}