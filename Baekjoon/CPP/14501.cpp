#include <iostream>
#include <algorithm>

enum {

	TEST_CASE_MAX = 16,
	T_MAX = 6,
	P_MAX = 1001



};

int result;


using namespace std;
int N;

struct counsel {

	int T;
	int P;

};

int DP[TEST_CASE_MAX];

counsel Counsel[TEST_CASE_MAX];

void input() {

	cin >> N;

	for (int i = 1; i <= N; i++) cin >> Counsel[i].T >> Counsel[i].P;

}



void solution() {

	int max_temp = 0;

	for (int i = 1; i <= N + 1; i++) {
	
		max_temp = max(max_temp, DP[i]);
		if (i + Counsel[i].T > N + 1) continue;

		DP[i + Counsel[i].T] = max(max_temp + Counsel[i].P, DP[i + Counsel[i].T]);
	}

	result = max_temp;


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