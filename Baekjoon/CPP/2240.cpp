#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int t, w;
const int MAX = 1001;

int arr[MAX];
int dp[MAX][31][2];

int go(int time, int dir, int cnt){

    int &ret = dp[time][cnt][dir];
    if (ret != -1) return ret;
    ret = 0;

    if (arr[time] == dir + 1) ret += 1;
    
    
    if (time == t){
        if (arr[time] == dir + 1){
            return 1;
        } else return 0;
    }




    if (cnt == w){
        ret += go(time + 1, dir, cnt);
    }else {
        ret += max(go(time + 1, dir, cnt), go(time + 1, (dir + 1) % 2, cnt + 1));
    }

    return ret;
    
}
void solution(){
    cin >> t >> w;

    memset(dp, -1, sizeof(dp));

    for (int i = 1; i <= t; i++){
        cin >> arr[i];
    }

    int result = max(go(1, 0, 0), go(1, 1, 1)); // 맨 첫번째에 다른 나무로 가는 것도 고려해주어야한다.

    cout << result << '\n';
    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}