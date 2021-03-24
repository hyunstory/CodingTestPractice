#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 501;

int duration[MAX];
int result[MAX];
int ind[MAX];
vector<int>node[MAX];
int n;


void solution(){
    cin >> n;

    for (int i = 1; i <= n; i++){
        cin >> duration[i];

        while(true){
            int tt;
            cin >> tt;

            if (tt == -1) break;

            node[tt].push_back(i);
            ind[i]++;
        }
    }

    queue<int> q;

    for (int i = 1; i <= n; i++){
        if(!ind[i]) q.push(i);
    }

    while(!q.empty()){
        int v = q.front();
        q.pop();

        for (int i = 0; i < node[v].size(); i++){
            int next = node[v][i];

            result[next] = max(result[next], result[v] + duration[v]);

            if(--ind[next] == 0) q.push(next);
        }
    }

    for (int i = 1; i <= n; i++) cout << result[i] + duration[i] << '\n'; // 마지막으로 자기 자신의 시간을 더해서 최종 걸리는 시간을 구할 수 있다.



}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}