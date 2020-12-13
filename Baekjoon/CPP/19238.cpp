#include <iostream>
#include <deque>
#include <algorithm>
#include <tuple>
#include <queue>
#include <cstring>
#include <memory>


using namespace std;

#define input_max 20 + 1

int n, m, fuel;

int map[input_max][input_max];
int simul[input_max][input_max];
bool check[input_max][input_max];
int taxi_x, taxi_y;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };


bool fuel_check(int result_fuel) {


	if (fuel - result_fuel < 0) {
		cout << -1 << '\n';
		exit(0);

	}

	
	return true;


}


void bfs() {

	queue<pair<int, int>> q;

	q.push(make_pair(taxi_x, taxi_y));

	check[taxi_x][taxi_y] = true;


	while (!q.empty()) {
	
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];


			if (nx >= 1 && nx <= n && ny >= 1 && ny <= n && !check[nx][ny] && simul[nx][ny] != -1) {

				check[nx][ny] = true;
				simul[nx][ny] = simul[x][y] + 1;
				q.push(make_pair(nx, ny));
				
			}
		}

	
	}

}

void solution() {



	deque<tuple<int, int, int, int, int>> trans; // 최단거리, 사용자, 목적지


	cin >> n >> m >> fuel;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) {
			int temp;
			cin >> temp;
			
			if (temp == 1) map[i][j] = -1;
			else map[i][j] = temp;

		}



	cin >> taxi_x >> taxi_y;



	for (int i = 0; i < m; i++) {

		int temp1, temp2, temp3, temp4;

		cin >> temp1 >> temp2 >> temp3 >> temp4;

		trans.push_back(make_tuple(0, temp1, temp2, temp3, temp4));

		
	}

	bool flag = true;

	while (!trans.empty()) {
	
		//최단 거리 구하기

		int min = 500;


		memcpy(simul, map, sizeof(simul));
		memset(check, false, sizeof(check));

		bfs();

		for (int i = 0; i < trans.size(); i++) {
			int x = get<1>(trans[i]);
			int y = get<2>(trans[i]);
			int dxdx = get<3>(trans[i]);
			int dydy = get<4>(trans[i]);


			int value = simul[x][y];
			if (!check[x][y]) {
				trans[i] = make_tuple(500, x, y, dxdx, dydy);
			}

			else if (value <= min) {
				trans[i] = make_tuple(value, x, y, dxdx, dydy);
			}
		}

		sort(trans.begin(), trans.end());



		int cus_fuel = get<0>(trans.front());
		int cx = get<1>(trans.front());
		int cy = get<2>(trans.front());
		int dest_x = get<3>(trans.front());
		int dest_y = get<4>(trans.front());

		if (cus_fuel == 500) {
			cout << -1 << '\n';
			exit(0);
		}

		trans.pop_front();

		if (fuel_check(cus_fuel)) {
			fuel -= cus_fuel;
			taxi_x = cx;
			taxi_y = cy;

		}


		memcpy(simul, map, sizeof(simul));
		memset(check, false, sizeof(check));

		bfs();

		int des_fuel = simul[dest_x][dest_y];

		if (!check[dest_x][dest_y]) {
			cout << -1 << '\n';
			exit(0);
		}


		if (fuel_check(des_fuel)) {
			fuel -= des_fuel;
			taxi_x = dest_x;
			taxi_y = dest_y;

			fuel += des_fuel * 2;
		}

		
	
	}



	cout << fuel << '\n';




}

int main() {


	solution();

	return 0;
}