#include <iostream>
#include <deque>

using namespace std;

#define input_max 50 + 1


deque<int> b(input_max);

int n;

int result;

void solution() {

	cin >> n; 
	

	for (int i = 0; i < n; i++) cin >> b[i]; // 입력


	bool null_FLAG = false;     //모든 배열이 0인지확인하는 FLAG, default는 true
	bool allEven_FLAG = false;  // 모든 배열이 짝수인지 확인하는 FLAG, default는 true


	while (1) {

		null_FLAG = true;       // default true 설정
		allEven_FLAG = true;    // default true 설정

		for (int i = 0; i < n; i++) {

			if (b[i]) null_FLAG = false;     //n번까지 돌았는데 모든 배열이 0이면 true를 계속 유지할 것임. 값이 있는 걸 찾으면 false표시

			if (b[i] % 2) {       // 배열의 값이 짝수가 아닐 때
				result++;         // 1을 빼주는 연산을 해야하기 때문에 카운트 1증가
				b[i] -= 1;        // 1을 빼줌
				allEven_FLAG = false;   // 모든 배열이 짝수가 아니라는 의미, false
			}
		}

		if (null_FLAG) break;          // 모든 배열이 0일 때 즉, 값이 있는 것을 발견하지 못했을 때 while루프를 빠져나옴


		if (allEven_FLAG) {
			for (int i = 0; i < n; i++) b[i] /= 2;        // 모든 배열의 값이 짝수일 때, 2로 나누어주고 카운트 1증가
			
			result++;
		}
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