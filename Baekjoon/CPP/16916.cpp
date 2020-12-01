#include <iostream>
#include <string>
#include <vector>

using namespace std;


vector<int> make_nested(string P);
vector<int> KMP(string S, string P);

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	string S, P;
	cin >> S >> P;
	vector<int>ans = KMP(S, P);
	if (ans.empty())
	{
		cout << 0;
	}
	else
	{
		cout << 1;
	}
	return 0;
}

vector<int> make_nested(string P)
{
	int len_P = P.length();
	int idx = 0;
	vector<int> nested(len_P);
	for (int i = 1; i < len_P; i++)
	{
		while (idx > 0)
		{
			if (P[i] == P[idx])
			{
				break;
			}
			idx = nested[idx - 1];
		}
		if (P[i] == P[idx])
		{
			nested[i] = ++idx;
		}
	}
	return nested;
}
vector<int> KMP(string S, string P)
{

	int idx = 0;
	int len_S = S.length();
	int len_P = P.length();
	vector<int>nested = make_nested(P);
	vector<int>ans;
	for (int i = 0; i < len_S; i++)
	{
		while (idx > 0)
		{
			if (S[i] == P[idx])
			{
				break;
			}
			idx = nested[idx - 1];
		}
		if(S[i]==P[idx])
		{
			if (idx == len_P - 1)
			{
				ans.push_back(i - (len_P - 1));
				idx = nested[idx];
			}
			else
			{
				idx++;
			}
		}
	}
	return ans;
}