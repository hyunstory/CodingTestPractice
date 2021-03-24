#include <iostream>
#include <queue>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int t;
const int MAX = 10001;
vector< pair < int, int> > node[MAX];
int dist[MAX];

void solution(){
    cin >> t;

    while(t--){
        int n, d, c;
        cin >> n >> d >> c;

                // dist 초기화
        for (int i = 1; i <= n; i++){
            dist[i] = __INT_MAX__;
            node[i].clear();
        }
        

        for (int i = 0; i < d; i++){
            int a, b, c;
            cin >> a >> b >> c;

            node[b].push_back({a, c});
        }





        // priority_queue 정의

        priority_queue< pair<int, int>, vector< pair< int, int> >, greater<pair< int, int> > > pq;

        pq.push({0, c});
        dist[c] = 0;

        int _time = 0;

        while(!pq.empty()){
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if (dist[cur] < cost) continue;

            for (int k = 0; k < node[cur].size(); k++){
                int next = node[cur][k].first;
                int nCost = node[cur][k].second;

                if (dist[next] > cost + nCost){
                    dist[next] = cost + nCost;
                    pq.push({dist[next], next});
                }
            }

        }

        int cnt = 0;
        int maxV = 0;
        for (int i = 1; i <= n; i++){
            if (dist[i] != __INT_MAX__){
                cnt++;
                maxV = max(maxV, dist[i]);
                
            }
        }

        cout << cnt << ' ' << maxV << '\n';
        


    }

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}