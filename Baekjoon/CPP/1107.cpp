#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>

using namespace std;

bool check[10];

int go(int n){

    if (n == 0){
        if (check[0]){
            return 0;
        }
        else return 1;
    }

    int len = 0;
    while( n > 0){
        if (check[n % 10]) return 0;
        n = n / 10;
        len += 1;
    }

    return len;
}


void solution(){

    int n;

    int m;

    cin >> n >> m;
    

    for (int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        check[temp] = true;

    }

    int result = abs(n - 100);

    for (int i = 0; i <= 1000000; i++){
        int c = i;
        int len = go(i);

        if (len > 0){
            int press = abs(c - n);
            if (result > press + len)
            result = press + len;
        }
    }

    

    cout << result << '\n';
    
}
int main(){


    solution();

    return 0;
}