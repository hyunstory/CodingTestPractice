#include <iostream>

using namespace std;

#define MAX 8 + 1

int n;
int a[MAX];
int ans[MAX];
bool check[MAX];


void print() {


	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';
}
void go(int depth) {

	if (depth == n) {

		print();

		return;
	}

	for (int i = 0; i < n; i++) {

		if (check[i]) continue;

		ans[depth] = a[i];
		check[i] = true;
		go(depth + 1);
		check[i] = false;

	}
}

void solution() {

	cin >> n;

	for (int i = 0; i < n; i++) {
		a[i] = i + 1;
	}

	
	go(0);

}
int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	//freopen("Input.txt", "r", stdin);

	solution();


	return 0;
}