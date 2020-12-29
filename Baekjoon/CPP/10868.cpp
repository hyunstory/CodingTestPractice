#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

#define MAX 100001

int arr[MAX];
int seg[4*MAX];

long long initSegmentTree(int left, int right, int node){

    if (left == right) return seg[node] = arr[left];

    int mid = (left + right) / 2;

    return seg[node] = min(initSegmentTree(left, mid, node * 2), initSegmentTree(mid + 1, right, node * 2 + 1));
}

long long query(int left, int right, int node, int nodeLeft, int nodeRight){

    if (right < nodeLeft || nodeRight < left){
        return __INT_MAX__;
    }

    else if (left <= nodeLeft && nodeRight <= right ) return seg[node];

    int mid = (nodeLeft + nodeRight) / 2;

    return min(query(left, right, node * 2, nodeLeft, mid), query(left, right, node*2 + 1, mid + 1, nodeRight ));
}

void solution(){


    int n, m;

    cin >> n >> m;

    for (int i = 1; i <= n; i++){
        cin >> arr[i];
    }

    initSegmentTree(1, n, 1);

    while(m--){

        int left, right;
        cin >> left >> right;

        cout << query(left, right, 1, 1, n) << '\n';
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}