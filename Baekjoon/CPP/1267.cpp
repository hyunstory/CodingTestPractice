#include <iostream>

using namespace std;


void solution(){

    int n;
    int a[21];

    cin >> n;

    int M, Y, sumM = 0 , sumY = 0;

    for (int i = 0; i < n; i++){
        cin >> a[i];
    }

    for (int i = 0; i < n; i++){
        // 영식

        sumY += (a[i]/30) + 1;

    }
    for (int i = 0; i < n; i++){
        sumM += (a[i]/60) + 1;
    }

    Y = sumY * 10;
    M = sumM * 15;

    if (Y == M){
        cout << "Y " << "M " << Y << '\n';
    }
    else if ( Y > M){
        cout << "M " << M << "\n";
    }
    else cout << "Y " << Y << '\n';

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}