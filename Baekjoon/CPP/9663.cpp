#include <iostream>
using namespace std;


int n, ans = 0;
bool col[16];
bool d1[31];
bool d2[31];

void solve(int r) {
	if (r > n) {
		ans++;
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (!col[i] && !d1[r + i] && !d2[n + (r - i) + 1]) {
			col[i] = d1[r + i] = d2[n + (r - i) + 1] = true;
			solve(r + 1);
			col[i] = d1[r + i] = d2[n + (r - i) + 1] = false;
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n;
	solve(1);
	cout << ans << '\n';


}