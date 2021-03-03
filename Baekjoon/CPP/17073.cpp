#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> v[500001];
bool check[500001];

void solution(){

    int n, a, b, cnt = 0;

    double sum;
    cin >> n >> sum;

    for (int i = 0; i < n - 1; i++){
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    queue<int> q;
    check[1] = true;
    q.push(1);

    while(!q.empty()){
        int idx = q.front();
        q.pop();

        bool avail = false;
        for (int i = 0; i < v[idx].size(); i++){
            int next = v[idx][i];
            if (check[next]) continue;
            check[next] = true;
            q.push(next);
            avail = true;
        }
        if (!avail) cnt++;
    }

    cout << sum / cnt << '\n';


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout.precision(11); // 소숫점 정확도 11자리까지

    solution();

    return 0;
}