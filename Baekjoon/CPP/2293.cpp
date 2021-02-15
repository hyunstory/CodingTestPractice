/*

2020 하반기 네이버 공채코테에 나왔던 문제와 비슷한 문제...

다시 풀어보고 싶어서 문제를 찾아서 풀어봄. 

topdown 은 이문제에서 메모리 초과이다. 

bottom-up 방식




*/

#include <iostream>

using namespace std;

int n, k;

int coin[101];
int dp[10001];

void solution(){
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++){
        cin >> coin[i];
    }
    
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = coin[i]; j <= k; j++){
            dp[j] += dp[j - coin[i]];
        }

    cout << dp[k] << '\n';
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}