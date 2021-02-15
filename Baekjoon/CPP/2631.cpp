#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

const int MAX = 200;

int n;
int arr[MAX];
int dp[MAX + 1];

int lis(int start){
    int & ret = dp[start + 1];
    
    if (ret != -1) return ret;

    ret = 0;

    for (int next = start + 1; next < n; next++){
        if (start == -1 || arr[start] < arr[next]){
            int candi = 1+ lis(next);

            if (ret < candi) ret = candi;
        }

    }

    return ret;
}
void solution(){
    cin >> n;

    for (int i = 0; i < n; i++) cin >> arr[i];

    memset(dp, -1, sizeof(dp));

    cout << n - lis(-1) << '\n';

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}