#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int n, m;
int m_tmp;

int result = 10000; int x;
int temp;
int y;

int mini = 10000;
int k;



vector<pair<int, int>> house;
vector<pair<int, int>> chick;

int idx[20];

void find_chick(int start, int depth) {
	int chick_size = chick.size();



	if (depth == m_tmp) {
		int house_size = house.size();
		temp = 0;

		int distance = 10000;
		for (int i = 0; i < house_size; i++) {

				x = house[i].first;
				y = house[i].second;

				mini = 10000;


			for (int j = 0; j < m_tmp; j++) {

				k = idx[j];

				int cx = chick[k].first;
				int cy = chick[k].second;

				distance = abs(x - cx) + abs(y - cy);

				mini = min(mini, distance);


			}

			temp += mini;

		}

		result = min(temp, result);

		return;
	}

	for (int i = start; i < chick_size; i++) {
	
		idx[depth] = i;
		find_chick(i + 1, depth + 1);
	}








}


void solve() {


	for (int i = 1; i <= m; i++) {
		m_tmp = i;
		find_chick(0, 0);

	}
	
	//find_chick(0, 0);





	cout << result << '\n';

}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n >> m;
	

	int temp;

	int cnt = 0;


	for(int i = 1;i <= n;i++)
		for (int j = 1; j <= n; j++) {

			
		
			cin >> temp;
			if (temp == 1) {
			
				//집에 대한 정보를 푸쉬
				house.push_back(make_pair(i, j));

			}
			else if (temp == 2) {
			
				//치킨집에 대한 좌표를 푸쉬
				idx[cnt] = cnt; //DFS 순열 구하기 위해 인덱스를 임의 저장
				cnt++;
				chick.push_back(make_pair(i, j));
			}

		}



	solve();



	return 0;
}