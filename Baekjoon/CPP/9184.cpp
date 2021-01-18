#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 21;

int dp[MAX][MAX][MAX];

int w(int a, int b, int c){

    if (a <= 0 || b <= 0 || c <= 0) return 1;

    if (a >= MAX || b >= MAX || c >= MAX) return w(20, 20, 20);

    
    int &ret = dp[a][b][c];
    if (ret != -1) return ret;

    if ( a < b && b < c) ret = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);


    else ret = w(a-1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);

    return ret;
    

}
void solution(){

    memset(dp, -1, sizeof(dp));

    while(1){
        int a, b, c;
        cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1) break;
        cout << "w(" << a << ", " << b << ", " << c << ") = " << w(a, b, c) << endl;
        
    }

}
int main(){

    solution();

    return 0;
}
