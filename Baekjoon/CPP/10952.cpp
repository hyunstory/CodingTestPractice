#include <iostream>

using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;



	while (a != 0 || b != 0) {
	cin >> a >> b;
	int result = a + b;

	if(a != 0 || b !=0)
	cout << result << "\n";

	}
	
	return 0;
}