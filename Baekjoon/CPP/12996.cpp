#include <iostream>
#include <cstring>

using namespace std;

const int mod = 1000000007;

long long dp[51][51][51][51];


long long dfs(int S, int a, int b, int c) {

	if (S == 0) {
		if (a == 0 && b == 0 && c == 0) return 1;
		else return 0;
	}

	if (a < 0 || b < 0 || c < 0) return 0;

	long long &ret = dp[S][a][b][c];

	if (ret != -1) return ret;  // 중복 계산을 피하게 만들어줌. 

	ret = 0;

	ret += dfs(S - 1, a - 1, b, c);
	ret += dfs(S - 1, a, b - 1, c);
	ret += dfs(S - 1, a, b, c - 1);
	ret += dfs(S - 1, a - 1, b - 1, c);
	ret += dfs(S - 1, a - 1, b, c - 1);
	ret += dfs(S - 1, a, b - 1, c - 1);
	ret += dfs(S - 1, a - 1, b - 1, c - 1);

	ret %= mod;

	return ret;


}

void solution() {

	int S, a, b, c;

	cin >> S >> a >> b >> c;

	memset(dp, -1, sizeof(dp));

	cout << dfs(S, a, b, c) << '\n';


}

int main() {

	solution();

	return 0;
}
