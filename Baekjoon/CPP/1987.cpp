#include <iostream>
#include <algorithm>

using namespace std;

int n, m;

int result;

char str[30][30];

bool check[26];

//int count_check[25][25];

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void DFS(int x, int y, int count) {

	int temp = str[x][y];

	result = max(result, count);


	for (int i = 0; i < 4; i++) {

		int nx = x + dx[i];
		int ny = y + dy[i];

		temp = str[nx][ny];

		if (0 <= nx && nx < n && 0 <= ny && ny < m && !check[temp - 65]) {

			//count_check[nx][ny] = count_check[x][y] + 1;
			//result = max(result, count_check[nx][ny]);
			check[temp - 65] = true;

			DFS(nx, ny, count + 1);

			check[temp - 65] = false;



		}






	}


}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			cin >> str[i][j];

		}
	int temp = str[0][0];
	check[temp - 65] = true;
	//count_check[0][0] = 1;

	DFS(0, 0, 1);

	cout << result << '\n';







	return 0;
}