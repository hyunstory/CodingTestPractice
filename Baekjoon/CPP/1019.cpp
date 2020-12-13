#include <iostream>
#include <string>


using namespace std;

long long N;

long long num[10];

void input() {

	cin >> N;

}

void calc(long long n, long long ten) {
	while (n > 0) {
		num[n % 10] += ten;

		n /= 10;
	}
}


void solution(long long A, long long B, long long ten) {


	
	// A를 ++ 시키면서 0을 만든다.

	while (A % 10 != 0 && A <= B)

	{

		// A를 ++ 시킬때는 calc를 거쳐야한다.

		calc(A, ten);

		A++;

	}

	if (A > B) return;

	while (B % 10 != 9 && B >= A)

	{

		//B를 -- 시킬때는 calc를 거쳐야 한다.

		calc(B, ten);

		B--;

	}



	long long cnt = (B / 10 - A / 10 + 1);

	//B-A +1 * 자리수 만큼 0~9에 각각 더해준다.

	for (int i = 0; i < 10; ++i)

		num[i] += cnt * ten;



	// 다음자리 수를 계산위해 재귀함수 호출한다.

	solution(A / 10, B / 10, ten * 10);

	


}


void solve() {

	input();
	solution(1, N, 1);

	for (int i = 0; i <= 9; i++) {
		cout << num[i] << ' ';

	}

}

int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();




	return 0;
}