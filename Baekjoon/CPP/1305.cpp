#include <iostream>
#include <vector>
#include <string>

using namespace std;

void solution(){

    
    int n;
    string p;

    cin >> n >> p;

    int idx = 0;
    vector<int> nested(n, 0);

    for (int i = 1; i < n; i++){
        while(idx > 0){
            if (p[i] == p[idx]) break;
            idx = nested[idx - 1];
        }
        if (p[i] == p[idx]) nested[i] = ++idx;
    }

    cout << n - nested[n - 1] << '\n';

}
int main(){


    solution();

    return 0;
}