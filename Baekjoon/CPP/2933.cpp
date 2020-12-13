#include <iostream>
#include <queue>
#include <deque>
#include <cstring>
#include <algorithm>

#define INF 999999999

using namespace std;

int r, c;

char map[101][101];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };  // 0은 오른쪽 방향, 1은 왼쪽 방향
bool check[101][101];
bool is_cluster[101][101];
int n;

deque<pair<int, int>> air;
deque<int> cmd;

void bfs(int x, int y) {

	queue<pair<int, int>> q;

	q.push(make_pair(x, y));
	check[x][y] = true;

	while (!q.empty()) {
	
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < r && ny >= 0 && ny < c && !check[nx][ny] && map[nx][ny] == 'x') {
				check[nx][ny] = true;

				q.push(make_pair(nx, ny));

			}
		}
	}

}
bool investigate() {

	for (int i = 0; i < c; i++)
		if (map[r - 1][i] == 'x' && !check[r - 1][i]) bfs(r - 1, i);



	bool flag = false;

	memset(is_cluster, false, sizeof(is_cluster));

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++) {
			if (map[i][j] == 'x' && !check[i][j]) {
				flag = true;
				
				air.push_back(make_pair(i, j));
				is_cluster[i][j] = true;
				
				
			}
		}
	
	return flag;
}

bool simul(int r, bool is_left) {

	
	if (is_left) {
		for (int i = 0; i < c; i++) {
			if (map[r][i] == 'x') {
				map[r][i] = '.';
				return true;
			}
		}
	}

	else {
		for (int i = c - 1; i >= 0; i--) {
			if (map[r][i] == 'x') {
				map[r][i] = '.';
				return true;
			}
		}
	}

	return false;
}

int falldown(int x, int y) {

	int cnt = 0;

	for (int i = x + 1; i < r; i++) {
		if (map[i][y] == 'x') {
			if (is_cluster[i][y]) return INF;
			else return cnt;
		}
		else if (map[i][y] == '.') cnt++;
	}
		
	return cnt;
}

void reconstruct() {

	int r = INF - 1;

	for (int i = 0; i < air.size(); i++) {
		int x = air[i].first;
		int y = air[i].second;

		int tmp = falldown(x, y);

		if (tmp == INF) continue;

		else r = min(r, tmp);
	}

	sort(air.begin(), air.end(), greater<pair<int, int>>());

	for (int i = 0; i < air.size(); i++) {
		int x = air[i].first;
		int y = air[i].second;

		map[x][y] = '.';
		map[x + r][y] = 'x';
	}

}

void solution() {
	
	cin >> r >> c;

	for (int i = 0; i < r; i++)
		for (int j = 0; j < c; j++)
			cin >> map[i][j];

	cin >> n;

	

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		cmd.push_back(temp);
	}
	bool is_left = true;

	for (int i = 0; i < cmd.size(); i++) {

		memset(check, false, sizeof(check));
		memset(is_cluster, false, sizeof(is_cluster));
		air.clear();

		
		int value = cmd[i];
		
		if (i % 2 == 0) is_left = true;
		else is_left = false;

		int row = r - value;

		
		
		if (!(simul(row, is_left))) continue;

		if (!(investigate())) continue;
		else reconstruct();

	}
	

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cout << map[i][j];
		}
		cout << '\n';
	}

}

int main() {

	solution();

	return 0;
}