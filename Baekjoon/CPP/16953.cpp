#include <iostream>
#include <algorithm>

using namespace std;


int a, b;
int result = -1;

void go(int dep, int num) {

	if (num < a) {
		
		return;
	}

	else if (num == a) {
		
		result = dep;
		return;
	}

	if (num % 10 == 1) {
		num = (num - 1) / 10;

	}
	else if (num % 2 == 0) {
		num = num / 2;

	}
	else return;

	go(dep + 1, num);

}
void solution() {

	cin >> a >> b;


	go(1, b);
	
	
	cout << result << '\n';
	

}
int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();
}