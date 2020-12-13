#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define INF 999999999

int street[1000];

int dp[1000];

int n;

int dfs(int pos) {

	if (pos == n - 1) return 0;

	int &ret = dp[pos];

	if (ret != -1) return ret;

	ret = INF;

	for (int i = pos + 1; i < n; i++) 
		if (street[i] == (street[pos] + 1) % 3) ret = min(ret, dfs(i) + (i - pos) * (i - pos));

	return ret;

}

void solution() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		char c;

		cin >> c;

		if (c == 'B') street[i] = 0;
		else if (c == 'O') street[i] = 1;
		else street[i] = 2;

	}

	memset(dp, -1, sizeof(dp));

	int ret = dfs(0);

	cout << (ret == INF ? -1 : ret) << '\n';



}

int main() {

	solution();

	return 0;
}
