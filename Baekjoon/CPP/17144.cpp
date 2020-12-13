#include <iostream>
#include <vector>



using namespace std;

vector<pair<int, int>> vac;
vector<pair<int, int>> dirt;


int R, C, T;
int map[51][51];
int c_map[51][51];

int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };


void copy_map(int a[][51], int b[][51]){ 

	for (int i = 0; i < R; i++) {
	
		for (int j = 0; j < C; j++) {
		
			a[i][j] = b[i][j];
		}
	}

}
void spread_dirt() {

	copy_map(c_map, map);

	for (int i = 0; i < R; i++) {
	
		for (int j = 0; j < C; j++) {
		
			if (map[i][j] != 0 && map[i][j] != -1) {
			
				int cnt = 0;
				int value = map[i][j] / 5;
				for (int k = 0; k < 4; k++) {
				
					int nx = i + dx[k];
					int ny = j + dy[k];

					if (nx >= 0 && ny >= 0 && nx < R && ny < C && map[nx][ny] != -1) {
						
						c_map[nx][ny] = c_map[nx][ny] + value;
						cnt++;	
					
					}
				}
			
				c_map[i][j] = c_map[i][j] - (cnt * value);

			}
		}
	}

	copy_map(map, c_map);

}

void move_dirt() {

	


	for (int idx = 0; idx < 2; idx++) {

		int first = vac[idx].first;
	
		if (idx == 0) {
		
			for (int i = first - 1; i > 0; i--) {
			
				map[i][0] = map[i - 1][0];

			}

			for (int i = 0; i < C - 1; i++) {
			
				map[0][i] = map[0][i + 1];
			}

			for (int i = 1; i <= first; i++) {
			
				map[i - 1][C - 1] = map[i][C - 1];
			}

			for (int i = C - 1; i > 1; i--) {
			
				map[first][i] = map[first][i - 1];
			}

			map[first][1] = 0;
		}
		else {
		
			for (int i = first + 1; i < R - 1; i++) {
			
				map[i][0] = map[i + 1][0];

			}
			for (int i = 0; i < C - 1; i++) {
			
				map[R - 1][i] = map[R - 1][i + 1];
			}
			for (int i = R - 1; i >= first; i--) {
			
				map[i][C - 1] = map[i - 1][C - 1];
			}
			for (int i = C - 1; i > 1; i--) {
			
				map[first][i] = map[first][i - 1];
			}
			map[first][1] = 0;
		}
	
	}


}


int count_dirt() {

	int result = 0;

	for (int i = 0; i < R; i++) {
	
		for (int j = 0; j < C; j++) {
		
			result += map[i][j];
		}
	}

	return result + 2;  //공기청정기 -1 -1 해주었기 때문에
}



void solve() {


	for (int i = 0; i < T; i++) {
		//T만큼 돌린다.


		spread_dirt();
		move_dirt();

		
	
	
	
	}

	cout << count_dirt() << '\n';






}

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int temp;

	cin >> R >> C >> T;


	for(int i = 0;i < R;i++)
		for (int j = 0; j < C; j++) {
		

			cin >> temp;

			map[i][j] = temp;


			if (temp == -1) {
				vac.push_back(make_pair(i, j));
			}



			
		
		}



	solve();





	return 0;
}
