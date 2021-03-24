#include <iostream>
#include <cstring>
#include <queue>
#include <tuple>
#include <vector>

using namespace std;

int n;

const int MAX = 126;

int Tcase = 1;

int map[MAX][MAX];

int dist[MAX][MAX];
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

const int INTMAX = __INT_MAX__;
void solution(){

    while(true){
        cin >> n;

        if (n == 0) break;

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                cin >> map[i][j];
            }
        }

        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                dist[i][j] = INTMAX;
            }
        }

        priority_queue< tuple<int,int,int>, vector<tuple<int,int,int> >, greater<tuple<int,int,int> > > pq;


        pq.push(make_tuple(map[0][0], 0, 0));
        dist[0][0] = map[0][0];

        while(!pq.empty()){

            auto v = pq.top();
            int cost = get<0>(v);
            int x = get<1>(v);
            int y = get<2>(v);
            pq.pop();
            

            if (x == n - 1 && y == n - 1){
                cout << "Problem " << Tcase << ": " << dist[n-1][n-1] << '\n';
                break;
            }

            for (int k = 0; k < 4; k++){
                int nx = x + dx[k];
                int ny = y + dy[k];
                int nCost = map[nx][ny];

                if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;

                if (dist[nx][ny] > cost + nCost){
                    dist[nx][ny] = cost + nCost;

                    pq.push(make_tuple(dist[nx][ny], nx, ny));
                }
            }
        }

        Tcase++;
    }


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}