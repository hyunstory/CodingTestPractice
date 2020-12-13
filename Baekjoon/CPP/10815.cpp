#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;


vector<int> card;
vector<int> compare;
vector<int> result;

bool find_value(int value) {

	int left = 0;
	int right = card.size() - 1;

	while (left <= right) {
		int mid = (left + right) / 2;

		if (card[mid] > value) {
			right = mid - 1;
		}
		else if (card[mid] < value) {
			left = mid + 1;
		}
		else {

			return true;
		}
	}

	return false;

}

void solution() {

	cin >> n;

	for (int i = 0; i < n; i++) {

		int temp;

		cin >> temp;

		card.push_back(temp);

	}

	cin >> m;
	

	for (int i = 0; i < m; i++) {
		int temp;
		cin >> temp;
		
		compare.push_back(temp);
	}

	sort(card.begin(), card.end());


	for (int i = 0; i < m; i++) {

		int value = compare[i];

		if (find_value(value)) result.push_back(1);
		else result.push_back(0);
	}
	

	for (int i = 0; i < m; i++) {
		cout << result[i] << ' ';
	}


}

int main() {

	solution();

	return 0;
}