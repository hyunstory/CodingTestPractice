#include<iostream>
#include <algorithm>

using namespace std;


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	int a,b, tmp;

	cin >> a>>b;



	for (int i = 0; i < a; i++) {
	
		cin >> tmp;

		if (tmp < b) cout << tmp<<' ';
	}





		return 0;
}