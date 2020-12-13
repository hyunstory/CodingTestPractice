#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>

using namespace std;

int n;
int map[101][101];
long long dp[101][101];

void solution() {

	cin >> n;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			cin >> map[i][j];

	dp[1][1] = 1;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			if (dp[i][j] == 0 || (i == n && j == n)) continue;

			int step = map[i][j];

			int d = step + i;
			int r = step + j;

			if (d <= n) dp[d][j] = dp[d][j] + dp[i][j];
			if (r <= n) dp[i][r] = dp[i][r] + dp[i][j];
		}

	cout << dp[n][n] << '\n';


}


int main() {

	solution();

	return 0;
}
