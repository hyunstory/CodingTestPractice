#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int INF = 987654321;
const int MAX = 100001;

int n;

int dp[MAX];

int go(int five, int two){

    int money = 5 * five + 2 * two;

    if (money > n) return INF;

    if (money == n) return 0;
    
    int &ret = dp[money];

    if (ret != -1) return dp[money];
    ret = INF;

    ret = min(go(five + 1, two) + 1, go(five, two + 1) + 1);

    return ret;
}
void solution(){

    cin >> n;

    memset(dp, -1, sizeof(dp));

    if (n % 5 != 0 && n % 2 != 0 && n < 5){
        cout << -1 << '\n';
        return;
    }

    int result = go(0, 0);
    if (result != INF) cout << go(0, 0) << '\n';
    else cout << -1 << '\n';

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}