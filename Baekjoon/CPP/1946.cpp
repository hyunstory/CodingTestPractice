#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int T, N;

int result = 1;

void input() {
	cin >> T;



}

vector<pair<int, int>> applicant;



void solution() {
	int a, b;


	for (int i = 0; i < T; i++) {

		applicant.clear();
	
		cin >> N;
		

		for (int j = 0; j < N; j++) {

			cin >> a >> b;
		
			applicant.push_back(make_pair(a, b));

			
		}

		sort(applicant.begin(), applicant.end());


		int interview =  applicant[0].second;

		for (int k = 0; k < N-1; k++) {

			if (interview > applicant[k + 1].second) {
			
				interview = applicant[k + 1].second;
				result++;
			}
			
		
			
			
		}

	
		cout << result << '\n';
		result = 1;
	}


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