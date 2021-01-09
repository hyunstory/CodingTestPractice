/*


2^27승이 1억 3천정도 된다.

dfs로 조합 구하려면 2^25이내이면 1초가 됨.

맵을 1차원으로 만든다음, dfs로 순열을 구해서 풀어도 된다.


아래 코드는 비트연산으로 구한 코드
*/

#include <iostream>
#include <cstring>
#include <string>

using namespace std;

char map[5][5];
bool check[1 << 25];
int result;

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void dfs(int cnt, int s, int c) {

	if (cnt >= 7) {
		if (s > 3) result++;
		return;
	}

	for (int i = 0; i < 25; i++) {
		if ((c & (1 << i)) == 0) continue;

		int x = i / 5;
		int y = i % 5;

		for (int k = 0; k < 4; k++) {
			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
			int num = nx * 5 + ny;
			if (check[c | (1 << num)])continue;

			check[c | (1 << num)] = true;

			if (map[nx][ny] == 'S') dfs(cnt + 1, s + 1, c | (1 << (num)));
			if (map[nx][ny] == 'Y') dfs(cnt + 1, s, c | (1 << (num)));
		}
	}

}

void solution() {

	for (int i = 0; i < 5; i++){
		cin >> map[i];
	}

	int prin = 0;

	for (int i = 0; i < 5; i++)
		for (int j = 0; j < 5; j++) {

			check[1 << (i * 5 + j)] = true;
			dfs(1, map[i][j] == 'S', 1 << (i * 5 + j));

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