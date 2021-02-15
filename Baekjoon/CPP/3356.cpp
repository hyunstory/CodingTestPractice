#include <iostream>
#include <vector>
#include <string>

using namespace std;

int n;

vector<int> nestedF(string s){
    int len_P = s.length();
	int idx = 0;
	vector<int> nested(len_P);
	for (int i = 1; i < len_P; i++)
	{
		while (idx > 0)
		{
			if (s[i] == s[idx])
			{
				break;
			}
			idx = nested[idx - 1];
		}
		if (s[i] == s[idx])
		{
			nested[i] = ++idx;
		}
	}
	return nested;
}
void solution(){
    cin >> n;

    string s;
    cin >> s;
    vector<int> answer = nestedF(s);

    cout << n - answer[n-1] << '\n';
    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}
