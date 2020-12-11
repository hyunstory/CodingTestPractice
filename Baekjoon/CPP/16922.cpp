#include <iostream>

using namespace std;

#define input_max 20 + 1 //입력 최대
#define check_max 1100   // 나올 수 있는 누적합의 최대
#define char_count 4     // 문자열 총 4개
int n;

int cnt;

int a[input_max];
bool check[check_max];

bool validation() {

	int sum = 0;

	for (int i = 0; i < n; i++) {

		switch (a[i])
		{

		case 1: // 1일 때 문자열 1값
			sum += 1; 
			break;
		case 2: // 2일 때 문자열 5값
			sum += 5;
			break;
		case 3: // 3일 때 문자열 10값
			sum += 10;
			break;
		case 4: // 4일 때 문자열 50 값
			sum += 50;
			break;
			
		default:
			break;
		}
	}

	if (!check[sum]) {
		check[sum] = true;
		return true;
	}

	return false;


}
void dfs(int start, int dep) {

	if (dep == n) {
		
		if (validation()) cnt++;

		return;
	}

	for (int i = start; i < char_count; i++) {

		a[dep] = i + 1;

		dfs(i, dep + 1); // 자기 자신은 중복을 허용하기 때문에 i+1이 아닌 i로 셋팅
	}
}
void solution() {

	cin >> n;

	dfs(0, 0);


	cout << cnt << '\n';
	
}


int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}
