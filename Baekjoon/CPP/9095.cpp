#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int N;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int d[12] = { 0 };

	int testCase;
	
	cin >> testCase;
	d[0] = 1;
	for (int i = 1; i < 11; i++) {
	
		if (i - 1 >= 0) d[i] += d[i - 1]; 

		if (i - 2 >= 0) d[i] += d[i - 2]; 

		if (i - 3 >= 0) d[i] += d[i - 3]; 

	
	}

	

	while (testCase--) {
	
		int n;
		cin >> n;
		cout << d[n]<<"\n";
	}
	

	return 0;
		
	}
	

	
	
	
	


