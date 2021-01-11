#include <iostream>
#include <vector>
#include <cstring>

using namespace std;


const int MAX = 20001;
vector<int> vertex[MAX];
int color[MAX]; // 0은 아직, 1,2는 색깔구별


int v, e;

void dfs(int k, int coloring){
    
    color[k] = coloring;

    for (int i = 0; i < vertex[k].size(); i++){
        int next = vertex[k][i];

        if (color[next] == 0){
            dfs(next, 3 - coloring);
        }
    }

}
bool isBigraph(){
    for (int i = 1; i <= v; i++){
        for (int j = 0; j < vertex[i].size(); j++){
            int next = vertex[i][j];
            if (color[i] == color[next]) return false;
        }
    }

    return true;

}
void solution(){
    int t;
    cin >> t;

    while(t--){

        memset(color, 0, sizeof(color));
        for (int i = 0; i < MAX; i++) vertex[i].clear();

        
        cin >> v >> e;

        for (int i = 0; i < e; i++){
            int a, b;
            cin >> a >> b;

            vertex[a].push_back(b);
            vertex[b].push_back(a);
        }

        for (int i = 1; i <= v; i++){
            if (color[i] == 0)dfs(i, 1);
        }

        if (isBigraph()) cout << "YES" << '\n';
        else cout << "NO" << '\n';


    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}