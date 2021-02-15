#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 501;

const int INF = 0x3f;
int n;
int dp[MAX][MAX];
int cost[MAX];
int sum[MAX];
int dpf(int tx, int ty){
    
    int &ret = dp[tx][ty];

    if (ret != 0x3f3f3f3f) return ret;

    if (tx == ty) return ret = 0;

    if (tx + 1 == ty) return ret = cost[tx] + cost[ty];

    for (int mid = tx; mid < ty; ++mid){
        int left = dpf(tx, mid);
        int right = dpf(mid + 1, ty);

        ret = min(ret, left + right);
    }

    return ret += sum[ty] - sum[tx - 1];
}
void solution(){
    int t;

    cin >> t;

    while(t--){
        memset(dp, 0x3f, sizeof(dp));

        cin >> n;

        for (int i = 1; i <= n; i++){
            cin >> cost[i];
            sum[i] = sum[i - 1] + cost[i];
        }
        cout << dpf(1, n) << '\n';
        
    }

}
int main(){ 

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}