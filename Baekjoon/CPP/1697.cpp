#include <iostream>
#include <queue>
const int MAX = 100001;
using namespace std;
bool check[MAX];
int dist[MAX];





int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n, m;
	
	cin >> n >> m;

	check[n] = true; //먼저 시작하기 때문

	queue<int> q;
	q.push(n);

	while (!q.empty()) {
	
		int now = q.front();

		q.pop();

		if (now - 1 >= 0) {
			if (check[now - 1] == false) {
				q.push(now - 1);
				check[now - 1] = true;
				dist[now - 1] = dist[now] + 1;

			}
		}

		if (now + 1 <= m + 1) {
			if (check[now + 1] == false) {
				q.push(now + 1);
				check[now + 1] = true;
				dist[now + 1] = dist[now] + 1;

			}
			
		
		}

		if (2*now <= m + 1) {
			if (check[2 * now] == false) {
				q.push(2 * now);
				check[2 * now] = true;
				dist[2 * now] = dist[now] + 1;
			}
		
		}
	
	}
	

	cout << dist[m] << '\n';





	return 0;
}