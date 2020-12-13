#include <iostream>

using namespace std;


int n, b, c;
int p[10000000];

long long result;
int temp;
int product;
void solve() {
	
	for (int i = 0; i < n; i++) {
	
		temp = p[i];

		temp -= b;
		
		product = temp / c - 1;
        
        if (product < 0) product = 0;
	
		while (1) {
		
			if ((product * c) >= temp) {
				result += product + 1;
				break;
			}

			product++;
		
		}

		
	
	}

	cout << result << '\n';

	
	
}



int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for (int i = 0; i < n; i++) {
	
		cin >> p[i];

	}

	cin >> b >> c;

	solve();







	return 0;
}

