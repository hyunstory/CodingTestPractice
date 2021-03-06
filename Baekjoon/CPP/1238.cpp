#include <iostream>
#include <queue>
#include <cstring>
#include <vector>
#include <algorithm>

using namespace std;

int n, m, x;
const int MAX = 1001;
const int INTMAX = 987654321;

vector<pair<int, int> > node[MAX];
vector<int> student(MAX);

int dist1[MAX];
int dist2[MAX];

bool check[MAX];


void calOne(){


    for (int i = 1; i <= n; i++){

        if (i == x) continue;

        for (int i = 1; i <= n; i++){
            dist1[i] = INTMAX;
        }
        priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // 가중치, 노드번호


        pq.push({0, i});
        dist1[i] = 0;

        while(!pq.empty()){
            int cost = pq.top().first;
            int num = pq.top().second;
            pq.pop();

            for (auto k : node[num]){
                int next = k.first;
                int nCost = k.second;

                if (dist1[next] > cost + nCost){
                    dist1[next] = cost + nCost;
                    pq.push({dist1[next], next});
                }
            }
        }


        student[i] += dist1[x];
    }
    

}
void calTwo(){

    for (int i = 1; i <= n; i++){
            dist2[i] = INTMAX;
        }
    priority_queue < pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq; // 가중치, 노드번호


    pq.push({0, x});
    dist2[x] = 0;

    while(!pq.empty()){
        int cost = pq.top().first;
        int num = pq.top().second;
        pq.pop();

        for (auto k : node[num]){
            int next = k.first;
            int nCost = k.second;

            if (dist2[next] > cost + nCost){
                dist2[next] = cost + nCost;
                pq.push({dist2[next], next});
            }
        }
    }

    for (int i = 1; i <= n; i++){
        if (i == x) continue;

        student[i] += dist2[i];
    }

}


void solution(){

    cin >> n >> m >> x;

    for (int i = 0; i < m; i++){
        int a, b, t;

        cin >> a >> b >> t;
        
        node[a].push_back({b, t});
    }

    
    

    calOne();
    calTwo();

    int maxV = 0;

    for (int i = 1; i <= n; i++){
        if (i == x && student[i] == 0) continue;

        maxV = max(maxV, student[i]);        
    }

    cout << maxV << '\n';
    


}
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}