#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[33000];
int ind[33000];

void solution(){
    int n, m;

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int first, second;
        cin >> first >> second;

        a[first].push_back(second);
        ind[second]++;
    
    }
    queue<int> q;

    for (int i = 1; i <= n; i++){
        if (ind[i] == 0){
            q.push(i);
        }
    }

    while(!q.empty()){

        int node = q.front();
        q.pop();

        cout << node << ' ';
        
        int node_size = a[node].size();

        for (int i = 0; i < node_size; i++){

            int y = a[node][i];

            ind[y]--;

            if(ind[y] == 0){
                q.push(y);
            }

        }

    }

    cout << '\n';
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;

}