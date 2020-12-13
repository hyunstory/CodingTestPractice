#include<iostream>
#include <algorithm>

using namespace std;


int temp;
int max1 = -1000001;
int min2 = 1000001;


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n;

	cin >> n;



	for (int i = 0; i < n; i++) {
	
		cin >> temp;
		max1 = max(temp, max1);
		min2 = min(temp, min2);
	}

	

	

	cout << min2 << " " << max1 << '\n';

	return 0;
}
