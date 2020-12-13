#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n;
int sum;

int result;






int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	cin >> n;
	vector<int> d(n);
	vector<int> temp(n);



	

	for (int i = 0; i < n; i++) {
		cin >> d[i];

	}

	

	sort(d.begin(), d.end());

	temp[0] = d.front();
	sum = d.front();


	for (int i = 1; i < n; i++) {
		
		temp[i] = temp[i - 1] + d[i];
		sum += temp[i];
	
	}

	result = sum;

	

	cout << result;

	return 0;
}
	

	
	
	
	


