#include <iostream>

using namespace std;


#define MAX 1001
int N;
int arr[MAX];
int d[MAX];
int result;

void solution() {

	cin >> N;

	for (int i = 1; i <= N; i++) {

		cin >> arr[i];
	}

	for (int i = 1; i <= N; i++) {
		d[i] = arr[i];
		for (int j = 1; j < i; j++)
			if (arr[j] < arr[i] && d[i] < d[j] + arr[i]) d[i] = d[j] + arr[i];

		if (result < d[i]) result = d[i];
	}


	cout << result << '\n';



}


int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solution();


	return 0;
}