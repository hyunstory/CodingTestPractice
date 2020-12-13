#include<iostream>
#include<algorithm>
using namespace std;
#define north 0
#define east 1
#define south 2
#define west 3


int house[50][50];
int visit[50][50];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int n, m;
int dir;
int room = 1;

int start_x, start_y;

int change_dir(int dir) {
	if (dir == 0) return 3;
	else if (dir == 1)return 0;
	else if (dir == 2)return 1;
	else if (dir == 3)return 2;

}


void solve() {
	int x = start_x;
	int y = start_y;

	

	int nx, ny, nd;

	while (1) {
	
		int Tmp_d = dir;
		bool Can_Clean = false;
		int CanNotClean = 0;

		for (int i = 0; i < 4; i++) {
		
			nd = change_dir(dir);
			nx = x + dx[nd];
			ny = y + dy[nd];

			if (house[nx][ny] == 0) {
				Can_Clean = true;
				break;
			}
			else if (house[nx][ny] == 1 || house[nx][ny] == 2 || (nx < 0 || ny < 0 || nx >= n || ny >= m)) {
				dir = nd;
				CanNotClean++;
			}

		}

		if (Can_Clean == true) {
			house[nx][ny] = 2;
			room++;
			dir = nd;
		}

		if (CanNotClean == 4) {

			nx = x - dx[Tmp_d];
			ny = y - dy[Tmp_d];
			dir = Tmp_d;
			if ((nx < 0 || ny < 0 || nx >= n || ny >= m) || house[nx][ny] == 1) { break; }

		}
		x = nx;
		y = ny;

	}

	cout << room << '\n';

}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> n >> m;

	cin >> start_x >> start_y >> dir;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
		
			cin >> house[i][j];
		}
	}
	
	house[start_x][start_y] = 2;

	solve();
	

	



	return 0;
}

