#include <iostream>
#include <cstring>


using namespace std;


enum {

	MAX = 51
};

int T, N, R;

int raiser_x;
int raiser_y;

bool mirror[MAX][MAX];
short dir;

int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };

bool inSpace(int x, int y) {

	if (1 <= x && x <= N && 1 <= y && y <= N)return true;
	else return false;


}

void solution() {



	if (raiser_y == 0) dir = 0;
	else if (raiser_x == 0) dir = 1;
	else if (raiser_y == N + 1) dir = 2;
	else if (raiser_x == N + 1) dir = 3;

	int cur_x = raiser_x + dx[dir];
	int cur_y = raiser_y + dy[dir];




	while (inSpace(cur_x, cur_y)) {

		if (mirror[cur_x][cur_y]) {
			dir++;
			dir %= 4;
		}

		cur_x += dx[dir];
		cur_y += dy[dir];


	}

	cout << cur_x << ' ' << cur_y << '\n';




}




void input() {

	cin >> T;

	int rx, ry;

	for (int i = 0; i < T; i++) {

		cin >> N >> R;


		for (int j = 0; j < R; j++) {
			
			cin >> rx >> ry;

			mirror[rx][ry] = true;
			
		}

		cin >> raiser_x >> raiser_y;

		solution();

		memset(mirror, false, sizeof(mirror));
		

	}

	
	



}




void solve() {

	input();
	
	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solve();





	return 0;
}