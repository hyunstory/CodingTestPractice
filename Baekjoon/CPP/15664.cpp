#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;

int n, m;
vector<int > v;
int result[10];
int check[10];
map<int, int> numCount;

void dfs(int idx, int depth) {

	if (depth == m) {

		for (int i = 0; i < m; i++) {
			cout << v[check[i]] << ' ';
			
		}

		cout << '\n';
		return;
		
	}

	for (int i = 0; i < v.size(); i++) {

		
		if (numCount[v[i]]) {

			if (idx >= 1 && v[check[idx - 1]] > v[i]) continue;
			numCount[v[i]]--;

			check[idx] = i;

			dfs(idx + 1, depth + 1);

			numCount[v[i]]++;
			
		}
		

		
	}
}
void solution() {


	cin >> n >> m;

	for (int i = 0; i < n; i++) {
		int temp;
		cin >> temp;

		if (!numCount.count(temp)) {
			numCount[temp] = 1;
			v.push_back(temp);
		}
		else numCount[temp]++;

	}


	sort(v.begin(), v.end());
	dfs(0, 0);



}
int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();


	return 0;
}