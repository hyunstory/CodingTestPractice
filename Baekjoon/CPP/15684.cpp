#include <iostream>
#include <algorithm>

using namespace std;

enum {

	MAX = 10000000,
	row = 11,
	col = 300
};

int N, M, H;


bool ladder[row][col];
bool check[row][col];

int result;


void input() {

	int x, y;
	result = MAX;
	cin >> N >> M >> H;

	for (int i = 0; i < M; i++) {
		cin >> y >> x;
		
		check[x][y] = true;
		



	}
	

}

bool startGame() {

	for (int i = 1; i <= N; i++) {
		int curNum = i;
		for (int j = 1; j <= H; j++) {
			if (check[curNum][j]) curNum += 1;
			else if (check[curNum - 1][j]) curNum -= 1;
		}

		if (curNum != i) return false;
	}

	return true;



}
void permute_line(int idx, int cnt) {

	if (cnt >= 4) return;

	if (startGame()) {

		result = min(result, cnt);
		return;
	}

	for (int i = idx; i <=H;i++)
		for (int j = 1; j < N; j++) {
		
			if (check[j][i]) continue;
			if (check[j - 1][i]) continue;
			if (check[j + 1][i]) continue;

			check[j][i] = true;
			permute_line(i, cnt + 1);
			check[j][i] = false;

		}
}
void solution() {

	
	permute_line(1, 0);

	if (result == MAX) result = -1;

	cout << result << '\n';


}



void solve() {

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