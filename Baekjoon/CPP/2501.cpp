#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> vec;


void solution(){

    int n, k;

    cin >> n >> k;

    for (int i = 1; i <= n; i++ ){
        if (n % i == 0) vec.push_back(i);
    }

    sort(vec.begin(), vec.end());

    if (vec.size() < k) cout << 0 << '\n';
    else cout << vec[k-1] << '\n';
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}