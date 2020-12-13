#include <iostream>
#include <deque>

using namespace std;


int n, k, l;

int map[101][101];
bool check[101][101];

int dx[] = { 0, 1, 0, -1 }; //우하좌상
int dy[] = { 1, 0, -1, 0 };

void solution() {

	deque<pair<int, char>> cmds;
	deque<pair<int, int>> snake;
	int dir = 0;


	cin >> n;

	cin >> k;

	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;

		map[x][y] = 1;
	}

	cin >> l;

	for (int i = 0; i < l; i++) {
		int temp;
		char cmd;
		cin >> temp >> cmd;

		cmds.push_back(make_pair(temp, cmd));

	}

	int result = 0;

	check[1][1] = true;

	snake.push_front(make_pair(1, 1));



	while (1) {

		result++;
		//우하좌상
		int nx = snake.front().first + dx[dir];
		int ny = snake.front().second + dy[dir];

		if (check[nx][ny] || !(nx >= 1 && nx <= n && ny >= 1 && ny <= n)) {


			cout << result << '\n';


			break;
		}
		check[nx][ny] = true;
		snake.push_front(make_pair(nx, ny));

		if (map[nx][ny] == 1) {
			map[nx][ny] = 0;
		}

		else {

			
			check[snake.back().first][snake.back().second] = false;
			snake.pop_back();
			
		}
	

		if (!cmds.empty() && cmds.front().first == result) {

			if (cmds.front().second == 'L') {
				dir = (dir + 3) % 4;

			}

			else dir = (dir + 1) % 4;



			cmds.pop_front();

		}



	}

}
int main() {


	solution();

	return 0;
}