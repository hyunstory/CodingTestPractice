#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void solution(){

    int n, m;

    int minV = __INT_MAX__;

    cin >> n >> m;


    vector<int> arr(n + 1, 0);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int sum = arr[0];
    int left = 0;
    int right = 0;

    while(left <= right && right < n && left < n){

        if (sum < m) sum += arr[++right];
        else if (sum >= m){
            
            minV = min(minV, (right - left + 1));
            
            sum -= arr[left++];

            if (left > right && left < n){
                right = left;
                sum = arr[left];
            }
        }
    }

    if (minV != __INT_MAX__) cout << minV << '\n';
    else cout << 0 << '\n';
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}