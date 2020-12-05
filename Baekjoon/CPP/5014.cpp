#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>

using namespace std;

int f, s, g, u, d;


int bfs(){
    queue<pair<int, int>> q;

    vector<bool> check(f+1);

    check[s] = true;
    q.push({s, 0});

    while(!q.empty()){

        pair<int, int> c = q.front();
        q.pop();

        if (c.first == g) return c.second;

        int up = c.first + u;
        int down = c.first - d;
        int count = c.second;
        

        if (up <= f && !check[up]) {
            check[up] = true;
            q.push(make_pair(up, count + 1));
        }
        if (down >= 1 && !check[down]) {
            check[down] = true;
            q.push(make_pair(down, count + 1));
        }

    }

    return -1; // default

}


void solution(){

    cin >> f >> s >> g >> u >> d;

    
    int result = bfs();
    
    if (result != -1)cout << result << '\n';
    else cout << "use the stairs" << '\n';
}

int main(){


    solution();

    return 0;

}