#include <iostream>
#include <vector>

using namespace std;

int n;

int arr[101];
vector<bool> check(101, false);
vector<int> result;

void dfs(int start, int cur){

    if(check[cur]){
        if (start == cur){
            result.push_back(start);
        }
        return;
    }

    check[cur] = true;
    dfs(start, arr[cur]);
    
}

void solution(){

    cin >> n;

    for (int i = 1; i <= n; i++){


        cin >> arr[i];
    }

    for (int i = 1; i <= n; i++){
        check = vector<bool> (101, false);
        dfs(i, i);
    }

    cout << result.size() << '\n';
    for (auto i : result){
        cout << i << '\n';
    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}