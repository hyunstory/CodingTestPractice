#include <iostream>
#include <deque>
#include <queue>
#include <algorithm>
#include <string>
#include <cstring>
#include <cstdio>

using namespace std;

#define input_max 25 + 1
#define dir 4

int n;
char map[input_max][input_max];
int dx[] = { -1, 1, 0, 0};
int dy[] = { 0, 0, -1, 1 };

deque<int> dq;

int house;
int bfs(int x, int y) {  // BFS 탐색

	queue<pair<int, int>> q;

	int cnt = 1;
	map[x][y] = '2';

	q.push(make_pair(x, y));

	while (!q.empty()) {

		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int k = 0; k < dir; k++) {

			int nx = x + dx[k];
			int ny = y + dy[k];

			if (nx >= 0 && nx < n && ny >= 0 && ny < n && map[nx][ny] == '1') {  // 방문하지 않은 곳 '1'만 찾음

				q.push(make_pair(nx, ny));
				map[nx][ny] = '2';  // 방문했기 때문에 '2'로 변환
				cnt++;
			}
		}
		
	}

	return cnt;  // 집의 넓이 총 개수를 반환시켜줌

	
}

void solution() {


	cin >> n;

	for (int i = 0; i < n; i++) {
		
		string str;
		cin >> str;
	
		strcpy(map[i], str.c_str());  // 문제 출제자는 띄워쓰기를 꼭 해주어서 다시 문제 내주시기를

	}

			


	

	for (int i = 0; i < n; i++) 
		for (int j = 0; j < n; j++) {

			if (map[i][j] == '1') {  // 1을 발견하면 BFS탐색을 합니다. 그리고 집을 찾았다는 의미로 house++을 합니다.
				house++;
				int cnt = bfs(i, j);

				dq.push_back(cnt);

			}
		}
	
	


	sort(dq.begin(), dq.end());  // 오름차순으로 정렬

	cout << house << '\n';  // house의 총 개수를 먼저 출력하고

	while (!dq.empty()) {
	
		
		cout << dq.front() << '\n';  // 오름 차순으로 정렬된 값들을 하나씩 출력

		dq.pop_front();

	}

}


int main() {


	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}