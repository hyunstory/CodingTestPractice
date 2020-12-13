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
	
		for (int k = 0; k <= i; k++) {
		
			cout << "*";
		}
		cout << "\n";

	}
	
	return 0;
}