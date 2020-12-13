#include <iostream>

using namespace std;


int n, m;

bool check[10];
int arr[10];

void dfs(int idx, int depth) {

	if (depth == m) {
		
		for (int i = 0; i < m; i++) {

			cout << arr[i] << ' ';
		}
		cout << '\n';
		
	}


	for (int i = 0; i < n; i++) {

		if (!check[i]) {
			arr[depth] = i + 1;

			check[i] = true;
			dfs(i + 1, depth + 1);
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