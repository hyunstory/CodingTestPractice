#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int n;
	cin >> n;
	vector<int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	vector<int> d(n + 1);

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			d[i] = max(d[i], d[i - j] + a[j]);
		}
	}
	cout << d[n] << '\n';
	return 0;
}
	

	
	
	
	


