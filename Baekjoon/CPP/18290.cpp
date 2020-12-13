#include <iostream>
#include <algorithm>

using namespace std;
#define MAX 10 +1
#define KMAX 100 + 1

int n, m, k;
int a[MAX][MAX];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

bool check[MAX][MAX];

int result = -1000000000;




void go(int start_x, int start_y, int sum, int depth) {


	if (depth == k) {

		result = max(result, sum);


		return;
	}


	for (int i = start_x; i < n; i++)
		for (int j = 0; j < m; j++) {

			if (check[i][j]) continue;

			bool FLAG_adj = true;

			for (int k = 0; k < 4; k++) {
				int x = i + dx[k];
				int y = j + dy[k];

				if (0 <= x && x < n && 0 <= y && y < m) {
					if (check[x][y]) FLAG_adj = false;
				}
			}

			if (FLAG_adj) {
				check[i][j] = true;
				go(i, j, sum + a[i][j], depth + 1);
				check[i][j] = false;
			}

		}
}

void solution() {




	cin >> n >> m >> k;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			cin >> a[i][j];
		}


	go(0, 0, 0, 0);
	cout << result << '\n';
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}