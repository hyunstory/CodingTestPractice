#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>


using namespace std;

enum{
	MAX = 101,
	dir = 4
};


int naming = -1;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };


int N;
int island[MAX][MAX];
int result = 100000000;
int count_path[MAX][MAX];
bool check[MAX][MAX];

void input() {

	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

			cin >> island[i][j];

		}





}

bool isNeighborZero(int x, int y) {

	for (int i = 0; i < dir; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 <= nx && nx < N && 0 <= ny && ny < N && island[nx][ny] == 0)
			return true;

	
	}

	return false;


}


void solution() {


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			if (island[i][j] == 1) {

				queue<pair<int, int>> q;

				island[i][j] = naming;
				
				q.push(make_pair(i, j));

				while (!q.empty()) {
				
					int x = q.front().first;
					int y = q.front().second;
					q.pop();

					for (int k = 0; k < dir; k++) {
					
						int nx = x + dx[k];
						int ny = y + dy[k];

						if (0 <= nx && nx < N && 0 <= ny && ny < N && island[nx][ny] == 1) {

							island[nx][ny] = naming;
							q.push(make_pair(nx, ny));

						}
					}
				}

				naming--;
			}
			


			if ( isNeighborZero(i, j) && island[i][j] < 0) {

				queue<pair<int, int>> q;

				q.push(make_pair(i, j));


				int myregion = island[i][j];

				while (!q.empty()) {

					int x = q.front().first;
					int y = q.front().second;
					q.pop();


					
					for (int k = 0; k < dir; k++) {
						int nx = x + dx[k];
						int ny = y + dy[k];
						if (0 <= nx && nx < N && 0 <= ny && ny < N) {
							if (island[nx][ny] == 0 && !check[nx][ny]) {
								q.push(make_pair(nx, ny));
								count_path[nx][ny] = count_path[x][y] + 1;
								check[nx][ny] = true;


							}
							if (island[nx][ny] != myregion && island[nx][ny] != 0) {
								result = min(result, count_path[x][y]);
							}
						}
					}
				}

				memset(count_path, 0, sizeof(count_path));
				memset(check, false, sizeof(check));

			}

			


		}


	cout << result << '\n';


}

void solve() {

	input();
	solution();
}
int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);

	solve();


	return 0;

}