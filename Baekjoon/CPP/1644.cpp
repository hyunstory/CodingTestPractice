#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


vector<bool> check(4000001, false);
//bool check[250001];
vector<int> v;
void getSosu(){

    check[0] = true;
    check[1] = true;

    for (int i = 2; i <= 2000; i++){
        for (int j = i *2; j <= 4000000; j += i){
            if (check[j]) continue;
            check[j] = true;
        }
    }
}
void solution(){
    int n;
    cin >> n;

    getSosu();

    for (int i = 2; i <= 4000000; i++){
        if (!check[i]) v.push_back(i);
    }
    int result = 0;

    //sort(v.begin(), v.end());

    int sum = v[0];
    int left = 0;
    int right = 0;

    while(left <= right && v[left] <= n && right < v.size()){
        if (sum < n) sum += v[++right];
        else if(sum == n) {
            result++;
            sum += v[++right];
        }
        else if(sum > n){
            sum -= v[left++];
            if (left > right && left < v.size()){
                sum = v[left];
                right = left;
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