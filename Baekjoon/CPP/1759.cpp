#include<iostream>
#include<algorithm>
using namespace std;

char s[16];
char result[16];
int n, m;

void dfs(int start, int depth) {

	if (depth >= n) {
		int cnt_mo = 0;
		int cnt_ja = 0;
		for (int i = 0; i < n; i++) {
		
			if (result[i] == 'a' || result[i] == 'e' || result[i] == 'i' || result[i] == 'o' || result[i] == 'u') cnt_mo++;
			else cnt_ja++;
		}

		if (cnt_mo >= 1 && cnt_ja >= 2) {

			for (int i = 0; i < n; i++) {

				cout << result[i];

			}
			cout << '\n';
		}
		return;
	}

	for (int i = start; i < m; i++) {

		result[depth] = s[i];

		dfs(i + 1, depth + 1);

	}




}



int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);



	cin >> n >> m;

	for (int i = 0; i < m; i++) {

		cin >> s[i];
	}

	sort(s, s + m);


	dfs(0, 0);




	return 0;
}

