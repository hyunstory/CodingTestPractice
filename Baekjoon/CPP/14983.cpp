#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, r;

const int MAX = 101;

vector<pair<int, int> > node[MAX]; // pair to저짐, 가중치
vector<int> items(MAX);

int dist[MAX];

bool check[MAX];

int result;

void solution(){

    cin >> n >> m >> r;

    for (int i = 1; i <= n; i++){
        int temp;
        cin >> temp;
        items[i] = temp;
    }

    for (int i = 0; i < r; i++){
        int a, b, c;

        cin >> a >> b >> c;

        node[a].push_back({b, c});
        node[b].push_back({a, c});

    }

    

    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    // 각 노드마다 시작해서 최대 아이템 개수를 기록한다.

    for (int i = 1; i <= n; i++){

        // 거리 무한대로 초기화
        for (int i = 0; i < MAX; i++){
            dist[i] = __INT_MAX__;
        }
        // 아이템 체크 초기화
        memset(check, false, sizeof(check));

        int itemCnt = 0;

        
        pq.push({0, i});
        dist[i] = 0;

        while(!pq.empty()){
            int cost = pq.top().first;
            int cur = pq.top().second;
            pq.pop();

            if (!check[cur])itemCnt += items[cur];

            check[cur] = true;

            for (int k = 0; k < node[cur].size(); k++){
                int nCost = node[cur][k].second;
                int next = node[cur][k].first;

                if (dist[next] > cost + nCost && cost + nCost <= m){ // m 보다 작을 때
                    dist[next] = cost + nCost;
                    pq.push({dist[next], next});
                }
            }

        }

        
        result = max(result, itemCnt);



    }
    

    //아이템 출력!
    cout << result << '\n';

}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}