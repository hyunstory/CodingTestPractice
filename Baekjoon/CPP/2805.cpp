#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


long long n, m;

long long arr[1000001];

void solution() {

	long long left = 1;
	long long right = 1;

	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];

		right = max(right, arr[i]);

	}

	while (left <= right) {

		long long mid = (left + right) / 2;

		long long log = 0;

		for (int i = 0; i < n; i++) {

			if (arr[i] > mid) log += (arr[i] - mid);
					
		}

		if (log >= m) left = mid + 1;
		else right = mid - 1;
		
	}

	cout << right << '\n';

	

	


	
}
int main() {


	solution();

	return 0;
}