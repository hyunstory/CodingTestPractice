#include <iostream>
#include <queue>
#include <string>
using namespace std;


queue<int> q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int N, K;

	cin >> N >> K;

	cout << "<";

	for (int i = 0; i < N; i++) {
	
		q.push(i + 1);
	}

	while (!q.empty()) {
		int temp;

		for (int k = 0; k < K - 1; k++) {

			temp = q.front();
			
			q.pop();
			q.push(temp);
		}

		temp = q.front();
		q.pop();
		
		if (q.empty()) {
			cout << temp;
		}
		else {
			cout << temp << "," << " ";
		}
	
	
	}

	cout << ">";

	return 0;
}