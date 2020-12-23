#include <iostream>
#include <vector>

using namespace std;

void solution(){

    int n, m;

    cin >> n >> m;


    vector<int> arr(n + 1, 0);

    for (int i = 0; i < n; i++){
        cin >> arr[i];
    }

    int left = 0;
    int right = 0;
    int sum = arr[0];
    int result = 0;


    while(left <= right && right < n && left < n){

        if (sum < m) sum += arr[++right];
        else if (sum == m){
            sum += arr[++right];
            result++;
        }
        else if (sum > m){
            sum -= arr[left++];
            
            // 넘어가게 되는 경우, left부터 다시 시작, sum도 초기화
            if (left > right && left < n){
                right = left;
                sum = arr[left];
            }
        }

    }

    cout << result << '\n';
    
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}