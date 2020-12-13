#include<iostream>
#include<vector>
#include<tuple>
using namespace std;

int repeat;


bool location[4];


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n, m;
	bool tmp;
	bool notfound = true;

	location[1] = true;
	cin >> repeat;

	for (int i = 0; i < repeat; i++) {
		
		cin >> n >> m;

		tmp = location[n];
		location[n] = location[m];
		location[m] = tmp;

		
	}

	for (int i = 1; i <= 3; i++) {
	


		if (location[i]) {
			
			cout << i << '\n';
			notfound = false;
			break;
		}




	}


	if (notfound) {
		cout << '-1' << '\n';
	}
	


	



	return 0;
}

