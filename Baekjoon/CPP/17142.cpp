#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;


vector<pair<int, int>> virus;

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0 ,0 };


int empty1;

int map[51][51];
int time2[51][51];
bool select2[11];


bool cnt_v;



int result = 987654321;


int N, M;




void spread_virus(queue<pair<int,int>>q) {
	int cnt = 0;

	int temp2 = 0;




	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;


		q.pop();

		


			

			for (int i = 0; i < 4; i++) {

				int nx = x + dx[i];
				int ny = y + dy[i];

				if (0 <= nx && nx < N && 0 <= ny && ny < N) {

					if (map[nx][ny] != 1 && time2[nx][ny] == -1) {

						

						time2[nx][ny] = time2[x][y] + 1;
						

						if (map[nx][ny] == 0) {

							cnt++;

							temp2 = time2[nx][ny];


						}


						q.push(make_pair(nx, ny));

						

					}


				}

			}



		

	}

	


	if (cnt == empty1) {


		result = min(result, temp2);
	}



}


void DFS(int start, int depth) {

	int virus_size = virus.size();



	if (depth == M) {
		queue<pair<int, int>> q;
		
		memset(time2, -1, sizeof(time2));

		for (int i = 0; i < virus.size(); i++) {
			if (select2[i] == true){

			q.push(make_pair(virus[i].first, virus[i].second));
			time2[virus[i].first][virus[i].second] = 0;
			}
		}
		
		spread_virus(q);


		



		return;
	
	}


	for (int i = start; i < virus.size(); i++) {
	/*
		idx[depth] = i;
		DFS(i + 1, depth + 1); */

		if (select2[i] == true) continue;
		select2[i] = true;
		DFS(i + 1, depth + 1);
		select2[i] = false;
	}


}

void solve() {

	DFS(0, 0);

	if (result == 987654321) cout << -1 << '\n';
	else cout << result << '\n';





}


int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int temp;

	cin >> N >> M;

	for(int i = 0;i<N;i++)
		for (int j = 0; j < N; j++) {

			cin >> temp;

			if (temp == 2) {

				

				virus.push_back(make_pair(i, j));
			}

			else if (temp == 0) {
				empty1++;
			}
			map[i][j] = temp;
			
		
		}




	solve();

	//cout << result << '\n';
	
	return 0;

}