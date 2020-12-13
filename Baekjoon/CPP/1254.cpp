#include <iostream>
#include <string>
#include <cstring>

using namespace std;
enum {
	MAX = 1001
};


string S;
int len;
int result;
void input() {

	cin >> S;



}

bool palindrome(int idx) {

	for (int i = 0; idx + i < len - i - 1; i++) {
		if (S[idx + i] != S[len - i - 1]) {
			return false;
		}
	}

			return true;
}

void solution() {

	len = S.size();
	

	for (int i = 0; i < len; i++) 
		if (palindrome(i)) {
			result = len + i;
			break;
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