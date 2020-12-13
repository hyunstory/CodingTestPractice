#include <iostream>
#include <deque>
#include <algorithm>
#include <cmath>

using namespace std;

int n, c;

long long result = 1000000000;
long long max_value;


deque<int> dq;
bool ok(int x) {
	int cnt = 1;

	int last = dq[0];

	for (int house : dq) {
		if (house - last >= x) {
			cnt++;
			last = house;
		}
	}

	return cnt >= c;
}

void solution() {

	

	cin >> n >> c;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;


		dq.push_back(temp);

	}

	
	sort(dq.begin(), dq.end());

	int left = 1;
	int right = dq[n-1] - dq[0];


	int ans = left;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (ok(mid)) {
			if (ans < mid) {
				ans = mid;
			}
			left = mid + 1;

		}
		else {
			right = mid - 1;
		}
	}


	

	cout << ans << '\n';
	
}

int main() {

	solution();


	return 0;
}
