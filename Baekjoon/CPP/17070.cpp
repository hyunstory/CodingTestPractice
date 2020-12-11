#include <iostream>

using namespace std;

#define input_max 16 + 1
int n;

int a[input_max][input_max];

int dx[] = { 0, 1, 1 }; // 가로 대각선 세로 순
int dy[] = { 1, 1, 0 }; // 가로 대각선 세로 순
int result;

bool ok(int x, int y, int dir) {

	if (dir == 0) { //진행하려는 방향이 가로일 때 가능한 공간 체크
		
		for (int k = 0; k < 1; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (!(nx > 0 && nx <= n && ny > 0 && ny <= n && a[nx][ny] == 0)) {
				return false;
			}
		}

	}

	else if (dir == 1) { //진행하려는 방향이 대각선일 때 가능한 공간 체크
		for (int k = 0; k < 3; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (!(nx > 0 && nx <= n && ny > 0 && ny <= n && a[nx][ny] == 0)) {
				return false;
			}
		}

	}

	else if (dir == 2) { //진행하려는 방향이 세로일 때 가능한 공간 체크
		for (int k = 2; k < 3; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (!(nx > 0 && nx <= n && ny > 0 && ny <= n && a[nx][ny] == 0)) {
				return false;
			}
		}

	}

	return true;

}

void dfs(int x, int y, int dir) {
	 
	if (x == n && y == n) { // N x N 에 도착했을 때 카운트 1추가
		result++;

		return;
		
	}


	
	if (dir == 0) { //진행중인 방향이 가로일 때

		for (int k = 0; k < 2; k++) {
			if (ok(x, y, k)) {
				dfs(x + dx[k], y + dy[k], k);

			}
		}

	}
	else if (dir == 1) { //진행중인 방향이 대각선일 때

		for (int k = 0; k < 3; k++) {
			if (ok(x, y, k)) {
				dfs(x + dx[k], y + dy[k], k);

			}

		}

	}
	else if (dir == 2) { //진행중인 방향이 세로일 때
		for (int k = 1; k < 3; k++) {
			if (ok(x, y, k)) {
				dfs(x + dx[k], y + dy[k], k);

			}

		}

		
	}
	
}
void solution() {

	cin >> n;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i + 1][j + 1];
		}

	dfs(1, 2, 0); // 1, 2 좌표에서 시작! 방향은 가로 즉, dir = 0


	cout << result << '\n';

}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solution();


	return 0;
}