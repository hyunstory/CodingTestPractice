#include <iostream>
#include <deque>
#include <string>
#include <cstring>

using namespace std;

string word;
string one;
string two;

long long dp[102][29][2]; // 위치, 돌다리 0, 1
int len;

long long go(int idx, int cur, int br){

    long long &ret = dp[idx][cur][br];
    if (ret != -1) return ret;
    ret = 0;
    
    if(cur == word.length()) {
        return 1;
    }

    else if (idx == len) return 0;
    



    if (br == 0){
        if (one[idx] == word[cur]){
            ret += go(idx + 1, cur + 1, 1);
        }
        ret += go(idx + 1, cur, br);
    }
    else{
        if (two[idx] == word[cur]){
            ret += go(idx + 1, cur + 1, 0);
        }
        ret += go(idx + 1, cur, br);
        
    }

    return ret;
}
void solution(){
    cin >> word >> one >> two;

    len = one.length();

    memset(dp, -1, sizeof(dp));

    cout << go(0, 0, 0) + go(0, 0, 1) << '\n';
    

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}