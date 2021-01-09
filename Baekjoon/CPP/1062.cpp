/*
정답까지 잘 갔지만...
dfs(idx + 1, i + 1)을
dfs(idx + 1, start + 1)해서 틀린부분 찾는다고 질질끈 문제..

시간복잡도 계산과 구현 방법을 정말 잘했는데..정말 어이없는 부분에서 틀렸음...ㅠ

dfs 순열, 조합 구하는 알고리즘을 매번 연습해서 칼이 닳도록 항상 갈아놓아야함..ㅠㅠ
화이팅!
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

vector<string> strs;
bool check[27];
string strs[50];
int n, k;

int maxV;

void simul(){
    int count = 0;

    for (int i = 0; i < n; i++){
        string a = strs[i];
        bool flag = true;

        for (int j = 0; j < a.length(); j++){
            if (!(check[a[j] - 'a'])) {
                flag = false;
                break;
            }

        }

        if (flag) count++;
    }

    maxV = max(maxV, count);
}

void dfs(int idx, int start){
    if (idx == k - 5){
        simul();

        return;
    }

    for (int i = start; i < 26; i++){
        if (check[i]) continue;

            check[i] = true;
            dfs(idx + 1, start + 1);
            check[i] = false;
    }
}
void solution(){


    cin >> n >> k;

    check['a' - 'a'] = true;
    check['n' - 'a'] = true;
    check['t' - 'a'] = true;
    check['i' - 'a'] = true;
    check['c' - 'a'] = true;

    for (int i = 0; i < n; i++){
        string a;

        cin >> a;

        a = a.substr(4, a.length());
        for (int j = 0; j < 4; j++){
            a.pop_back();
        }
        strs.push_back(a);

        

    }

    if (k < 5){
        cout << 0 << '\n';
        return;
    }
    else if(k == 26){
        cout << n << '\n';
        return;
    }

    dfs(0, 0);

    cout << maxV << '\n';
    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}