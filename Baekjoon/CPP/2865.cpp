#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

vector<float> max_point;



enum {

	MAX = 101
};
int N, M, K;

float point[MAX];
float max_temp[MAX];

void input() {

	cin >> N >> M >> K;

	int num;
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++) {
			cin >> num;
			cin >> point[num];

			float temp = max_temp[num];

			if (point[num] > temp) max_temp[num] = point[num];

		}

	


}

void solution() {

	for (int i = 1; i <= N; i++) {

		max_point.push_back(max_temp[i]);
		
		

	}

	sort(max_point.begin(), max_point.end());

	float result = 0.0;
	for (int i = 0; i < K; i++) {

		result += max_point.back();
		max_point.pop_back();
		
	}
	cout << fixed;
	cout.precision(1);
	cout << result << '\n';



}



void solve() {


	input();
	solution();



}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solve();




	return 0;
}