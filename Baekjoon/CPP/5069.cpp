#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 15;


int t;
int n;

long long dp[MAX][6]; //idx, 방향

long long go (int idx, int dir){

    if (idx == n){
        return 1;
    }

    long long &ret = dp[idx][dir];

    if (ret != -1) return ret;
    ret = 0;

    

    for (int k = 0; k < 5; k++){
        ret += go(idx*2, k);
    }
    return ret;
}
void solution(){

    cin >> t;

    memset(dp, -1, sizeof(dp));


    while(t--){

        cin >> n;

        long long ret = 0;

        for (int i = 0; i < 6; i ++){
            ret += go(2, i);    
        }


        cout << ret << '\n';
    }


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;   
}