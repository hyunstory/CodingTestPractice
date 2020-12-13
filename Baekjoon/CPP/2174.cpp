#include <iostream>
#include <cstring>


using namespace std;

int A, B, N, M;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

int FLAG = 1;
struct robot {

	int x;
	int y;
	int dir;

};

bool check[105][105];



robot Robot[105];

void solution(int robot, char cmd, int times) {

	for (int i = 0; i < times; i++) {
		//cout << Robot[robot].x << ' ' << Robot[robot].y << " " << Robot[robot].dir<< '\n';

		int x = Robot[robot].x;
		int y = Robot[robot].y;
		int dir = Robot[robot].dir;
		

		if (cmd == 'F') {

			int nx = x + dx[dir];
			int ny = y + dy[dir];

			if (1 <= nx && nx <= B && 1 <= ny && ny <= A) {

				if (check[nx][ny] == false) {
					check[x][y] = false;
					check[nx][ny] = true;

					Robot[robot].x = nx;
					Robot[robot].y = ny;

					//cout << Robot[robot].x << ' ' << Robot[robot].y << '\n';
				}

				else {
				
					int robotNum = 0;

					for (int i = 1; i <= N; i++) {

						if (i == robot) continue;

						int x = Robot[i].x;
						int y = Robot[i].y;

						if (nx == x && ny == y) {

							robotNum = i;


						}
					}
					
					if (FLAG != 2) cout << "Robot " << robot << " crashes into robot " << robotNum << '\n';
					FLAG = 2;
					return;
				}



			}

			else {
				//cout << Robot[robot].x << ' ' << Robot[robot].y << '\n';
				if (FLAG != 2) cout << "Robot " << robot << " crashes into the wall\n";
				FLAG = 2;
				return;
			}



		}

		else if (cmd == 'L') {

			if (dir - 1 < 0) {
			
				Robot[robot].dir = 3;
			}
			else {
				Robot[robot].dir = dir - 1;
			}

		}

		else if (cmd == 'R') {

			Robot[robot].dir = (dir + 1) % 4;


		}



	}




}

void input() {

	cin >> A >> B;
	cin >> N >> M;

	char temp;
	int x;

	for (int i = 1; i <= N; i++) {

		cin >> Robot[i].y >> x >> temp;

		Robot[i].x = B + 1 - x;

		check[Robot[i].x][Robot[i].y] = true;

		switch (temp) {
		
		case 'N':
			Robot[i].dir = 0;
			break;
		case 'E':
			Robot[i].dir = 1;
			break;
		case 'S':
			Robot[i].dir = 2;
			break;
		case 'W':
			Robot[i].dir = 3;
			break;
		default:
			break;
		}


	}

	for (int i = 1; i <= M; i++) {

		int robot, times;
		char cmd;
	
		cin >> robot >> cmd >> times;


		//cout << Robot[1].x << ' ' << Robot[1].y << '\n';
		solution(robot, cmd, times);



	}

	if (FLAG == 1) cout << "OK" << '\n';

	

}




void solve() {

	//while (1) {
		input();
		//FLAG = 1;
	//}
	//solution();


}






int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);






	solve();






	return 0;
}