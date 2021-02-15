#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1500001;

int t[MAX];
int p[MAX];
int dp[MAX];
int n;

int go(int idx){

	if (idx == n + 1) return 0;

	int &ret = dp[idx];
	if (ret != -1) return ret;

	ret = 0;

	if (idx + t[idx] <= n + 1){
		ret += max(go(idx + 1), p[idx] + go(idx + t[idx]));
	}
	else {
		ret += go(idx + 1);
	}


	return ret;
}

void solution(){
	cin >> n;

	for (int i = 1; i <= n; i++){
		cin >> t[i] >> p[i];

	}
	memset(dp, -1, sizeof(dp));

	cout << go(1) << '\n';

}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}