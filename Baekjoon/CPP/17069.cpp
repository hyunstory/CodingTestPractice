#include <iostream>
#include <cstring>

using namespace std;

#define input_max 32 + 1  //입력의 최대값
#define dir_max 3         // 방향은 총 3가지 가로 대각선 세로
int n;

int a[input_max][input_max];

int dx[] = { 0, 1, 1 };
int dy[] = { 1, 1, 0 };

long long d[input_max][input_max][dir_max];  //DP 배열 선언

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

long long dfs(int x, int y, int dir) {
	 
	if (x == n && y == n) {
		

		return 1; //반환하면서 카운트를 계산
		
	}

	long long &result = d[x][y][dir];  // x,y, dir방향에서 N,N까지 가는 모든 방법의 수를 대입

	if (result != -1) return result;   //만약에 방법의 수가 대입이 되어있다면 중복계산할 필요가 없음.

	result = 0;                        // d[x][y][dir] 값이 -1 즉, 아직 구하지 않았다면 0부터 다시 계산함.

	
	if (dir == 0) { //진행중인 방향이 가로일 때

		for (int k = 0; k < 2; k++) {
			if (ok(x, y, k)) {
				result += dfs(x + dx[k], y + dy[k], k);

			}
		}

	}
	else if (dir == 1) { //진행중인 방향이 대각선일 때

		for (int k = 0; k < 3; k++) {
			if (ok(x, y, k)) {
				result += dfs(x + dx[k], y + dy[k], k);

			}

		}

	}
	else if (dir == 2) { //진행중인 방향이 세로일 때
		for (int k = 1; k < 3; k++) {
			if (ok(x, y, k)) {
				result += dfs(x + dx[k], y + dy[k], k);

			}
			
		}

		
	}

	return result;
	
}
void solution() {

	cin >> n;
	
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> a[i + 1][j + 1];
		}

	
	
	memset(d, -1, sizeof(d));           //초기값 -1 설정, -1은 아직 계산 안한 배열

	cout << dfs(1, 2, 0) << '\n';       // 1, 2부터 시작

}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solution();


	return 0;
}