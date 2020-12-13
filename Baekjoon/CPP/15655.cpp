#include <iostream>
#include <algorithm>


using namespace std;

int n, m;
int arr[9];
int result[10];
bool check[10];

void dfs(int idx, int depth) {

	if (depth == m) {

		for (int i = 0; i < m; i++) {
			cout << result[i] << ' ';
			
		}

		cout << '\n';
		return;
		
	}

	for (int i = idx; i < n; i++) {

		if (check[i]) continue;

			
		if (depth >= 1 && result[depth - 1] >= arr[i]) continue;

		check[i] = true;
		result[depth] = arr[i];
		dfs(idx + 1, depth + 1);

		check[i] = false;

		
	}
}
void solution() {


	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}


	sort(arr, arr + n);
	dfs(0, 0);



}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();


	return 0;
}