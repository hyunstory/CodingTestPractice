#include<iostream>
#include<queue>
#include<algorithm>
#include<cstring>


using namespace std;

int box[101][101];
int tmp[101][101];
int n;
int height;
int cnt, result = 1;
bool check[101][101];
int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };
queue<pair<int, int>> q;


void print() {

	cout << result;
}

void copyBox() {

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) 
			if(box[i][j] > height)
			tmp[i][j] = box[i][j];


}

void go() {

	cnt = 0;

	

	for(int i = 0;i<n;i++)
		for (int j = 0; j < n; j++) {


			if (tmp[i][j] != 0 && !check[i][j]) {
				cnt++;
				check[i][j] = true;
				q.push(make_pair(i, j));
				
				while (!q.empty()) {

					int x = q.front().first;
					int y = q.front().second;
					q.pop();
				

					for (int k = 0; k < 4; k++) {



						int nx = x + dx[k];
						int ny = y + dy[k];

						if (0 <= nx && nx < n && 0 <= ny && ny < n) {
							if (!check[nx][ny] && tmp[nx][ny]) {
								check[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					

						
					}


					
				}
			}
			result = max(cnt, result);
			
		}



	

}






int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);



	cin >> n;


	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) cin >> box[i][j];

	

	for (int i = 1; i <= 100; i++) {
		height = i;

		copyBox();

		go();
		memset(check, false, sizeof(check));
		memset(tmp, 0, sizeof(tmp));
	}

	print();



		return 0;
}