#include <iostream>

using namespace std;

const int MAX = 41;

int n, vipCnt;
int dp[MAX];
int vip[MAX];

void calDP(){
    dp[0] = dp[1] = 1;

    for (int i = 2; i <= n; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
}

int calCase(){
    int res = 1;

    for (int i = 1; i <= vipCnt; i++){
        res *= dp[vip[i] - vip[i-1] - 1];
    }

    return res *= dp[n - vip[vipCnt]];
}
void solution(){

    cin >> n;

    calDP();


    cin >> vipCnt;

    for (int i = 1; i <= vipCnt; i++){
        cin >> vip[i];
    }

    cout << calCase() << '\n';
    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}