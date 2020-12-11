#include <iostream>
#include <algorithm>

using namespace std;

int hou[1001][3];
int dp[1001][3];
int n;

void solution(){
    
    cin >> n;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < 3; j++){
            int temp;
            cin >> temp;

            hou[i][j] = temp;
        }
    }
    
    dp[0][0] = hou[0][0];
    dp[0][1] = hou[0][1];
    dp[0][2] = hou[0][2];

    for (int i = 1; i < n; i++){
        dp[i][0] = min(dp[i-1][1], dp[i-1][2]) + hou[i][0];
        dp[i][1] = min(dp[i-1][0], dp[i-1][2]) + hou[i][1];
        dp[i][2] = min(dp[i-1][0], dp[i-1][1]) + hou[i][2];
    }

    int minV = __INT_MAX__;

    for (int i = 0; i < 3; i++){
        if (dp[n-1][i] < minV) minV = dp[n-1][i];
    }

    cout << minV << '\n';
}
int main(){


    solution();


    return 0;
}