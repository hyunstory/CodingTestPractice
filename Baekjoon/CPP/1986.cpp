#include <iostream>
#include <vector>

using namespace std;

enum {

	Q_dir = 8,
	K_dir = 8,
	MAX = 1001
};


int N, M, Q_M, K_M, P_M;

int chess[MAX][MAX];
bool check[MAX][MAX];
//bool checkQ[MAX][MAX];
bool check_temp[MAX][MAX];

int result;

int Q_dx[] = {-1, 1, 0, 0, -1, -1, 1, 1};
int Q_dy[] = {0, 0, -1, 1, -1, 1, 1, -1};

int K_dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
int K_dy[] = {-2, -1, 1, 2, 2, 1, -1, -2};


vector<pair<int, int>> Q;
vector<pair<int, int>> K;
vector<pair<int, int>> P;


void copy_check(bool input[][MAX], bool output[][MAX]) {


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) output[i][j] = input[i][j];
}




void input() {

	int t1, t2;

	cin >> N >> M;

	cin >> Q_M;
	for (int i = 0; i < Q_M; i++) {
		
		cin >> t1 >> t2;
		check[t1][t2] = true;
		check_temp[t1][t2] = true;
		Q.push_back(make_pair(t1, t2));
	}

	cin >> K_M;
	for (int i = 0; i < K_M; i++) {
	
		cin >> t1 >> t2;
		check[t1][t2] = true;
		check_temp[t1][t2] = true;
		K.push_back(make_pair(t1, t2));
	}

	cin >> P_M;
	for (int i = 0; i < P_M; i++) {
	
		cin >> t1 >> t2;
		check[t1][t2] = true;
		check_temp[t1][t2] = true;
		
	}


}

void solution() {



	int Q_size = Q.size();
	int K_size = K.size();



	for (int i = 0; i < Q_size; i++) {
		int x = Q.back().first;
		int y = Q.back().second;

		Q.pop_back();

		//copy_check(check_temp, check);
	
		for (int j = 0; j < Q_dir; j++) {
			int nx = x + Q_dx[j];
			int ny = y + Q_dy[j];
			while (1) {


				if (1 > nx || nx > N || ny > M || 1 > ny || check_temp[nx][ny] == true) break;

				check[nx][ny] = true;

				nx = nx + Q_dx[j];
				ny = ny + Q_dy[j];


				
			
			}
		

		}
	}

	for (int i = 0; i < K_size; i++) {
		int x = K.back().first;
		int y = K.back().second;

		K.pop_back();

		for (int j = 0; j < K_dir; j++) {
			int nx = x + K_dx[j];
			int ny = y + K_dy[j];
			//while (1) {
			
				if ( 1 <= nx && 1 <= ny && nx <= N && ny <= M) check[nx][ny] = true;

				//nx = nx + K_dx[j];
				//ny = ny + K_dy[j];


			//}
		

		}
	

	}



	

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
			if (check[i][j] == false) result++;
		}

	
}

void solve() {

	input();
	solution();


	cout << result << '\n';

}

int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solve();



	return 0;
}