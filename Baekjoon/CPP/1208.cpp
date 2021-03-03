#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int n, s;

const int MAX = 41;


int arr[MAX];

long long result;


vector<int> a;
vector<int> b;

void left_temp(int idx, int sum){

	if (idx >= n / 2) return;

	if (sum == s) result++;

	a.push_back(sum);

	left_temp(idx + 1, sum);
	left_temp(idx + 1, sum + arr[idx]);
	
}

void left(int idx, int sum){

	sum += arr[idx];

	if (idx >= n /2) return;

	if (sum == s) result++;

	a.push_back(sum);

	left(idx + 1, sum - arr[idx]);
	left(idx + 1, sum);

}
void right(int idx, int sum){

	sum += arr[idx];

	if (idx >= n) return;

	if (sum == s) result++;

	b.push_back(sum);

	right(idx + 1, sum - arr[idx]);
	right(idx + 1, sum);


}
void solution(){

	cin >> n >> s;

	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	


	left(0, 0);
	right(n/2, 0);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	int a_size = a.size();

	for (int i = 0; i < a_size; i++){

		int value = s - a[i];
		
		int upper = upper_bound(b.begin(), b.end(), value) - b.begin(); // 인덱스 위치를 알고 싶으면 begin을 빼주어야한다.
		int lower = lower_bound(b.begin(), b.end(), value) - b.begin();

		result += upper - lower;
		

	}

	cout << result << '\n';


}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}