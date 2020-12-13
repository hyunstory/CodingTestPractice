#include <iostream>

using namespace std;
#define map_max 20 + 1


int n, m, x, y, k;
int map[map_max][map_max];

typedef struct dice {
	int value = 0;

}Dice;

Dice dice[7];

int dx[] = { 0, 0, -1, 1 };
int dy[] = { 1, -1, 0, 0 };
int cur_x;
int cur_y;

int turnDice(int dir) {
	dir -= 1;
	cur_x += dx[dir];
	cur_y += dy[dir];

	if (!(cur_x >= 0 && cur_x < n && cur_y >= 0 && cur_y < m)) {
		
		cur_x -= dx[dir];
		cur_y -= dy[dir];
		return -1; //바깥으로 벗어나면 무시.
	}


	int temp;

	dir += 1;
	switch (dir)
	{

	case 1: // 동

		//이동
		temp = dice[3].value;
		dice[3].value = dice[6].value;
		dice[6].value = dice[4].value;
		dice[4].value = dice[1].value;
		dice[1].value = temp;

		break;

	case 2: // 서

		temp = dice[3].value;

		dice[3].value = dice[1].value;
		dice[1].value = dice[4].value;
		dice[4].value = dice[6].value;
		dice[6].value = temp;

		break;

	case 3: // 북
		temp = dice[1].value;
		dice[1].value = dice[2].value;
		dice[2].value = dice[6].value;
		dice[6].value = dice[5].value;
		dice[5].value = temp;
		

		break;

	case 4: // 남
		temp = dice[1].value;
		dice[1].value = dice[5].value;
		dice[5].value = dice[6].value;
		dice[6].value = dice[2].value;
		dice[2].value = temp;

		break;

	default:
		break;
	}


	if (map[cur_x][cur_y] == 0) {
		
		map[cur_x][cur_y] = dice[1].value;
		
		
	}

	else {
		dice[1].value = map[cur_x][cur_y];
		map[cur_x][cur_y] = 0;
	}

	return dice[6].value;

}

void solution() {

	cin >> n >> m >> x >> y >> k;
	cur_x = x;
	cur_y = y;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) cin >> map[i][j];

	for (int i = 0; i < k; i++) {
		int cmd, result;
		cin >> cmd;

		result = turnDice(cmd);

		if( result != -1) cout << result << '\n';

	}


}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();


	return 0;
}