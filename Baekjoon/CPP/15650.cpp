#include <iostream>

using namespace std;

int n, m;
int arr[9];
bool check[10];

void dfs(int idx, int depth) {

	if (depth == m) {
		for (int i = 0; i < m; i++) cout << arr[i] << ' ';

		cout << '\n';

		return;
	}



	for (int i = idx; i < n; i++) {

		if (!check[i]) {

			if (depth >= 1 && arr[depth - 1] > i + 1) continue;

			check[i] = true;
			arr[depth] = i + 1;
			dfs(idx + 1, depth + 1);

			check[i] = false;
		}
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