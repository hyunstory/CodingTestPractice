#include <iostream>
#include <vector>



using namespace std;

int x, y, d, g, sx, sy;

bool map[110][110] = {false};

int dx[] = { 0, -1, 0, 1 };
int dy[] = { 1, 0, -1 ,0 };

vector<int> dir_info;

int n;


void make_curve() {


	int s = dir_info.size();
	for (int i = s - 1; i >= 0; i--) {

		int nd = (dir_info[i] + 1) % 4;
		x = x + dx[nd];
		y = y + dy[nd];
		map[x][y] = true;

		dir_info.push_back(nd);

	}
}

void count_square() {

	int cnt = 0;
	for (int i = 0; i < 101; i++) {

		for (int j = 0; j < 101; j++) {

			if (map[i][j] && map[i + 1][j] && map[i][j + 1] && map[i + 1][j + 1]) {
				cnt++;
			}

		}
	}

	cout << cnt << '\n';

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n;


	for (int i = 0; i < n; i++) {

		cin >> y >> x >> d >> g;

		dir_info.clear();

		map[x][y] = true;
		x = x + dx[d];
		y = y + dy[d];

		map[x][y] = true;

		dir_info.push_back(d);
		for (int j = 0; j < g; j++) {

			make_curve();
		}

	}


	count_square();






	return 0;
}