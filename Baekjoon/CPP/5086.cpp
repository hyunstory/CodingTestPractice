#include <iostream>

using namespace std;

void solution(){

    while(true){
        int a, b;
        cin >> a >> b;
        if (a == 0 && b == 0) break;

        if (a < b && (b % a == 0)) cout << "factor" << '\n';
        else if(a > b && (a % b == 0)) cout << "multiple" << '\n';
        else cout << "neither" << '\n';
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);


    solution();

    return 0;
}