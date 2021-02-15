#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 1001;
const int MOD = 1000000003;

int n, k;

long long dp[MAX][MAX]; // N, k번째

void solution(){

    cin >> n >> k;

    
    for (int i = 1; i <= 3; i++) dp[i][1] = i;

    for (int i = 4; i <= n; i++){
        int maxSelect = i / 2;

        for (int c = 1; c <= maxSelect; c++){
            if (c == 1) dp[i][c] = i;
            else dp[i][c] = (dp[i - 2][c - 1] + dp[i - 1][c]) % MOD;
        }
    }

    
    
    
    cout << dp[n][k] << '\n';

        
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;

}