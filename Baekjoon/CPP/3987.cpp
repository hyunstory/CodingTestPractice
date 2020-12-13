#include <iostream>
#include <algorithm>

using namespace std;


enum {

	MAX = 501,
	vec = 4
};
int N, M;
int PR, PC;

char space[MAX][MAX];
char tmp_space[MAX][MAX];

int cnt[vec];

int result;
char result_c;

char FLAG;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
char final_c[] = { 'U', 'R', 'D', 'L' };

void copy_map(char input[][MAX], char output[][MAX]) {


	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
		
			output[i][j] = input[i][j];
		}
}

void input() {

	cin >> N >> M;

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= M; j++) {
		

			cin >> space[i][j];
		}

	cin >> PR >> PC;

	

	


}


void solution() {

	

	for (int i = 0; i < 4; i++) {
		// i = 0일 때 U
		// i = 1일 때 R
		// i = 2일 때 D
		// i = 3일 때 L

		int x = PR;
		int y = PC;
		int d = i;

		//tmp_space[x][y] = '*';
	
		copy_map(space, tmp_space);

		while (1) {

			int nx = x + dx[d];
			int ny = y + dy[d];

			if (1 <= nx && nx <= N && 1 <= ny && ny <= M) {

				if (tmp_space[nx][ny] == 'C') {

					break;


				}

				else if (tmp_space[nx][ny] == '/') {

					switch (d)
					{
					case 0:
						d = 1;

						break;
					case 1:
						d = 0;

						break;
					case 2:
						d = 3;

						break;

					case 3:
						d = 2;

						break;

					default:
						break;
					}

				}

				else if (tmp_space[nx][ny] == '\\') {

					switch (d)
					{
					case 0:
						d = 3;

						break;
					case 1:
						d = 2;

						break;
					case 2:
						d = 1;

						break;
					case 3:
						d = 0;

						break;

					default:
						break;
					}


				}




				cnt[i]++;
				//tmp_space[nx][ny] = '*';
				x = nx;
				y = ny;

				

				if (cnt[i] > 1000000) {
					result_c = final_c[i];
					FLAG = -1;
					break;
				}


			}

			else {
			//공간을 벗어났다면, 중단한다.
				break;
			}




		}

		
		
	}


	result = cnt[0];
	result_c = final_c[0];
	

	for (int i = 1; i <= 3; i++) {



		if (result < cnt[i]) {
		
			result = cnt[i];
			result_c = final_c[i];
		}
	}

	

}



void solve() {

	input();

	solution();
	result += 1;

	if (FLAG != -1) {
		cout << result_c << '\n';
		cout << result << '\n';
	}
	else {
		cout << result_c << '\n';
		cout << "Voyager" << '\n';
	}
}

int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solve();




	return 0;
}