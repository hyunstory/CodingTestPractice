#include <iostream>
#include <cstring>
#include <algorithm>
#include <cmath>

using namespace std;

const int MAX = 100001;
const int LRMAX = 5;

int dp[MAX][LRMAX][LRMAX];

int arr[MAX];

int iddd = 1;

int calCost(int from, int to){

    if (from == 0) return 2;
    else if (from == to) return 1;
    else if (abs(from - to) == 2) return 4;
    else return 3;

}
int go(int idx, int left, int right){
    if (idx == iddd - 1) return 0;

    if ((left != 0 && right != 0) && left == right) return 987654321;

    int &ret = dp[idx][left][right];

    if (ret != -1) return ret;

    int cost = 0;
    //왼쪽 발을 해당위치에 옮겼을 때
    cost = calCost(left, arr[idx + 1]);
    ret = go(idx + 1, arr[idx + 1], right) + cost;

    //오른쪽 발을 옮겼을 때
    cost = calCost(right, arr[idx + 1]);
    ret = min(ret, go(idx + 1, left, arr[idx + 1]) + cost);

    //cout << ret << ' ';
    return ret;
}

void solution(){
    

    int n;

    while(true){
        cin >> n;

        if (n == 0) break;
        arr[iddd++] = n;
    }

    //iddd--;

    cout << go(0, 0, 0) << '\n';





}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    memset(dp, -1, sizeof(dp));

    solution();


    return 0;
}