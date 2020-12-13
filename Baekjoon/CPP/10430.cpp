#include<iostream>

using namespace std;

int main() {


	int n, m, k;

	cin >> n >> m >> k;


	cout << (n + m) % k << '\n';
	cout << (n%k + m%k) %k << '\n';
	cout << (n * m)%k << '\n';
	cout << (n % k * m%k)%k << '\n';

	return 0;
}