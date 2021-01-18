#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

const int MAX = 1000001;

int dp[MAX];

int N;

void dpInit(){
    for (int i = 0; i < MAX; i++){
        dp[i] = -1;
    }
}

int getMinNum(int N){
    int &ret = dp[N];

    if (ret != -1) return ret;

    if (N == 1) return ret = 0;

    ret = __INT_MAX__;

    if (N % 3 == 0) ret = min(ret, getMinNum(N /3) + 1);

    if (N % 2 == 0) ret = min(ret, getMinNum(N / 2) + 1);

    ret = min(ret, getMinNum(N -1) + 1);

    return ret;

}

void print(int N){

    if (N == 0) return;

    cout << N << ' ';

    if (N % 3 == 0 && (dp[N] == dp[N / 3] + 1)) print(N /3);
    else if (N % 2 == 0 && (dp[N] == dp[N / 2] + 1)) print(N / 2);
    else if ( N - 1 >= 0 && (dp[N] == dp[N - 1] + 1)) print(N - 1);
}
void solution(){
    cin >> N;

    dpInit();

    cout << getMinNum(N) << '\n';
    
    print(N);


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}