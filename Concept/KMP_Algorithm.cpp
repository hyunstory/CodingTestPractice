/*
이현승
2020년12월05일토요일
이 알고리즘은 KMP알고리즘이며, 문자열을 비교할 때, 실패함수 테이블을 만들어
O(NM)으로 모든 문자열을 비교하지 않고, 접두사 접미사를 판별하여,
뛰어넘는 식으로 문자열을 비교하여 약 O(N + M)의 시간 복잡도가 나온다. 

비슷한 알고리즘으로는 라빈 카프 (문자열 해싱하여 하나씩 비교)가 있는데, 라빈 카프는 해쉬 충돌이 일어날 수 있어서,
해쉬 값이 같은 것의 경우, 하나씩 문자열을 비교해봐야한다. 시간복잡도는 이론상으로 O(N*1)이지만, 해쉬 충돌 및 계산 과정이 있어서 KMP보다 효율적이지는 못하다. 
문자열 파싱하는 알고리즘 중, 내가 아는 제일 빠른 알고리즘은 KMP O(N + M)이다.


cf) KMP는 pi함수로 실패 테이블을 만드는데 있어 O(M^3)이 걸릴 수 있지만, KMP검사 알고리즘을 비슷하게 비용하여
pi함수 즉, 실패테이블을 만들면 O(M)이 걸린다. KMP 문자열 찾는 알고리즘과 pi함수 만드는 알고리즘은 비슷하다.
*/

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