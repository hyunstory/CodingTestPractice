#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, s;
int result;
int arr[22];

void dfs(int depth, int sum) {

	

	if (depth >= n) return;

	sum += arr[depth];


	if (sum == s) result++;


	dfs(depth + 1, sum);
	dfs(depth + 1, sum - arr[depth]);
}
void solution() {


	cin >> n >> s;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dfs(0, 0);

	cout << result << '\n';
}
int main() {


	solution();

	return 0;
}