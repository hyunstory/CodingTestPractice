#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int arr[14];
int k;
int result[7];
bool check[50];

void dfs(int idx, int depth) {

	if (depth == 6) {
		for (int i = 0; i < 6; i++) {
			cout << result[i] << ' ';
		}
		cout << '\n';
		return;
	}


	for (int i = idx; i < k; i++) {

		result[depth] = arr[i];

		dfs(i + 1, depth + 1);


	}
}
void solution() {

	while (cin >> k && k) {

		for (int i = 0; i < k; i++) { cin >> arr[i]; }
		dfs(0, 0);
		cout << '\n';
	}


}
int main() {


	solution();

	return 0;
}