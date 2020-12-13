#include <iostream>
#include <queue>
#include <deque>
#include <string>
#include <cstring>

using namespace std;

#define MAX 10000
int t;

bool check[MAX];

void solution() {

	cin >> t;

	while (t--) {


		int start, end;
		cin >> start >> end;

		memset(check, false, sizeof(check));

		queue<pair<int, string>> q;

		q.push(make_pair(start, ""));
		check[start] = true;

		


		while (!q.empty()) {
		
			int num = q.front().first;
			string command = q.front().second;
			
			q.pop();

			if (num == end) {
				cout << command << '\n';
				break;
			}
			
			//D방향일 때
			int next_num = num * 2;
			if (next_num > 9999) next_num %= 10000;

			if (!check[next_num]) {
				check[next_num] = true;
				q.push(make_pair(next_num, command + "D"));
			}


			//S방향일 때
			next_num = num - 1;
			if (next_num < 0) next_num = 9999;

			if (!check[next_num]) {
				check[next_num] = true;
				q.push(make_pair(next_num, command + "S"));
			}

			//L방향일 때
			next_num = (num % 1000) * 10 + (num / 1000);
			if (!check[next_num]) {
				check[next_num] = true;
				q.push(make_pair(next_num, command + "L"));
			}

			//R방향일 때

			next_num = (num % 10) * 1000 + (num / 10);
			if (!check[next_num]) {
				check[next_num] = true;
				q.push(make_pair(next_num, command + "R"));
			}
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