#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 10000;



typedef pair<int, double>  ppi;
typedef pair<double, int> ppd;

void setUpWolfMap(vector<ppi> *in, vector<ppi> *out, int n){
    for(int i = 1; i <= n; i++){
		for(int j = 0; j < in[i].size(); j++){
			auto ii = in[i][j];
			out[2 * i].push_back({ii.first * 2 + 1, ii.second / 2});
			out[2 * i + 1].push_back({ii.first * 2, ii.second * 2});
		}
	}
    

}

vector<double> dijkstra(vector<ppi> *a, int n, int start){
    vector<double> dist(n+20, __INT_MAX__); // **** 10 이상을 더해주어야 함

	dist[start] = 0;
	priority_queue<ppd> pq;
	pq.push({0, start});
	while(!pq.empty()){
		double cost = -pq.top().first;
        int v = pq.top().second;
		pq.pop();

		if(cost > dist[v]) continue;

		for(auto k : a[v]){
			int next = k.first;
            double nCost = k.second;
            double calCost = cost + nCost;
            
			if(dist[next] > calCost){
				dist[next] = calCost;
				pq.push({-calCost, next});
			}
		}
	}
	return dist;

}
void solution(){
    int n, m;

    cin >> n >> m;

    vector<ppi> vec1[MAX];
    vector<ppi> vec2[MAX];


    for (int i = 0; i < m; i++){
        int a, b, c;
        cin >> a >> b >> c;
        vec1[a].push_back({b, c});
        vec1[b].push_back({a, c});

    }

    setUpWolfMap(vec1, vec2, n);


    auto ret1 = dijkstra(vec1, n, 1);
	auto temp = dijkstra(vec2, n * 2, 2);

	vector<double> ret2(n+1);

	for(int i = 1; i <= n; i++){
		if(temp[i * 2] == 0 || temp[i * 2] == __INT_MAX__) ret2[i] = temp[i * 2 + 1];
		else if(temp[i * 2 + 1] == 0 || temp[i * 2 + 1] == __INT_MAX__) ret2[i] = temp[ i * 2];
		else ret2[i] = min(temp[i * 2], temp[i * 2 + 1]);
	}

	int cnt = 0;
	for(int i=2; i<=n; i++){
		if(ret1[i] < ret2[i]) cnt++;
	}
	cout << cnt << '\n';
    

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}