#include <iostream>

using namespace std;

void solution(){
    int n;

    cin >> n;

    int cnt = 0;
    while (n != 0){
        
        if ((n % 2) == 1) cnt ++;

        n /= 2;

        
    }

    cout << cnt << '\n';

}

int main(){


    solution();

    return 0;
}