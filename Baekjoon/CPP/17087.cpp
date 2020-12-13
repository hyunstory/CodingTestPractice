#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int gcd(int x, int y) {

	if (y == 0) return x;
	else return gcd(y, x%y);

}


void solution() {

	int n, s;
	cin >> n >> s;
	vector <int> v(n);

	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		int diff = abs(x - s);

		v[i] = diff;
	}

	int ans = v[0];

	for (int i = 1; i < n; i++) {
		ans = gcd(ans, v[i]);
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


