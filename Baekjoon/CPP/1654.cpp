#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int k, n;
long long arr[10001];

void solution() {


	long long left = 1;
	long long right = 1;


	cin >> k >> n;


	for (int i = 0; i < k; i++) {

		cin >> arr[i];
		right = max(right, arr[i]);
	}

	while (left <= right) {

		long long mid = (left + right) / 2;

		long long sum = 0;

		for (int i = 0; i < k; i++) {

			long long temp = arr[i];

			sum += (temp / mid);
		}


		if (sum >= n) {
			left = mid + 1;
		}

		else right = mid - 1;
	}


	cout << right << '\n';
	
}
int main() {


	solution();

	return 0;
}