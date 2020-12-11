#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

#define input_max 8 + 1
int n;

int a[input_max];
int selected[input_max];
bool check[input_max];

int result;


void cal_max() {

	int sum = 0;

	for (int i = 0; i < n - 1; i++) {

		sum += abs(selected[i] - selected[i + 1]);
	}

	result = max(sum, result);
}

void go(int depth) {

	if (depth == n) {


		cal_max();

		return;
	}


	for (int i = 0; i < n; i++) {

		if (check[i]) continue;

		check[i] = true;
		selected[depth] = a[i];
		go(depth + 1);
		check[i] = false;
	}


	
}
void solution() {

	cin >> n;

	for (int i = 0; i < n; i++) {

		cin >> a[i];

	}

	go(0);


	cout << result << '\n';
	

}

int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}