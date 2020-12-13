#include<iostream>
#include<queue>

using namespace std;


int n, m, startx, starty, endx, endy;

char dim[51][51];

int water_spread[51][51];

int check[51][51];


int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

queue<pair<int, int>> water;


void water_bfs() {
	while (!water.empty()) {
		
		int x = water.front().first;
		int y = water.front().second;

		water.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (water_spread[nx][ny] == 0 && dim[nx][ny] == '.') {
					water_spread[nx][ny] = water_spread[x][y] + 1;
					water.push(make_pair(nx, ny));
				}
			}
		}
	}

}

void bfs() {
	queue<pair<int, int>> q;

	q.push(make_pair(startx, starty));

	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];


			if (0 <= nx && nx < n && 0 <= ny && ny < m) {
				if (check[nx][ny] == 0 && (dim[nx][ny] == 'D' || dim[nx][ny] == '.')) {
					if (water_spread[nx][ny] == 0) {
						check[nx][ny] = check[x][y] + 1;
						q.push(make_pair(nx, ny));

					}
					else {
						if (water_spread[nx][ny] > check[x][y] + 1) {
							check[nx][ny] = check[x][y] + 1;
							q.push(make_pair(nx, ny));
						}
					}
				}
			}

		}



	}
	
}



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	char temp;

	cin >> n >> m;

	
	for(int i = 0;i<n;i++)
		for (int j = 0; j < m; j++) {
			cin >> temp;
			dim[i][j] = temp;

			if (temp == 'D') {
				endx = i;
				endy = j;

			}

			else if (temp == 'S') {
				startx = i;
				starty = j;
			}

			else if (temp == '*') water.push(make_pair(i, j));
			
		}


	water_bfs();

	bfs();


	if (check[endx][endy] != 0) {

		cout << check[endx][endy] << '\n';
		
	}
	else cout << "KAKTUS\n";

	


		return 0;
}