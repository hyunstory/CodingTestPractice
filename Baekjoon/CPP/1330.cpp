#include<iostream>

using namespace std;

int main() {


	int n, m, k;

	cin >> n >>m;

	if (n > m) cout << '>' << '\n';
	
	else if (n < m) cout << '<' << '\n';
	else if (n == m) cout << "==" << '\n';




	return 0;
}