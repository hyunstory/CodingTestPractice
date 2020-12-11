#include <iostream>
#include <cmath>

using namespace std;

#define MAX 1001 // 문제에서 1000이하의 자연수
int N;

int input_arr[MAX]; // 입력 받을 자연수의 배열

bool Notsosu[MAX];  //소수가 아니라면 true, 소수가 맞다면 false

int result; // 총 개수

void calculate_sosu() {

	Notsosu[0] = true; // 0과 1은 소수가 아님으로 초기값 셋팅
	Notsosu[1] = true;

	int square_root = (int) sqrt(MAX - 1); // sqrt(N)까지만 계산
	for (int i = 2; i <= square_root; i++) {
		int num = i;
		
		if (Notsosu[i] == true) continue; // 이미 계산한 연산이라면 패스

		while (num < MAX - 1) { // 계산하는 최대 범위가 넘어갔을 때 break
			
			num += i;			//배수 구하기

			Notsosu[num] = true; // 배수들은 전부 true표시
		}
		
	}

}
void input() {

	cin >> N;
		
	for (int i = 0; i < N; i++) {
		cin >> input_arr[i];
	}
	
	calculate_sosu();


}
void solution() {

	for (int i = 0; i < N; i++) {

		if (!Notsosu[input_arr[i]]) result++;


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