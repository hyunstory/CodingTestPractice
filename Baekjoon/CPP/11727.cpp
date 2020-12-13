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

	int d[10008] = { 0 };

	d[0] = 1;
	d[1] = 1;

	for (int i = 2; i <= n; i++) {
	
	
		d[i] = d[i - 1] + 2 * d[i - 2];
		d[i] %= 10007;

	}

	cout << d[n];

	return 0;
}
	

	
	
	
	


