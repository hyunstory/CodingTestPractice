#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

const int MAX = 1001;

int dp[MAX][MAX];

void solution(){

    string a, b;
    cin >> a >> b;

    int a_size = a.length();
    int b_size = b.length();

    for (int i = 1; i <= a_size; i++)
        for (int j = 1; j <= b_size; j++){
            if (a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
            }
            else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }

    

    cout << dp[a_size][b_size] << '\n';
    


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}