#include <iostream>

using namespace std;


int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int a, b;



	int repeat;
	cin >> repeat;
	for (int i = 0; i < repeat; i++) {
	
		cin >> a >> b;

		int result = a + b;

		cout << "Case" << " " << "#" << i + 1 << ":";
		cout << " " << a << " "<<"+"<< " " << b << " " << "=" << " " << result << "\n";

	}
	
	return 0;
}