/*  
이현승
2020년 12월 14일
LCA 예제 문제 백준 11437

2개의 노드의 가장 가까운 조상을 찾는 알고리즘이다.

1. 두 개의 노드 중, 깊이가 더 깊은 노드를 선택하여 두 개의 노드 depth(level)이 같아지도록 깊이가 제일 깊은 노드 깊이를 올린다.
2. 두 개의 노드 깊이가 같을 때까지 찾았다면 공통 조상이 맞을 때까지 한단계식 깊이를 올려가며 비교한다.
3. 두 개의 노드의 부모가 같다면 공통 조상이므로 둘 중 하나를 반환시켜준다.


백준 오프라인 수업에서 들었을 때, 댓글에서 사용할 수 있다고 들었던 기억이 난다.
댓글에 답글, 답글 답글.. 끊임없는 답글을 달았을 때, db에서 해당 관련 댓글들을 다 불러와서 연결 시켜줄 때 사용할 수 있다고 들었었다. 
실제로 구현해보지는 않아서 정확하게 어떻게 구현해야할지는 떠올리지 않는다.

*/

#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int MAX = 120000;

bool check[MAX];
int parent[MAX];
int depth[MAX];


int lca(int a, int b){


    // 깊이가 더 깊은 것이 a가 되도록 해당 조건을 체크
    if (depth[a] < depth[b]){
        swap(a, b);
    }

    while(depth[a] != depth[b]){

        //깊이가 다르다면 a가 더 깊으니까, a를 같은 레벨 깊이 까지 올린다.
        a = parent[a];
    }

    // 두개의 레벨이 같은데, 공통 부모가 아니라면, 서로 한단계식 계속올리면서 공통 부모를 찾는다.
    while(a != b){
        a = parent[a];
        b = parent[b];
    }

    
    // 찾았으면 a, b 서로 공통부모를 나타내므로 둘 중 어느 것 하나만 반환시켜준다.
    return a;

    
}


void solution(){

    vector<int> node[MAX];
    int n, m;
    // 입력으로 주어지는 인접리스트
    cin >> n;

    for (int i = 0; i < n-1; i++){
        int a, b;

        cin >> a >> b;

        // 인접 리스트 추가
        node[a].push_back(b);
        node[b].push_back(a);

    }

    // 1은 Root이므로 부모 0, 깊이 0
    depth[1] = 0;
    parent[1] = 0;
    check[1] = true;
    queue<int> q;
    q.push(1);

    while(!q.empty()){

        int x = q.front();
        q.pop();

        for (int y : node[x]){
            if (!check[y]){

                // 깊이를 한층 내려가면서 연결 시켜준다.
                depth[y] = depth[x] + 1;
                parent[y] = x;
                check[y] = true;
                q.push(y);
            }
        }
    }

    cin >> m;

    while(m--){
        int a, b;

        cin >> a >> b;

        cout << lca(a, b) << '\n';
    }


}
int main(){

    
    solution();

    return 0;
}