#include <iostream>

using namespace std;

#define input_max 50 + 1
#define dir 4

char map[input_max][input_max];
bool check[input_max][input_max];


int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
int n, m;


void dfs(int x, int y, char type, int d) {

	check[x][y] = true; // 방문했다는 표시 하기

	if (map[x][y] != type) return;  // 같은 문자열이 아니라면 반환하여 다음 방향 실행하기

	


	for (int i = 0; i < dir; i++) {

		if (i == ((d + 2) % 4)) continue;  // 진행해온 반대방향은 돌아가는 방향이기 때문에 돌아가지 않게 만든다.

		int nx = x + dx[i];
		int ny = y + dy[i];

		if (nx >= 0 && nx < n && ny >= 0 && ny < m && map[nx][ny] == type && !check[nx][ny]) {  //같은 문자이고, 갔던 길이 아닌지 확인
			
			dfs(nx, ny, type, i);

		}


		else if (map[nx][ny] == type && check[nx][ny]) { //같은 문자이지만, circular가 형성이 되면 "Yes"를 출력하고 프로그램 종료

			cout << "Yes" << '\n';

			exit(0);
		}
		
	}

}

void solution() {

	cin >> n >> m;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {

			cin >> map[i][j];   // 문자 입력
		}


	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++) {
			char temp = map[i][j];

			if (!check[i][j]) {  // 탐색해봤던 길이 아니라면 i, j부터 탐색을 시작해본다.


				int d = -1;  
				
				for (int k = 0; k < dir; k++) {

					if (map[i + dx[k]][j + dy[k]] == temp) {   // i,j 중심으로 4방향 상우하좌 중에서 가장 처음에 찾은 방향을 값을 넣기
						d = k;
						break;
					}
					
				}

				if (d == -1) continue; // 주변에 i,j와 같은 문자가 없다는 뜻이다. 1개의 문자만 존재할 때 default -1, 연산 패스

				dfs(i, j, temp, d);  //재귀함수 dfs깊이 탐색하기


			}
			
			
		}

	cout << "No" << '\n';



}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solution();


	return 0;
}