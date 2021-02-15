#include <iostream>

using namespace std;

const int MAX = 100002;
const int mod = 9901;

int dp[MAX][3];

void solution(){

    int n;

    cin >> n;

    dp[1][0] = dp[1][1] = dp[1][2] = 1;

    


    for (int i = 2; i <= n; i++){
        dp[i][0] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % mod;
        dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % mod;
        dp[i][2] = (dp[i - 1][0] + dp[i - 1][1]) % mod;
    }
    
    cout << (dp[n][0] + dp[n][1] + dp[n][2]) % mod << '\n';


}
int main(){

    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}