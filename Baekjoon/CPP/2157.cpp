#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 301;
const int INF = 987654321;

int n, m, k;
int input[MAX];
int dp[MAX][MAX]; /// [해당 지점][M 카운트]
int dist[MAX][MAX];

int go(int start, int cnt){
    

    if (cnt >= m && start != n){
        
        return -INF;
    }
    if(start == n){
        return 0;
    }



    int &ret = dp[start][cnt];
    if (ret != -1) return ret;
    
    ret = -INF;

    for (int k = start + 1; k <= n; k++){
        if (dist[start][k]) ret = max(ret, dist[start][k] + go(k, cnt + 1));
    }

    return ret;
}
void solution(){
    cin >> n >> m >> k;

    for (int i = 0; i < k; i++){
        int from, to, bonus;
        cin >> from >> to >> bonus;

        dist[from][to] = max(dist[from][to], bonus);
    }

    memset(dp, -1, sizeof(dp));

    int ret = go(1, 1);
    if (ret > 0) cout << ret << '\n';
    else cout << 0 << '\n';


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}