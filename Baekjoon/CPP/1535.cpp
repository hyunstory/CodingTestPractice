#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 21;

int n;

int health[MAX];
int joy[MAX];
int dp[101][MAX]; // 체력, 사람 몇번째


int go(int p, int h){


    int &ret = dp[h][p];
    if (ret != 0) return ret;

    if (p >= n + 1) return 0;

    ret = h - health[p] > 0 ? max(go(p + 1, h - health[p]) + joy[p], go(p + 1, h)) : go(p + 1, h);

    return ret;


}
void solution(){

    cin >> n;

    //memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= n; i++){
        cin >> health[i];
    }
    for (int i = 1; i <= n; i++){
        cin >> joy[i];
    }

    cout << go(0, 100) << '\n';
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}