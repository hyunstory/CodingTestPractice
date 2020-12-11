#include <iostream>
#include <deque>

using namespace std;

#define input_max 500 + 1

int n, m;
char map_c[input_max][input_max];
int map_status[input_max][input_max]; // 0은 모름 unkown, 1은 가능, 2는 불가능, 3은 갔던 길

int dx[] = { -1, 0, 1, 0 }; // 상우하좌
int dy[] = { 0, 1, 0, -1 };

int result;

void solution() {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			cin >> map_c[i][j];
		}

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			int x = i;
			int y = j;

			deque<pair<int, int>> dq;

			bool impos_FLAG = false;

			while (0 <= x && x < n && 0 <= y && y < m) {

				if (map_status[x][y] == 1) break; 
				else if (map_status[x][y] == 2 || map_status[x][y] == 3) {
					impos_FLAG = true;
					break;
				}

			
				char temp = map_c[x][y];

				dq.push_back(make_pair(x, y));
				map_status[x][y] = 3;

				if (temp == 'U') {

					x = x + dx[0];
					y = y + dy[0];
					

				}

				else if (temp == 'R') {
					x = x + dx[1];
					y = y + dy[1];
				}

				else if (temp == 'D') {
					x = x + dx[2];
					y = y + dy[2];

				}

				else if (temp == 'L') {
					x = x + dx[3];
					y = y + dy[3];

				}



			
			}

			if (!impos_FLAG) {

				while (!dq.empty()) {

					int dq_x = dq.back().first;
					int dq_y = dq.back().second;

					map_status[dq_x][dq_y] = 1;
					dq.pop_back();
				}

				result++;
			}


		}


	cout << result << '\n';
}


int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();


	return 0;
}