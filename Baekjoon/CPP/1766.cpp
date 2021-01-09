#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n;
int ind[32001];

vector<int> vec[32001];

void solution(){

    int r;

    cin >> n >> r;

    for (int i = 0; i < r; i++){

        int a, b;

        cin >> a >> b;
        
        vec[a].push_back(b);

        ind[b]++;
        
    }

    priority_queue<int, vector<int>, greater<int> > pq;


    for (int i = 1; i <= n; i++){
        if (ind[i] == 0){
            pq.push(i);
        }
    }


    while(!pq.empty()){

        int next = pq.top();

        pq.pop();

        cout << next << ' ';

        for (int i = 0; i < vec[next].size(); i++){
            int t = vec[next][i];

            ind[t]--;

            if (ind[t] == 0) pq.push(t);
        }
    }



}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}