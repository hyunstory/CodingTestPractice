#include <iostream>

using namespace std;

void solution(){
    int n;
    int dp[31] = {0, };

    cin >> n;
    
    dp[0] = 1;
    dp[2] = 3;

    for (int i = 4; i <= n; i++){
        dp[i] = dp[i - 2] * 3; 

        for (int j = 4; j <= i; j += 2){
            dp[i] += dp[i - j] * 2;
        }
    }

    cout << dp[n] << '\n';

    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}