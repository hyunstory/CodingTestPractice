#include <iostream>
#include <algorithm>
#include <iostream>

using namespace std;

const int MAX = 10001;

int n;
int cards[MAX];
int dp[MAX];

void solution(){
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> cards[i];
    }

    dp[1] = cards[1];

    for (int i = 2; i <= n; i++){
        dp[i] = cards[i]; // 초기값을 안넣어주면 최솟값은 항상 0일수 밖에 없다...max값을 구하는 경우 안넣어도 자연스럽게 찾게 되어있다..양수기 때문에
        for (int j = 1; j <= i; j++){
            dp[i] = min(dp[i], dp[i-j] + cards[j]);
        }
    }

    cout << dp[n] << '\n';

    

    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}