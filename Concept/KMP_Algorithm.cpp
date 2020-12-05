#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

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

    /* 실패 함수 만들어주기 */
	vector<int>nested = make_nested(P);

    /* 정답 벡터 */
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


void solution(){
    string a;
    string cmp;


    /* 전체 문자열 입력  */
    getline(cin, a, '\n');

    /* 비교할 문자열 입력 */
    getline(cin, cmp, '\n');


    /* KMP 알고리즘으로 문자열 비교 후, ans벡터에 찾은 문자열 인덱스 저장 */
    vector<int>ans = KMP(a, cmp);

    
    /* 찾은 문자열 개수 출력하기 */
    cout << ans.size() << '\n';

    /* 찾은 문자열 인덱스 출력하기, 1개 낮게 출력하기 떄문에 +1 해주기 */
    for (int i = 0; i < ans.size(); i++){
        cout << ans[i] + 1<< '\n';
    }


}
int main(){

    solution();


    return 0;

}