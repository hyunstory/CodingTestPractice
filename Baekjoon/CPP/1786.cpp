#include <iostream>
#include <vector>
#include <string>

using namespace std;


vector<int> pi(string p){
	int p_len = p.length();
	int idx = 0;

	vector<int> nested(p_len, 0);

	for (int i = 1; i < p_len; i++){

		while(idx > 0){
			if (p[i] == p[idx]) break;
			idx = nested[idx - 1];
		}

		if (p[i] == p[idx]) nested[i] = ++idx;



	}


	return nested;
}

vector<int> KMP(string s, string p){

	int s_len = s.length();
	int p_len = p.length();
	int idx = 0;

	vector<int> ans;

	vector<int> nested = pi(p);

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


	return ans;

}

void solution(){

	string s;
	string p;

	getline(cin, s, '\n');
	getline(cin, p, '\n');

	vector<int> ans = KMP(s, p);

	int ans_size = ans.size();

	cout << ans_size << '\n';
	for (int i = 0; i < ans_size; i++){
		cout << ans[i] + 1 << '\n';
	}

}

int main(){


	solution();

	return 0;
}