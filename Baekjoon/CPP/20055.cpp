#include <iostream>
#include <deque>

using namespace std;


int n, k, Start, End, cnt, result;

int belt[300];
bool check[300];

deque<int> robot;
void move_belt() {
	Start--;
	End--;

	if (Start < 1) Start = 2 * n;
	if (End < 1) End = 2 * n;
}

void move_robot() {

	int size = robot.size();

	for (int i = 0; i < size; i++) {

		int cur = robot.front();
		check[cur] = false;

		robot.pop_front();

		if (cur == End) continue;

		int next = cur + 1;

		if (next > 2 * n) next = 1;

		if (belt[next] >= 1 && check[next] == false) {
			belt[next]--;
			if (belt[next] == 0) cnt++;

			if (next == End) continue;

			check[next] = true;
			robot.push_back(next);

		}
		else {
			check[cur] = true;
			robot.push_back(cur);
		}
	}



}

void make_robot() {

	if (check[Start] == false && belt[Start] >= 1) {
		check[Start] = true;
		belt[Start]--;
		robot.push_back(Start);

		if (belt[Start] == 0) cnt++;


	}

}

void solution() {

	cin >> n >> k;

	for (int i = 1; i <= 2 * n; i++) cin >> belt[i];


	Start = 1;
	End = n;

	while (cnt < k) {
		result++;

		move_belt();
		move_robot();
		make_robot();
	}

	cout << result << '\n';

}

int main() {

	solution();

	return 0;
}