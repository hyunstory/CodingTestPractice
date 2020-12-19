#include <iostream>
#include <vector>

using namespace std;

#define MAX 50

int n, r;

pair<int, bool> parent[MAX];

vector<int> anc[MAX];

int countLeaf(){


    // 부모중에 r값이 있는 자기 자신은 모두 true!!! 여기에서 걸러진다.
    for (int i = 0; i < n; i++)
        for (int j = 0; j < anc[i].size(); j++){
            if (anc[i][j] == r) parent[i].second = true;
        }

    

    // 혹시라도 false가 되어있는 것이 있을 까봐 삭제 노드의 부모 말고는 전부 true.
    for (int i = 0; i < n; i++){
        if (i != r){
            parent[parent[i].first].second = true;
        }
    }


    // 자식 노드 모두 구하기
    int cnt = 0;
    for (int i = 0; i < n; i++){
        if (parent[i].second == false) cnt++;
    }

    return cnt;
}

void solution(){

    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> parent[i].first;
        parent[parent[i].first].second = true;
    }

    for (int i = 0; i < n; i++){
        int curParent = parent[i].first;

        while(curParent != -1){
            anc[i].push_back(curParent);
            curParent = parent[curParent].first;
        }
    }

    cin >> r;

    parent[r].second = true;

    //아래 코드는 왼쪽으로 노드 하나 위에 부모가 자식 1개만 가지고 있을 때를 위해, 부모의 값을 false해주어야한다. 
    parent[parent[r].first].second = false;

    cout << countLeaf() << '\n';


    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}