#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;


int N, M;

deque<int> plus_arr;
deque<int> minus_arr;

short FLAG = 1;



int max_value;
int result;


void input() {
	int temp;

	cin >> N >> M;

	for (int i = 0; i < N; i++) {
		cin >> temp;

		if (temp < 0) {
			temp = abs(temp);
			
			if (max_value < temp) {

				FLAG = 2;
				max_value = temp;
			}
			minus_arr.push_back(temp);


			


		}
		else {

			if (max_value < temp) {
				FLAG = 1;
				max_value = temp;
			}
			plus_arr.push_back(temp);



		}
	}

	


}

void solution() {

	//플러스 정렬
	sort(plus_arr.begin(), plus_arr.end());

	//마이너스 정렬
	sort(minus_arr.begin(), minus_arr.end());

	int cnt = 0;
	if (FLAG == 1) {
		//플러스가 최댓값

		result += plus_arr.back();

		for (int i = 0; i < M; i++) {
			if (plus_arr.empty()) break;
			plus_arr.pop_back();
		}

		while (!plus_arr.empty()) {
		
			if (cnt == M) {

				cnt = 0;
				continue;
			}
			else if (cnt == 0){
				result += 2 * plus_arr.back();
				plus_arr.pop_back();


			}
			else {

				plus_arr.pop_back();


			}

			cnt++;
			
		}
		
		cnt = 0;


		while (!minus_arr.empty()) {
		
			if (cnt == M) {
				cnt = 0;
				continue;

			}
			else if (cnt == 0) {

				result += 2 * minus_arr.back();
				minus_arr.pop_back();


			}
			else {

				minus_arr.pop_back();
			}

			cnt++;
		}


	}

	else {
		//마이너스가 최댓값


		result += minus_arr.back();

		for (int i = 0; i < M; i++) {
			if (minus_arr.empty()) break;
			minus_arr.pop_back();
		}

		while (!minus_arr.empty()) {

			if (cnt == M) {
				cnt = 0;
				continue;

			}
			else if (cnt == 0) {

				result += 2 * minus_arr.back();
				minus_arr.pop_back();


			}
			else {

				minus_arr.pop_back();
			}

			cnt++;
		}


		cnt = 0;



		while (!plus_arr.empty()) {

			if (cnt == M) {

				cnt = 0;
				continue;
			}
			else if (cnt == 0) {
				result += 2 * plus_arr.back();
				plus_arr.pop_back();


			}
			else {

				plus_arr.pop_back();


			}

			cnt++;

		}

	}

}
void solve() {

	input();
	solution();

	cout << result << '\n';
}


int main() {



	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);


	solve();




	return 0;
}