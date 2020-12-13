#include <iostream>
#include <deque>
#include <algorithm>
#include <cstring>


using namespace std;

#define MAX 101
#define OVER 400


int r, c, k;
int cnt;

int r_cnt = 3;
int c_cnt = 3;

int numCount[MAX];


int map[MAX][MAX];

deque<int> temp;




void solve() {



	while (cnt <= 100) {

		if (map[r][c] == k) break;

		deque<int>size;
		

		if (r_cnt >= c_cnt) {


			for (int i = 1; i <= r_cnt; i++) {
			
				deque<pair<int, int>> V;
				memset(numCount, 0, sizeof(numCount));
				for (int j = 1; j <= c_cnt; j++) numCount[map[i][j]]++;
				for (int j = 1; j < MAX; j++) {
				
					if (numCount[j] == 0) continue;
					V.push_back(make_pair(numCount[j], j));
				}

				sort(V.begin(), V.end());
				for (int j = 1; j <= c_cnt; j++) map[i][j] = 0;
				int idx = 1;

				for (int j = 0; j < V.size(); j++) {
				
					map[i][idx++] = V[j].second;
					map[i][idx++] = V[j].first;
				}

				idx--;
				size.push_back(idx);
			
			}

			sort(size.begin(), size.end());

			c_cnt = size.back();


		
		}
		
		else {

			//열 연산
		

			for (int i = 1; i <= c_cnt; i++) {
			
				deque<pair<int, int>>V;
				memset(numCount, 0, sizeof(numCount));
				for (int j = 1; j <= r_cnt; j++) numCount[map[j][i]]++;
				for (int j = 1; j < MAX; j++) {
				
					if (numCount[j] != 0) {
					
						V.push_back(make_pair(numCount[j], j));
					}
				}

				sort(V.begin(), V.end());
				for (int j = 1; j <= r_cnt; j++) map[j][i] = 0;
				int idx = 1;
				for (int j = 0; j < V.size(); j++) {
				
					map[idx++][i] = V[j].second;
					map[idx++][i] = V[j].first;
				}
				idx--;
				size.push_back(idx);


			}

			sort(size.begin(), size.end());
			r_cnt = size.back();
				
		
		}

		

		cnt++;
	
	
		
	

		
	
	}


	if (cnt > 100) cout << -1 << '\n';

	else cout << cnt << '\n';

}






int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int temp;


	cin >> r >> c >> k;

	for (int i = 1; i <= 3 ; i ++)
		for (int j = 1; j <= 3; j++) {
		
			cin >> map[i][j];

		
		}


	solve();









	return 0;
}