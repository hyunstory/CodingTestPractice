#include <iostream>
#include <algorithm>

using namespace std;

#define MAX 1001
int n;

int map[MAX][3];
int dp[MAX][3];


void solution(){
    int result = __INT_MAX__;

    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> map[i][0] >> map[i][1] >> map[i][2];
    }

    for (int i = 0; i < 3; i++){
        for (int j = 0; j < 3; j++){
            if (i == j) dp[1][j] = map[1][j];
            else dp[1][j] = 1000000000;
        }

        for (int j = 2; j <= n; j++){
            dp[j][0] = min(dp[j - 1][1], dp[j - 1][2]) + map[j][0];
            dp[j][1] = min(dp[j - 1][0], dp[j - 1][2]) + map[j][1];
            dp[j][2] = min(dp[j - 1][1], dp[j - 1][0]) + map[j][2];
        }

        for (int j = 0; j < 3; j++){
            if (i != j) result = min(result, dp[n][j]);
        }
    }

    cout << result << '\n';




}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;

}