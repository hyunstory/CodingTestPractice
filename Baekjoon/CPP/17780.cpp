#include <iostream>
#include <deque>

using namespace std;

#define map_max 12 + 1
#define k_max 10 + 1

int n, k;
int dx[] = { 0, 0, 0, -1, 1 };
int dy[] = { 0, 1, -1, 0, 0 };

int map[map_max][map_max]; // 0은 흰색, 1은 빨간색, 2는 파란색
deque<int> horse_map[map_max][map_max]; // 말번호

int result = -1;

struct Horse {
	int x;
	int y;
	int dir;
};

Horse horse[k_max];

bool check() {


	for (int i = 1; i <= k; i++) {
		int x = horse[i].x, y = horse[i].y;
		if (horse_map[x][y].size() >= 4) {
			return true;
		}
	}

	return false;
}

int opposite_dir(int dir) {
	int tdir = dir % 2 == 1 ? dir + 1 : dir - 1;

	

	return tdir;
	
}


void move(int j, int x, int y, int dir, int count) {

	// 여기에 로직 입력

	if (count == 2) return;
	if (horse_map[x][y][0] != j) return;

	int nx = x + dx[dir];
	int ny = y + dy[dir];

	

	if (!(nx > 0 && nx <= n && ny > 0 && ny <= n)) {
		//밖으로 나갔을 때

		int tdir = opposite_dir(dir);

		horse[j].dir = tdir;
		move(j, x, y, horse[j].dir, count + 1);


	}

	else if (map[nx][ny] == 0) {
		// 흰색 일 때

		horse[j].dir = dir;

		for (int k = 0; k < horse_map[x][y].size(); k++) {
			int tnum = horse_map[x][y][k];

			horse[tnum].x = nx;
			horse[tnum].y = ny;


			horse_map[nx][ny].push_back(tnum);
		}




		horse_map[x][y].clear();


	}
	else if (map[nx][ny] == 1) {
		// 빨간색 일 때
		horse[j].dir = dir;

		for (int k = horse_map[x][y].size() - 1; k >= 0; k--) {
			int tnum = horse_map[x][y][k];


			horse[tnum].x = nx;
			horse[tnum].y = ny;

			horse_map[nx][ny].push_back(tnum);
		}


		horse_map[x][y].clear();

	}

	else if (map[nx][ny] == 2) {
		// 파란색 일 때

		int tdir = opposite_dir(dir);

		horse[j].dir = tdir;
		move(j, x, y, horse[j].dir, count + 1);



	}




}

void solution() {


	cin >> n >> k;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			cin >> map[i][j];
		}

	for (int i = 1; i <= k; i++) {
		int x, y, dir;

		cin >> x >> y >> dir;

		horse[i].x = x;
		horse[i].y = y;
		horse[i].dir = dir;

		horse_map[x][y].push_back(i);
	}


	//input 끝



	
	result = 0;
	while(1){


		if (check()) {


			break;
		}

		result++;

		if (result > 1000) {
			result = -1;
			break;
		}
		for (int j = 1; j <= k; j++) {



			int x = horse[j].x;
			int y = horse[j].y;
			int dir = horse[j].dir;

			move(j, x, y, dir, 0);


		}
		
	}




	cout << result << '\n';





}

int main() {

	solution();


	return 0;
}
