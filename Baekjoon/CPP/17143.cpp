#include <iostream>
#include <deque>
#include <tuple>


#define ROW 101
#define COL 101


using namespace std;

int R, C, M;

int dx[] = {0, -1, 1, 0, 0};
int dy[] = {0, 0, 0, 1, -1};

long long result;

deque<tuple<int, int, int>> map[ROW][COL];
deque<tuple<int, int, int>> map_temp[ROW][COL];

int changdir(int dir) {

	if (dir == 1) return 2;
	else if (dir == 2) return 1;
	else if (dir == 3) return 4;
	else if (dir == 4) return 3;


}

void copy_map() {

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
		
			map_temp[i][j].assign(map[i][j].begin(), map[i][j].end());
		
		}

}

void shark_check() {

	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {


			if (map[i][j].empty()) continue;
			else {

				int size = map[i][j].size();

				if (size > 1) {

					int ss = get<0>(map[i][j][0]);
					int dd = get<1>(map[i][j][0]);
					int max = get<2>(map[i][j][0]);
					
					

				
					for (int k = 1; k < size; k++) {

						if (max < get<2>(map[i][j][k])) {
						
							ss = get<0>(map[i][j][k]);
							dd = get<1>(map[i][j][k]);
							max = get<2>(map[i][j][k]);
						}

						
						

						
						
						
						
						
					}

					map[i][j].clear();
					map[i][j].push_back(make_tuple(ss, dd, max));


					



				}
			

			
			}

		}


}

void move_shark() {


	for (int i = 1; i <= R; i++)
		for (int j = 1; j <= C; j++) {
		
			if (!map_temp[i][j].empty()) {

			
				int s = get<0>(map_temp[i][j][0]);
				int d = get<1>(map_temp[i][j][0]);
				int z = get<2>(map_temp[i][j][0]);

				int px = i;
				int py = j;
			
				map[px][py].pop_front();

				if (d == 1 || d == 2) {

					int repeat = (R - 1) * 2;
					if (s >= repeat) s = s % repeat;

					for (int k = 0; k < s; k++) {
					
						int nx = px + dx[d];
						int ny = py + dy[d];

						if (nx < 1) {
						
							d = 2;
							nx += 2;
						}
						if (nx > R) {
						
							d = 1;
							nx -= 2;
							
						}

						px = nx;
						py = ny;
					}
				
				}

				else {

					int repeat = (C - 1) * 2;

					if (s >= repeat) s  = s % repeat;

					for (int k = 0; k < s; k++) {

						int nx = px + dx[d];
						int ny = py + dy[d];
						if (ny < 1) {
						
							d = 3;
							ny += 2;

						}

						if (ny > C) {
						
							d = 4;
							ny -= 2;
						}

						px = nx;
						py = ny;

						
					
					}
				
					
				}
				

				
				map[px][py].push_back(make_tuple(s, d, z));
			
			}
		
		}

}


void solve() {

	


	for (int i = 1; i <= C; i++) {  // 총돌리는 횟수, 낙시왕이 가장 오른쪽 열의 오른 칸에 이동하면 이동 멈추기


		//땅에 제일 가까운 상어를 잡는다...
		for (int j = 1; j <= R; j++) {
		
			
			if (!map[j][i].empty()) {

				result += get<2>(map[j][i][0]);
			
				map[j][i].pop_back();





				break;
				//땅에 제일 가까운 상어잡고 for문 빠져나오기
			}
			
		}

		//상어 이동

		copy_map();

		move_shark();

		shark_check();

		
		

		


	




	}



}


int main() {


	int r, c, temp_s, temp_d, temp_z;


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> R >> C >> M;

	for (int i = 0; i < M; i++) {
		cin >> r >> c >> temp_s >> temp_d >> temp_z;

		map[r][c].push_back(make_tuple(temp_s, temp_d, temp_z));

		
	
	}

	if (M != 0) {
		solve();
	}
		

	cout << result << '\n';
	


	return 0;
}