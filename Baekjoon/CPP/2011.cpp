#include <iostream>
#include <string>
#include <cstring>

using namespace std;
const int MAX = 5001;

int arr[MAX];
int dp[MAX], len;
string s;
int mod = 1000000;
int m = __INT_MAX__;

void solution(){

    cin >> s;

    len = s.length();

    for (int i = 1; i <= len; i++){
        arr[i] = s[i-1] - '0';
    }

    if (len == 1 && s[0] == '0'){
        cout << 0 << '\n';
        exit(0);
    }

    dp[0] = 1;

    for (int i = 1; i <= len; i++){
        if (arr[i] >= 1 && arr[i] <= 9){
            dp[i] = (dp[i-1] + dp[i]) % mod;

        }

        if (i == 1) continue;

        int temp = arr[i] + arr[i-1] * 10;
        if (temp >= 10 && temp <= 26){
            dp[i] = (dp[i-2] + dp[i]) % mod;
        }
    }

    

    cout << dp[len] << '\n';


}
int main(){

    solution();

    return 0;
}