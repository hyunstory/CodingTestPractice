#include <iostream>
#include <queue>
#include<algorithm>

using namespace std;

int building[8][8];
int tmpbuild[8][8];
int n, m;
int result = 0;

int dx[] = {0, 0, -1, 1};  //좌우 상하 arr[x][y]
int dy[] = {-1, 1, 0, 0};  //좌우 상하 arr[x][y]

void mapCopy(int a[][8], int b[][8]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			a[i][j] = b[i][j];
		}
	}
}

void virusSpread() {
	//spreadbuild는 3개의 벽의로 막은 후 바이러스가 퍼졌을 때의 연구소의 상황을 저장하는 곳.
	int spreadbuild[8][8];
	mapCopy(spreadbuild, tmpbuild);
	queue<pair<int, int>> q;
	for (int i = 0; i < n; i++) 
		for (int j = 0; j < m; j++) 
			if (spreadbuild[i][j] == 2) 
				q.push(make_pair(i, j));
			
		
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
		
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (spreadbuild[nx][ny] == 0) {
					spreadbuild[nx][ny] = 2;
					q.push(make_pair(nx, ny));
				}
			}
		}




	}

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (spreadbuild[i][j] == 0) {
				cnt++;
			}
		}
	}
	
	result = max(result, cnt);
}

void wall(int cnt) {
	
	if (cnt == 3) {
		virusSpread();
		return;

	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tmpbuild[i][j] == 0) {
				tmpbuild[i][j] = 1;
				wall(cnt + 1);

				//모든 경우의 수를 넣어야 함으로 기존의 1을 0으로 바꾸어주는 역할

				tmpbuild[i][j] = 0;
			}
		}
	}
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> building[i][j];

			
		}
	}

	






	//0인부분을 모두 벽을 세워본다.

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (building[i][j] == 0) {
				mapCopy(tmpbuild, building);
				tmpbuild[i][j] = 1;
				wall(1);
				tmpbuild[i][j] = 0;
				
			}
		}
	}


	cout << result << '\n';
	


	return 0;
}