#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;




int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int rect[1001] = { 0 };

	int N;
	cin >> N;

	rect[0] = 1;
	rect[1] = 1;

	for (int i = 2; i <= N; i++) {
	
	
		rect[i] = rect[i - 1] + rect[i - 2];

		rect[i] %= 10007;

	}

	cout << rect[N] << "\n";
	


	

	return 0;
		
	}
	

	
	
	
	


