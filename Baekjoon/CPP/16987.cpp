#include <iostream>
#include <algorithm>

using namespace std;

#define input_max 8 + 1

typedef struct egg{
	int power;
	int weight;
} Eggs;

int n;
int result;


Eggs eggs[input_max];

void dfs(int dep) {

	if (dep == n) {

		
		int sum = 0;

		for (int i = 0; i < n; i++) {
			if (eggs[i].power <= 0) sum++;
		}

		result = max(result, sum);

		return;
	}

	if (eggs[dep].power <= 0) return dfs(dep + 1);



	bool None_FLAG = false;



	for (int j = 0; j < n; j++) {
		int i = dep;

		if (i == j) continue;

		if (eggs[j].power > 0) {
			None_FLAG = true;

			
			eggs[i].power -= eggs[j].weight;
			eggs[j].power -= eggs[i].weight;

			dfs(dep + 1);

			eggs[i].power += eggs[j].weight;
			eggs[j].power += eggs[i].weight;
		}



	}

	if (!None_FLAG) return dfs(dep + 1);
		
}


void solution() {

	cin >> n;

	for (int q = 0; q < n; q++) {
		cin >> eggs[q].power;
		cin >> eggs[q].weight;
	}


	dfs(0);

	

	cout << result << '\n';
	
}
int main() {

	ios_base::sync_with_stdio(0);

	cin.tie(0);
	cout.tie(0);
	
	solution();

	return 0;
}