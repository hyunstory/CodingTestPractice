#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

const int MAX = 123456 * 2 + 1;

vector<int> check(MAX ,false);

void getSosu(){

    check[0] = true;
    check[1] = true;

    int st = sqrt(MAX) + 1;

    for (int i = 2; i <= st; i++){
        for (int j = i * 2; j <= MAX; j += i){
            if (check[j]) continue;
            check[j] = true;
        }
    }



}
void solution(){

    getSosu();

    while(true){
        int n;
        cin >> n;
        int result = 0;
        if (n == 0) break;

        for (int i = n +1; i <= 2*n; i++){
            if (!check[i]) result++;
        }

        cout << result << '\n';
    }


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}