#include <iostream>
#include <vector>

using namespace std;

void solution(){

    int n;

    cin >> n;

    vector<int> dp(n+1, 0);

    for (int i = 1; i <= n; i++){
        dp[i] = i;

        for (int j = 1; j*j <= i; j++) dp[i] = min(dp[i], dp[i-j*j] + 1);
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