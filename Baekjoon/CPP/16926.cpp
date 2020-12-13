#include <iostream>

using namespace std;
#define input_max 300 + 1

int n, m, r, rotate_p;
int map[input_max][input_max];
int check[input_max][input_max];
int changed[input_max][input_max];


void dfs(int x, int y, int dir, int R, int Range, int Orig) {

	if (r == R) {
		changed[x][y] = Orig;
		return;
	}


	if (dir == 0) {
		if (y + 1 < m - Range) dfs(x, y + 1, dir, R + 1, Range, Orig);
		else dfs(x - 1, y, 3, R + 1, Range, Orig);
	}

	else if (dir == 1) {
		if (y - 1 >= Range) dfs(x, y - 1, dir, R + 1, Range, Orig);
		else dfs(x + 1, y, 2, R + 1, Range, Orig);

	}

	else if (dir == 2) {
		if (x + 1 < n - Range) dfs(x + 1, y, dir, R + 1, Range, Orig);
		else dfs(x, y + 1, 0, R + 1, Range, Orig);


	}
	else if (dir == 3) {
		if (x - 1 >= Range) dfs(x - 1, y, dir, R + 1, Range, Orig);
		else dfs(x, y - 1, 1, R + 1, Range, Orig);

	}

}

void solution() {


	cin >> n >> m >> r;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> map[i][j];
			





	if (n > m) rotate_p = m / 2;
	else rotate_p = n / 2;

	for (int i = 0; i < rotate_p; i++) {

		int x = i;
		int y = i;

		for (int j = x; j < n - i; j++) {

			if (!check[j][y]) {

				dfs(j, y, 2, 0, i, map[j][y]);
				check[j][y] = true;
			}

		}

		for (int j = y; j < m - i; j++) {
			if (!check[n - 1 - i][j]) {
				dfs(n - 1 - i, j, 0, 0, i, map[n - 1 - i][j]);
				check[n - 1 - i][j] = true;
			}

		}

		for (int j = n - 1 - i; j >= i; j--) {
			if (!check[j][m - 1 - i]) {
				dfs(j, m - 1 - i, 3, 0, i, map[j][m - 1 - i]);
				check[j][m - 1 - i] = true;
			}

		}

		for (int j = m - 1 - i; j >= i; j--) {
			if (!check[x][j]) {
				dfs(x, j, 1, 0, i, map[x][j]);
				check[x][j] = true;
			}
		}



	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << changed[i][j] << ' ';
		}
		cout << '\n';
	}


}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}