#include<iostream>
#include<queue>

using namespace std;

int n;

char normal[101][101];
char ordi[101][101];
char tmp;
bool check_normal[101][101];
bool check_ordi[101][101];
int cnt_normal = 0;
int cnt_ordi = 0;
char letter;

int dx[] = { -1, 0, 1, 0 };
int dy[] = { 0, 1, 0, -1 };

void normal_person() {

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {
		
			if (check_normal[i][j] == false) {
				
				cnt_normal++;
				check_normal[i][j] = true;
				q.push(make_pair(i, j));
				letter = normal[i][j];

				while (!q.empty()) {
				
					int x = q.front().first;
					int y = q.front().second;

					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (0 <= nx && nx < n && 0 <= ny && ny < n) {
						
							if (normal[nx][ny] == letter && check_normal[nx][ny] == false) {
							
								check_normal[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}
					
						
					}
				

				}






			}
			
		}

	

	



	

	


}

void ordi_person() {

	queue<pair<int, int>> q;

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++) {

			if (check_ordi[i][j] == false) {

				cnt_ordi++;
				check_ordi[i][j] = true;
				q.push(make_pair(i, j));
				letter = ordi[i][j];

				while (!q.empty()) {

					int x = q.front().first;
					int y = q.front().second;

					q.pop();

					for (int i = 0; i < 4; i++) {
						int nx = x + dx[i];
						int ny = y + dy[i];

						if (0 <= nx && nx < n && 0 <= ny && ny < n) {

							if (ordi[nx][ny] == letter && check_ordi[nx][ny] == false) {

								check_ordi[nx][ny] = true;
								q.push(make_pair(nx, ny));
							}
						}


					}


				}






			}

		}






}



int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin >> n;

	for(int i = 0;i<n;i++)
		for (int j = 0; j < n; j++) {
			cin >> tmp;

			normal[i][j] = tmp;

			if (tmp == 'R' || tmp == 'G') {
				ordi[i][j] = 'R';
				continue;
			}

			ordi[i][j] = tmp;
			
			
			
		}

	normal_person();
	ordi_person();
	
	cout << cnt_normal << ' ' <<cnt_ordi << '\n';





		return 0;
}