#include <iostream>
#include <cstring>

using namespace std;

int n, m, k;

const int NMAX = 10001;

int cost[NMAX];
int parent[NMAX];


int find(int x){
    if (parent[x] < 0) return x;
    
    return parent[x] = find(parent[x]);

}
void merge(int x, int y){
    x = find(x);
    y = find(y);

    if (x == y) return;

    if (cost[x] < cost[y]) parent[y] = x;
    else parent[x] = y;
}

void solution(){

    cin >> n >> m >> k;

    memset(parent, -1, sizeof(parent));

    for (int i = 1; i <= n; i++) cin >> cost[i];

    for (int i = 0;i < m; i++){
        int a, b;

        cin >> a >> b;
        merge(a, b);
        
    }

    int result = 0;

    for (int i = 1; i <= n; i++){
        if (parent[i] == -1) result += cost[i];
    }

    if (result > k) cout << "Oh no" << '\n';
    else cout << result << '\n';


    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}