/*
dfs나 bfs로 부모부터 자식까지 찾아주면서 cnt +1 해주면 된다

*/
#include <iostream>
#include <vector>

using namespace std;

int n, a, b, k;

vector<int> vec[101];
bool check[101];
int res;

void dfs(int start, int end, int cnt){


    check[start] = true;
    if (start == end){
        res = cnt;
        return;
    }


    for (int v = 0; v < vec[start].size(); v++){
        
        if (check[vec[start][v]]) continue;

        dfs(vec[start][v], end, cnt + 1);
    }

    

    
}
void solution(){
    cin >> n >> a >> b;

    cin >> k;

    for (int i = 0; i < k; i++){
        int one, two;
        cin >> one >> two;

        vec[one].push_back(two);
        vec[two].push_back(one);
    }

    dfs(a, b, 0);

    if (res == 0) cout << -1 << '\n';
    else cout << res << '\n';
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}