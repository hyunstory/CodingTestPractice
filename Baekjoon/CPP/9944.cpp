#include <iostream>


using namespace std;

#define input_max 32 + 1
int n, m;
int total_blank;

int t_case = 1;
char a[input_max][input_max];



int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

int check(int x, int y) {
	return 0 <= x && x < n && 0 <= y && y < m;
}
int dfs(int x, int y, int cnt) {

	int result = -1;
	if (cnt == 0) {
		return 0;
	}

	for (int k = 0; k < 4; k++) {
		int nx = x + dx[k];
		int ny = y + dy[k];

		while (check(nx, ny) && a[nx][ny] == '.') {
			a[nx][ny] = '#';
			cnt -= 1;
			nx += dx[k];
			ny += dy[k];
		}

		nx -= dx[k];
		ny -= dy[k];

		if (!(x == nx && y == ny)) {
			int temp = dfs(nx, ny, cnt);

			if (temp != -1) {
				if (result == -1 || result > temp + 1) {
					result = temp + 1;

				}
			}
			
		}
		while (!(x == nx && y == ny)) {
			a[nx][ny] = '.';
			cnt += 1;
			nx -= dx[k];
			ny -= dy[k];
		}
		
	}
	return result;
}




void solution() {

	while (cin >> n >> m) {
		
		total_blank = 0;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
			for (int j = 0; j < m; j++) {

				if (a[i][j] == '.') {
					total_blank++;
				}

			}

		}
		int result = -1;

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == '.') {
					a[i][j] = '#';

					int s = dfs(i, j, total_blank - 1);

					if (s != -1) {
						if (result == -1 || result > s) {
							result = s;
						}
						
					}
					a[i][j] = '.';
				}
			}
		}


		
		cout << "Case "<< t_case << ": " << result << '\n';
		t_case++;
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}