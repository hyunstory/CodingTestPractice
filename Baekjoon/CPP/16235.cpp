#include<iostream>
#include<vector>
#include <cstring>
#include <algorithm>


using namespace std;

#define MAX 11

vector<pair<int, int>> tree[MAX][MAX];

vector<int> temp;

long long alive;

int dx[] = { -1, -1, -1, 0, 1, 1, 1, 0 };
int dy[] = { -1, 0, 1, 1, 1, 0, -1, -1 };


int N, M, K;


int map[MAX][MAX];
int winter_map[MAX][MAX];




void fourseason() {


	int size;

	//spring
	

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

		if (tree[i][j].size() == 0) continue;

		size = tree[i][j].size();


		

		sort(tree[i][j].begin(), tree[i][j].end());

		int total = 0;

		for (int k = 0; k < size; k++) {

		


			if (tree[i][j][k].second) {

				int z = tree[i][j][k].first;
				if (map[i][j] - z >= 0) {

					map[i][j] -= z;

					tree[i][j][k] = make_pair(z + 1, 1);

					temp.push_back(z + 1);

				}
				else {


					tree[i][j][k] = make_pair(z, 0);
					alive--;


					total += (int)(tree[i][j][k].first) / 2;
					


				}


			}


		}


		tree[i][j].clear();

		for (int q = 0; q < temp.size(); q++) {

			tree[i][j].push_back(make_pair(temp[q], 1));
		}

		temp.clear();

		map[i][j] += total;



		size = tree[i][j].size();


		for (int k = 0; k < size; k++) {

			if (!tree[i][j][k].second) {

				
			}

			
		}
	}

	//fall

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

		size = tree[i][j].size();


		for (int k = 0; k < size; k++) {

			if (tree[i][j][k].second) {
				if ((tree[i][j][k].first % 5) == 0) {

					for (int m = 0; m < 8; m++) {

						int nx = i + dx[m];
						int ny = j + dy[m];

						if (0 <= nx && nx < N && 0 <= ny && ny < N) {

							alive++;
							tree[nx][ny].push_back(make_pair(1, 1));

						}

					}
				}


			}


		}

	}


	//winter


	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

			map[i][j] += winter_map[i][j];
		}




}




void solve() {

	for (int i = 0; i < K; i++) {

		fourseason();


	}


	cout << alive << '\n';

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//시작 맵 초기화

	cin >> N >> M >> K;


	int x, y, z;




	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

			cin >> winter_map[i][j];

			map[i][j] = 5;



		}

	alive = M;

	for (int i = 0; i < M; i++) {

		cin >> x >> y >> z;

		x--;
		y--;
		

		tree[x][y].push_back(make_pair(z, 1));








	}



	solve();


}