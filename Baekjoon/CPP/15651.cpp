#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool check[10];

void dfs(int idx, int depth) {

	if (depth == m) {

		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';

		}

		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		arr[depth] = i + 1;

		dfs(idx, depth + 1);
	}
}
void solution() {


	cin >> n >> m;

	dfs(0, 0);



}
int main() {


	solution();


	return 0;
}