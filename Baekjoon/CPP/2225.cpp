#include <iostream>

using namespace std;

int n, k;
#define MAX 201

long long dp[MAX][MAX];

const int mod = 1000000000;

void solution(){

    cin >> n >> k;

    for (int i = 0; i <= n; i++) dp[1][i] = 1;
    for (int i = 0; i <= k; i++) dp[i][0] = 1;

    for (int i = 2; i <= k; i++){
        for (int j = 1; j <= n; j++){
            dp[i][j] = (dp[i][j-1] + dp[i-1][j]) % mod;
        }
    }

    cout << dp[k][n] << '\n';



}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}