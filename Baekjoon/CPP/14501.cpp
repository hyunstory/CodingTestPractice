#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;


const int MAX = 16;

int n;

int t[MAX];
int p[MAX];
int result;
void go(int idx, int sum){

	if (idx > n + 1) return;

	if (idx == n + 1) {
		result = max(result, sum);
		return;
	}

	go(idx + t[idx], sum + p[idx]);
	go(idx + 1, sum);
	

	
}
void solution(){
	cin >> n;

	for (int i = 1; i <= n; i++){
		cin >> t[i] >> p[i];
	}

	go(1, 0);
	cout << result << '\n';
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}