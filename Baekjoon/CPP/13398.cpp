#include <iostream>
#include <algorithm>

using namespace std;

int n;
int arr[100001];
int dp[100001][2];



void solution(){

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int ans = arr[0];

    for (int i = 0; i < n; i++){
        dp[i][0] = dp[i][1] = arr[i];

        if (i == 0) continue;

        dp[i][0] = max(dp[i-1][0] + arr[i], arr[i]);
        dp[i][1] = max(dp[i-1][0], dp[i-1][1] + arr[i]);

        ans = max(ans, max(dp[i][0], dp[i][1]));
    }

    cout << ans << '\n';


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}