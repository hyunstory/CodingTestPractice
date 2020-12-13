#include<iostream>
#include<vector>
using namespace std;

#define MAX 12
#define chess_max 10

struct chess {
	int x;
	int y;
	int dir;

};

int n, k, result;

int map[MAX][MAX];
vector<int> map_state[MAX][MAX];

chess Chess[chess_max];

int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };


int find_delete_num(int x, int y, int chess_num) {


	int cnt = 0;
	int size = map_state[x][y].size();

	for (int i = size - 1; i >= 0; i--) {
	
	
		if (map_state[x][y][i] == chess_num) break;

		cnt++;
	}

	return cnt + 1;
}

int toggle_dir(int n) {

	int dir = Chess[n].dir;
	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else if (dir == 4) return 3;


}

void moveChess(int x, int y, int nx, int ny, int chess_num, int pos, int color) {

	int size = map_state[x][y].size();
	if (color == 0) {
	
		for (int i = pos; i < size; i++) {
		
			map_state[nx][ny].push_back(map_state[x][y][i]);
			int idx = map_state[x][y][i];
			Chess[idx].x = nx;
			Chess[idx].y = ny;

		
		}

		int delete_num = find_delete_num(x, y, chess_num);
		for (int i = 0; i < delete_num; i++) map_state[x][y].pop_back();
	}

	else if (color == 1) {

		for (int i = size - 1; i >= pos; i--) {

			map_state[nx][ny].push_back(map_state[x][y][i]);
			int idx = map_state[x][y][i];
			Chess[idx].x = nx;
			Chess[idx].y = ny;


		}

		int delete_num = find_delete_num(x, y, chess_num);
		for (int i = 0; i < delete_num; i++) map_state[x][y].pop_back();

		
	
	}

	else if (color == 2) {


		int dir = toggle_dir(chess_num);
		Chess[chess_num].dir = dir;

		int nnx = x + dx[dir];
		int nny = y + dy[dir];

		if (nnx >= 0 && nny >= 0 && nnx < n && nny < n) {
		
			if (map[nnx][nny] != 2) moveChess(x, y, nnx, nny, chess_num, pos, map[nnx][nny]);
		}
	
	

	}

}

int find_position(int x, int y, int idx) {
	int size = map_state[x][y].size();


	for (int i = 0; i < size; i++) {
	
		if (map_state[x][y][i] == idx) return i;
	}
}

bool check_state() {

	for (int i = 0; i < k; i++) {
	
		int x = Chess[i].x;
		int y = Chess[i].y;
		if (map_state[x][y].size() >= 4) return true;
	}

	return false;
}


void solve() {


	bool flag = false;
	int cnt = 1;
	while (1) {
	
		if (cnt > 1000) break;

		for (int i = 0; i < k; i++) {

			int x = Chess[i].x;
			int y = Chess[i].y;
			int dir = Chess[i].dir;

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			int pos = find_position(x, y, i);
			
			if (nx >= 0 && ny >= 0 && nx < n&&ny < n) moveChess(x, y, nx, ny, i, pos, map[nx][ny]);
			else moveChess(x, y, nx, ny, i, pos, 2);



			if (check_state() == true) {
				flag = true;
				break;
			}
		

		
		}
	
		if (flag == true) break;
		cnt++;
	}

	if (flag == true) cout << cnt << '\n';
	else cout << -1 << '\n';
}





int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> k;


	for(int i = 0;i < n; i++)
		for (int j = 0; j < n; j++) {
		
			cin >> map[i][j];

		}

	for (int i = 0; i < k; i++) {
	
		int x, y, d; cin >> x >> y >> d;
		x--; y--;
		Chess[i] = { x,y,d };
		map_state[x][y].push_back(i);


	}
	solve();


	



	


	return 0;
}