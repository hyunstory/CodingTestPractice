#include <iostream>

using namespace std;


void solution(){

    long long t, a, b;

    cin >> t;

    while(t--){

        cin >> a >> b;

        long long temp = a % 10;
        

        for (long long i = 0; i < b - 1; i++){
            temp = (temp*a)%10;
            

        }

        if (temp == 0) temp = 10;
        cout << temp << '\n';
    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}