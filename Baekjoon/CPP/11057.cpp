#include <iostream>

using namespace std;

int dp[10001][10];

void solution(){
    int n;

    cin >> n;

    int result = 0;

    for (int i = 0; i <= 9; i++) dp[1][i] = 1;

    


    for (int i = 2; i <= n; i++){
        for (int j = 0; j <= 9; j++){
            for (int k = j; k <= 9; k++){
                dp[i][k] += dp[i-1][j];
                dp[i][k] %= 10007;
            }
        }
    }


    for (int i = 0; i <= 9; i++) result += dp[n][i];

    result %= 10007;
    
    cout << result << '\n';


}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}