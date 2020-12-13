#include <iostream>

using namespace std;

int result;

int DP[1001];
int sequence[1001];

int N;



void input() {

	cin >> N;

	for (int i = 1; i <= N; i++) {

		cin >> sequence[i];
	
		
	}
}

void solution() {

	for (int i = 1; i <= N; i++) {
	
		int min = 0;
		for (int j = 0; j < i; j++) {
			if (sequence[i] > sequence[j]) {
				if (min < DP[j]) min = DP[j];
			}
		
			
		}
		DP[i] = min + 1;
		if (result < DP[i]) result = DP[i];
	}

}

void solve() {

	input();

	solution();

	cout << result << '\n';
}


int main() {


	solve();



	



	return 0;

}