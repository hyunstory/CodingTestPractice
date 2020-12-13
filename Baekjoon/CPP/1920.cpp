#include <iostream>
#include <algorithm>
#include <deque>

using namespace std;

int n, m;

deque<int> A;
deque<int> M;

void solution() {


	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;
		A.push_back(temp);
	}

	cin >> m;

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		M.push_back(temp);
		
	}
	

	sort(A.begin(), A.end());

	while (!M.empty()) {
	
		int value = M.front();
		M.pop_front();

		int left = 0;
		int right = A.size() - 1;
		
		bool ok_flag = false;

		while (left <= right) {


			int mid = (left + right) / 2;
			
			if (A[mid] < value) {
				left = mid + 1;
			}
			else if (A[mid] > value) {
				right = mid - 1;
			}
			else {
				cout << 1 << '\n';
				ok_flag = true;
				break;
			}
			
		}

		if (!ok_flag) {
			cout << 0 << '\n';
		}


	}

	
	


}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}