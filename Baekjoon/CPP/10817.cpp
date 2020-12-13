#include<iostream>
#include <algorithm>

using namespace std;

int main() {


	int a, b, c;

	cin >> a >> b >> c;

	int temp;
	temp = max(max(a, b), c);

	if (a == temp) cout << max(b, c);
	else if (b == temp) cout << max(a, c);
	else if (c == temp) cout << max(a, b);
	





		return 0;
}