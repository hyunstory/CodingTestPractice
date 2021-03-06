#include <iostream>
#include <vector>
#include <string>

using namespace std;

vector<int> getPI(string p){
	int idx = 0;
	int p_len = p.length();
	vector<int>nested(p_len, 0);

	for (int i = 1; i < p_len; i++){
		while(idx > 0){
			if (p[i] == p[idx]) break;
			idx = nested[idx - 1];
		}

		if (p[i] == p[idx]) nested[i] = ++idx;
	}

	return nested;
}


void solution(){

	string s;
	string p;

	getline(cin, s, '\n');
	getline(cin, p, '\n');

	vector<int> nested = getPI(p);

	int idx = 0;
	vector<int> ans;
	int s_len = s.length();
	int p_len = p.length();

	for (int i = 0; i < s_len; i++){
		while(idx > 0){
			if (s[i] == p[idx]) break;
			idx = nested[idx - 1];
		}

		if (s[i] == p[idx]){
			if (idx == p_len - 1){
				ans.push_back(i - (p_len - 1));
				idx = nested[idx];
			}
			else idx++;
		}
	}


	if (!ans.empty()) cout << 1 << '\n';
	else cout << 0 << '\n';
}

int main(){


	solution();

	return 0;
}