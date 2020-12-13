#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int networks[101][101];

int n, m;
int result;
bool check[101];

void dfs(int idx) {


	check[idx] = true;

	for (int i = 1; i <= n; i++) {

		if (i == idx ) continue;

		if (networks[idx][i] == 0 || check[i]) continue;

		
		dfs(i);
		result++;
			
	}

	

}
void solution() {

	cin >> n >> m;


	for (int i = 0; i < m; i++) {
		int temp1, temp2;

		cin >> temp1 >>  temp2;

		networks[temp1][temp2] = 1;
		networks[temp2][temp1] = 1;
	}

	
	dfs(1);
	
	cout << result << '\n';
}
int main() {

	solution();

	return 0;
}