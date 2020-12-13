#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int tree[1000001];

int find(int x) {
	if (x == tree[x]) return x;
	else return tree[x] = find(tree[x]);
}

void solution() {

	cin >> n >> m;

	for (int i = 0; i <= n; i++) tree[i] = i;

	for (int i = 0; i < m; i++) {
		int cmd, a, b;

		cin >> cmd >> a >> b;

		if (cmd == 0) {
			a = find(a);
			b = find(b);

			if (a > b) tree[a] = b;
			else if (a < b) tree[b] = a;
		}
		else if (cmd == 1) {
			a = find(a);
			b = find(b);
			if (a == b) cout << "YES\n";
			else cout << "NO\n";
		}
	}


}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}