#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MAX = 1000001;

vector<int> node[MAX];
vector<int> tree[MAX];
int dp[MAX][2];

int n;

int adaptor(int root, int isAdaptor){
    if (tree[root].empty()){
        if (isAdaptor) return 1;
        else return 0;
    }

    int &ret = dp[root][isAdaptor];
    if (ret != -1) return ret;
    
    if (isAdaptor){
        ret = 1;
        for (auto c: tree[root]){
            ret += min(adaptor(c, 1), adaptor(c, 0));
        }
    } else{
        ret = 0;
        for (auto c: tree[root]){
            ret += adaptor(c, 1);
        }

    }

    return ret;
}

void makeTree(int child, int parent){
    if (parent != 0) tree[parent].push_back(child);

    for (auto n: node[child]){
        if (n == parent) continue;
        makeTree(n, child);
    }


}

void solution(){
    cin >> n;

    memset(dp, -1, sizeof(dp));

    for (int i = 0; i < n - 1; i++){

        int from, to;

        cin >> from >> to;

        node[from].push_back(to);
        node[to].push_back(from);
    }

    makeTree(1, 0);


    cout << min(adaptor(1, 1), adaptor(1, 0)) << '\n';
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();    
    
    return 0;
}