#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>

using namespace std;

int n;
int scvs[3];
int d[61][61][61];


int go(int i, int j, int k) {

	if (i < 0) return go(0, j, k);
	if (j < 0) return go(i, 0, k);
	if (k < 0) return go(i, j, 0);
	if (i == 0 && j == 0 && k == 0) return 0;

	int &ans = d[i][j][k];

	if (ans != -1) return ans;

	ans = 100000000;

	deque<int> p = { 1, 3, 9 };

	do {
		int temp = go(i - p[0], j - p[1], k - p[2]);

		if (ans > temp) ans = temp;
	} while (next_permutation(p.begin(), p.end()));

	ans += 1;

	return ans;

}

void solution() {

	cin >> n;

	for (int i = 0; i < n; i++) cin >> scvs[i];


	memset(d, -1, sizeof(d));

	cout << go(scvs[0], scvs[1], scvs[2]) << '\n';



}

int main() {

	solution();


	return 0;
}
