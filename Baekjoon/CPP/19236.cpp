#include <iostream>
#include <algorithm>

using namespace std;

#define input_max 4

int dx[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };
int dy[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1, };


struct Fish {
	int x;
	int y;
	int dir;
	bool alive;
};


int result;
int map[input_max][input_max];

Fish fish[20 + 1];

void swap_fish(int a, int b) {
	Fish t = fish[a];
	fish[a].x = fish[b].x;
	fish[a].y = fish[b].y;
	fish[b].x = t.x;
	fish[b].y = t.y;

}

void change(int x, int y, int nx, int ny, int num, bool ok) {
	if (ok) {
		map[x][y] = 0;
		map[nx][ny] = -1;
		fish[num].alive = false;
	}
	else {

		map[x][y] = -1;
		map[nx][ny] = num;
		fish[num].alive = true;
	}
}

void copy_status(int input[][4], int output[][4], Fish in[], Fish out[]) {

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) output[i][j] = input[i][j];

	for (int i = 1; i <= 16; i++) out[i] = in[i];
}

void move_fish() {
	for (int i = 1; i <= 16; i++) {


		if (!fish[i].alive) continue;

		int x = fish[i].x;
		int y = fish[i].y;
		int dir = fish[i].dir;

		int nx = x + dx[dir];
		int ny = y + dy[dir];
		bool flag = false;

		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {

			if (map[nx][ny] == 0) {
				flag = true;
				fish[i].x = nx;
				fish[i].y = ny;
				map[nx][ny] = i;
				map[x][y] = 0;
			}
			else if (map[nx][ny] != -1) {
				flag = true;
				//물고기 바꾸기
				swap_fish(i, map[nx][ny]);
			

				//맵도 바꾸기
				swap(map[x][y], map[nx][ny]);
			}
			
		}




		if (!flag) {
			int ndir = dir + 1;
			if (ndir == 9) ndir = 1;
			int nx = x + dx[ndir];
			int ny = y + dy[ndir];

			while (ndir != dir) {


				if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {
					if (map[nx][ny] == 0) {
						
						fish[i].x = nx;
						fish[i].y = ny;
						map[nx][ny] = i;
						map[x][y] = 0;
						fish[i].dir = ndir;
						break;
					}
					else if (map[nx][ny] != -1) {
				
						//물고기 바꾸기
						swap_fish(i, map[nx][ny]);


						//맵도 바꾸기
						swap(map[x][y], map[nx][ny]);
						fish[i].dir = ndir;
						break;
					}
				}







				ndir++;
				if (ndir == 9) ndir = 1;
				nx = x + dx[ndir];
				ny = y + dy[ndir];
			}
		}
	}
}

void dfs(int x, int y, int dir, int sum) {

	result = max(result, sum);


	int copy_map[4][4];
	Fish copy_fish[20];

	copy_status(map, copy_map, fish, copy_fish);

	//물고기 움직이기


	move_fish();

	//상어 움직이기


	for (int i = 1; i <= 3; i++) {
		int nx = x + dx[dir] * i;
		int ny = y + dy[dir] * i;

		if (nx >= 0 && nx < 4 && ny >= 0 && ny < 4) {

			if (map[nx][ny] == 0) continue;

			int num = map[nx][ny];
			int ndir = fish[num].dir;

			//만들고
			change(x, y, nx, ny, num, true);
			//dfs
			dfs(nx, ny, ndir, sum + num);

			
			//끄고

			change(x, y, nx, ny, num, false);
		}

		else break;

		
	}
	

	copy_status(copy_map, map, copy_fish, fish);

	//다시 되돌려 놓기

}

void solution() {

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++) {
			int a, b;
			cin >> a >> b;

			map[i][j] = a;

			fish[a] = { i, j, b, true };

		}

	int num = map[0][0];
	int dir = fish[num].dir;
	fish[num].alive = false;
	map[0][0] = -1;

	dfs(0, 0, dir, num);
	



	cout << result << '\n';
}

int main() {


	solution();

	return 0;
}