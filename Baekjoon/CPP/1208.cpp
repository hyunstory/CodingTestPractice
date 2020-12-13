// 부분 수열의 합!! 시간 아주 많이 단축할 수 있는 문제

// dfsleft, dfsright를 반반 나누어 다 더한 후, 더한 값을 벡터에 삽입하여
// 하나씩 값을 뺴보면서 계산한다.
// lower bound, upper bound 값으로 차이 값을 구해주면 구하고 싶은 값을 구할 수 있다!!!

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int n, s;
int arr[41];
long long result;

vector<int> a, b;

void dfsLeft(int depth, int sum) {

	sum += arr[depth];

	if (depth >= n / 2) return;

	if (sum == s) result++;

	a.push_back(sum);

	dfsLeft(depth + 1, sum - arr[depth]);
	dfsLeft(depth + 1, sum);

}

void dfsRight(int depth, int sum) {

	sum += arr[depth];

	if (depth >= n) return;

	if (sum == s) result++;

	b.push_back(sum);

	dfsRight(depth + 1, sum - arr[depth]);
	dfsRight(depth + 1, sum);

	

}

void solution() {

	cin >> n >> s;

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
	}

	dfsLeft(0, 0);
	dfsRight(n / 2, 0);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int a_size = a.size();

	for (int i = 0; i < a_size; i++) {

		int remain = s - a[i];

		int lower = lower_bound(b.begin(), b.end(), remain) - b.begin();
		int upper = upper_bound(b.begin(), b.end(), remain) - b.begin();

		result += upper - lower;



	}

	cout << result << '\n';
	

}
int main() {



	solution();

	return 0;
}