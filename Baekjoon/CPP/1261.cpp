#include <iostream>
#include <algorithm>
#include <queue>
#include <cstring>

using namespace std;

#define input_max 100 + 1
void solution() {

	int n, m; // n은 가로, m은 세로

	int map[input_max][input_max];
	memset(map, 0, sizeof(map));
	int count[input_max][input_max];
	//memset(count, 1000000000, sizeof(count));
	int dx[] = { -1, 1, 0, 0 };
	int dy[] = { 0, 0, -1, 1 };


	cin >> n >> m;


	for (int i = 1; i <= m; i++)
		for (int j = 1; j <= n; j++) {
			scanf("%1d", &map[i][j]);
			count[i][j] = 1000000000;
		}
	queue<pair<int, int>> q;

	q.push(make_pair(1, 1));
	count[1][1] = 0;

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		
		q.pop();


		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			

			if (nx >= 1 && nx <= m && ny >= 1 && ny <= n) {

				if (map[nx][ny] == 1) {

					if (count[nx][ny] > count[x][y] + 1) {
						count[nx][ny] = count[x][y] + 1;
						q.push(make_pair(nx, ny));
					}
				}

				else if (map[nx][ny] == 0) {
					if (count[nx][ny] > count[x][y]) {
						count[nx][ny] = count[x][y];
						q.push(make_pair(nx, ny));
					}
				}


				

				
			}


		}
	}

	cout << count[m][n] << '\n';

}
int main() {



	solution();


	return 0;
}