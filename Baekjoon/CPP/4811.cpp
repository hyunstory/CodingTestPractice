#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 31;

long long dp[MAX][MAX];

int n;
long long go(int w, int h){

    long long &ret = dp[w][h];
    if (ret) return ret;

    if (w == 0) return 1;

    ret = go(w - 1, h + 1);

    if (h > 0) ret += go(w, h - 1);

    return ret;
}
void solution(){

    while(true){
        cin >> n;

        if (n == 0) {break;}

        cout << go(n, 0) << '\n';

    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}