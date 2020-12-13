#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

void solution() {

	int n, k;

	cin >> n >> k;


	int left = 1;
	int right = k, ans;

	while (left <= right) {

		int mid = (left + right) / 2;

		long long cnt = 0;
		
		for (int i = 1; i <= n; i++) cnt += min(mid / i, n);
		if (cnt < k) left = mid + 1;
		else ans = mid, right = mid - 1;
		

	}


	
	cout << ans << '\n';
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}