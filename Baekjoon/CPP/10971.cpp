#include <iostream>
#include <algorithm>
using namespace std;

#define input_max 10 + 1


int min_val = 1e9;
int selected[input_max];
int origin_num[input_max];
int input[input_max][input_max];
bool check[input_max];
int result;
int n;

void init() {

	for (int i = 0; i < 10; i++) {
		origin_num[i] = i + 1;
	}
}

void cal_tsp() {
	int sum = 0;
	for (int i = 0; i < n; i++) {

		int index = (i + 1) % n;
		
		int temp = input[selected[i] - 1][selected[index] - 1];

		if (temp == 0) {
			sum = 1e9; // 0을 갈 수 없는 길이니 최댓값을 넣으면 됩니다.
			break;
		}
		sum += input[selected[i]-1][selected[index]-1]; // -1을 하여 인덱스 번호에 접근합니다
	}

	

	min_val = min(min_val, sum);
}

void go(int depth) {

	if (depth == n) {

		cal_tsp();
		return;
	}

	for (int i = 0; i < n; i++) {

		if (check[i]) continue;

		check[i] = true;
		selected[depth] = origin_num[i];
		go(depth + 1);

		check[i] = false;
		
	}
}
void solution() {

	init();

	cin >> n;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
			cin >> input[i][j];

			
		}

	

	go(0);
	result = min_val;
	cout << result << '\n';
	
}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();


	return 0;
}