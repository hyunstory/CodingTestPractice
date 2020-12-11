#include <iostream>

using namespace std;


#define input_max 1000 + 1

bool map[input_max][input_max];
bool check[input_max];
int n, m, result;


void dfs(int num) {

	check[num] = true;


	for (int i = 1; i <= n; i++) {
		
		if (map[num][i] && !check[i]) {    //num -> i 방향으로 깊이 탐색 진행, 연결이 끈기거나 싸이클이 돌 때까지 탐색
			dfs(i);
		}
	}
}

void solution() {

	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int a, b;

		cin >> a >> b;


		map[a][b] = true;  // 양방향으로 간선만들어주기
		map[b][a] = true;  // 양방향으로 간선만들어주기

	}

	
	for (int i = 1; i <= n; i++) {

		if (!check[i]) {
			result++;    //시작 시 카운트 세주기

			dfs(i);      // DFS 탐색
		}
	}

	cout << result << '\n';




}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solution();


	return 0;
}