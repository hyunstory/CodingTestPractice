#include <iostream>
#include <queue>
#include <deque>
#include <tuple>
#include <cstring>
#include <algorithm>


using namespace std;


#define dir_num 4
#define MAX 21

struct BabyShark {
	int cur_size;
	int cur_eaten;
	int cur_x;
	int cur_y;

};

int N;
int result;
int map[MAX][MAX];
int timeCount[MAX][MAX];
bool check[MAX][MAX];
BabyShark babyshark;

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

void init_shark() {

	babyshark.cur_size = 2;
	babyshark.cur_eaten = 0;
}

void input() {
	int temp;


	cin >> N;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {

			cin >> temp;
			
			map[i][j] = temp;

			if (temp == 9) {
				babyshark.cur_x = i;
				babyshark.cur_y = j;
				
			}

		}

}

int find_fish() {

	int FLAG = 0;

	queue<pair<int, int>> q;
	deque<tuple<int, int, int>> fish; // dist, x, y

	int x = babyshark.cur_x;
	int y = babyshark.cur_y;
	check[x][y] = true;
	map[x][y] = 0;

	q.push(make_pair(x, y));

	while (!q.empty()) {

		x = q.front().first;
		y = q.front().second;
		q.pop();

		for (int k = 0; k < dir_num; k++) {

			int nx = x + dx[k];
			int ny = y + dy[k];
			int size_f = map[nx][ny];

			if (nx >= 0 && nx < N && ny >= 0 && ny < N && !check[nx][ny]) {
				if (!size_f) {
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					timeCount[nx][ny] = timeCount[x][y] + 1;
				}
				else if (size_f > 0 && size_f <=babyshark.cur_size) {
					
					if (size_f < babyshark.cur_size) {
						FLAG = true;
						int distance = timeCount[x][y] + 1;
						fish.push_back(make_tuple(distance, nx, ny));
					}
					
					q.push(make_pair(nx, ny));
					check[nx][ny] = true;
					timeCount[nx][ny] = timeCount[x][y] + 1;

				}

			}

		}

	}



	if (FLAG) {

		// 먹을만한 물고리를 찾았으면,

		sort(fish.begin(), fish.end());

		result += get<0>(fish.front());
		int x = get<1>(fish.front());
		int y = get<2>(fish.front());

		map[babyshark.cur_x][babyshark.cur_y] = 0;

		babyshark.cur_x = x;
		babyshark.cur_y = y;

		map[x][y] = 0;
		

		if (++babyshark.cur_eaten == babyshark.cur_size) {
			babyshark.cur_size++; //먹은것이 크기와 가 같으면 크기 1증가
			babyshark.cur_eaten = 0;
		}
		
	}
	
	return FLAG;
}


void solution() {

	int FLAG;


	do {

		FLAG = 0;
		memset(check, false, sizeof(check));
		memset(timeCount, 0, sizeof(timeCount));
		FLAG = find_fish();

	} while (FLAG);

	cout << result << '\n';
}



void solve() {

	init_shark();

	input();

	solution();
}

int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solve();



	return 0;
}