#include <iostream>
#include <cmath>
#include <algorithm>

using namespace std;

void solution() {

	int a, b;

	cin >> a >> b;


	int one = abs(a - b);

	int minV = 1000000;

	int n;

	cin >> n;

	

	for (int i = 0; i < n; i++) {
		int temp;

		cin >> temp;

		minV = min(minV, abs(temp - b) + 1);
	}

	minV = min(minV, one);

	cout << minV << '\n';

}


int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);

	solution();


	return 0;
}