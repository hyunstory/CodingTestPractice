#include <iostream>
#include <algorithm>
#include <queue>
#include <deque>
#include <cstring>
#include <string>

using namespace std;

const int MAX = 1001;

int t, n, m;

char map[MAX][MAX];
bool visit[MAX][MAX];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

deque<pair<int, int>> fire;
int bfs(int start_x, int start_y) {

	memset(visit, false, sizeof(visit));


	queue<pair<int, int>> q;
	q.push({ start_x, start_y });

	visit[start_x][start_y] = true;


	int result = 1;

	while (!q.empty()) {
		int fire_size = fire.size();

		for (int i = 0; i < fire_size; i++) {
			int x = fire.front().first;
			int y = fire.front().second;

			fire.pop_front();

			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;

				if (map[nx][ny] == '.') {
					fire.push_back({ nx, ny });
					map[nx][ny] = '*';
				}
			}
		}



		int q_size = q.size();

		for (int i = 0; i < q_size; i++) {
			int x = q.front().first;
			int y = q.front().second;
			q.pop();


			for (int k = 0; k < 4; k++) {
				int nx = x + dx[k];
				int ny = y + dy[k];

				if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
					return result;
				}
				else if (visit[nx][ny] || map[nx][ny] == '#' || map[nx][ny] == '*') continue;

				visit[nx][ny] = true;
				q.push({ nx, ny });

			}
		}

		result++;

	}

	return -1;
}

void solution() {
	cin >> t;
	int start_x, start_y;

	while (t--) {
		cin >> m >> n;

		for (int i = 0; i < n; i++) {
			string s;
			cin >> s;
			for (int j = 0; j < m; j++) {
				map[i][j] = s[j];
				if (map[i][j] == '@') {
					start_x = i;
					start_y = j;
				}
				else if (map[i][j] == '*') {
					fire.push_back({ i, j });
				}
			}
		}

		int res = bfs(start_x, start_y);



		if (res == -1) cout << "IMPOSSIBLE" << '\n';
		else cout << res << '\n';

		fire.clear();

	}

}
int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}