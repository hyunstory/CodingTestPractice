#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k, n;

const int MAX = 10001;

vector<long long> v;

void solution(){

	cin >> k >> n;

	long long left = 1;
	long long right = 1; // 초기화

	for (int i = 0; i < k; i++){
		long long temp;
		cin >> temp;
		right = max(right, temp);
		v.push_back(temp);
	}

	

	int v_size = v.size();

	while( left <= right){ 
		long long mid = (left + right) / 2;

		// 시뮬레이션
		long long cnt = 0;
		for (int i = 0; i < v_size; i++){
			cnt += (long long) v[i] / mid;
		}

		if (cnt > n) left = mid + 1; 
		else if (cnt < n) right = mid - 1;  
		
		
	}

	cout << right << '\n';
}
int main(){

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}