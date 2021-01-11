#include <iostream>

using namespace std;

int n, m;

int map[1025][1025];
int dp[1025][1025];

void solution(){
    cin >> n >> m;

    for (int i = 0; i  < n; i++)
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
            dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + map[i][j];
        }

    for (int i = 0; i < m; i++){
        int x1, x2, y1, y2;

        cin >> x1 >> y1 >> x2 >> y2;

        cout << (dp[x2][y2] - dp[x2][y1 - 1] - dp[x1 - 1][y2] + dp[x1-1][y1-1]) << '\n';
    }
    


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}