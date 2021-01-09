#include<algorithm>
#include<cstring>
#include<cstdio>
#include<vector>
#include<queue>
using namespace std;
const int MAX = 20 + 10;
 
char what;
int n, m, map[MAX][MAX], dist[MAX][MAX];
 
const int dr[] = { -1,1,0,0 };
const int dc[] = { 0,0,-1,1 };
 

void do_bfs(int r, int c) {
 
    bool check[MAX][MAX] = { 0, };
    queue <pair<int, int>> q;
 
    check[r][c] = true;
    q.push(make_pair(r, c));
 
    while (!q.empty()) {
        int rr = q.front().first, cc = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = rr + dr[i], nc = cc + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m) continue;
            if (map[nr][nc] == -1 || check[nr][nc]) continue;
 
            check[nr][nc] = true;
            q.push(make_pair(nr, nc));
            dist[nr][nc] = dist[rr][cc] + 1;
        }
    }
}
 
int main(void) {
    while (1) {
        scanf("%d%d", &m, &n);         
        if (!n && !m) break;           
        
        memset(map, 0, sizeof(map));   
        vector <pair<int, int>> v(1); 
 
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf(" %c", &what);
                if (what == '*') {
                   
                    v.push_back(make_pair(i, j));
                }
                else if (what == 'x') {
                    
                    map[i][j] = -1;
                }
                else if (what == 'o') {
                   
                    v[0] = make_pair(i, j);
                }
            }
        }
 
        
        int result[MAX][MAX] = { 0, };
        for (int i = 0; i < v.size(); i++) {
            
           
            memset(dist, 0, sizeof(dist));
            do_bfs(v[i].first, v[i].second);
 
            for (int j = 0; j < v.size(); j++) {
 
                
                result[i][j] = dist[v[j].first][v[j].second];
                
            }
        }
 
        
        vector <int> location(v.size() - 1);
        for (int i = 0; i < v.size() - 1; i++)
            location[i] = i + 1;
 
        int ans = 987987987;
        bool flag = true;
 
       
        do {
            
            int cur = result[0][location[0]];
            if (!cur) {
                
                flag = false;
                break;
            }
            
            for (int i = 0; i < v.size() - 2; i++) {
                cur += result[location[i]][location[i + 1]];
            }
            if (ans > cur) ans = cur;
        } while (next_permutation(location.begin(), location.end()));
 
        if (!flag) printf("-1\n"); 
        else printf("%d\n", ans);
    }
    return 0;
}