#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 100;
const int MAXCOST = 10001;

int n, m;
int mem[MAX];
int cost[MAX];
int dp[MAX][MAXCOST];

int go(int idx, int total){
    if (idx >= MAX) return 0;

    int &ret = dp[idx][total];

    if (ret != -1) return ret;

    ret = go(idx + 1, total);


    if (cost[idx] <= total) ret = max(ret, mem[idx] + go(idx + 1, total - cost[idx]));

    return ret;
}

void solution(){
    cin >> n >> m;

    for (int i = 0; i < n; i++) cin >> mem[i];
    for (int i = 0; i < n; i++) cin >> cost[i];

    memset(dp, -1, sizeof(dp));

    int total = 0;

    while(true){
        if (go(0, total) >= m){
            cout << total << '\n';
            break;
        }
        total++;
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}