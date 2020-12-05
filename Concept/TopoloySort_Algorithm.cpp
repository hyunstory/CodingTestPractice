#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> a[33000];
int ind[33000];

void solution(){
    int n, m;


    // n은 수의 크기,
    // m은 입력 받을 2개의 비교 숫자 개수

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int first, second;

        // 첫 번째가 우선순위, 두 번 째가 그다음

        cin >> first >> second;


        // 우선순위가 먼저인 첫번 째 배열에 두번 째 인자값을 추가해준다. (첫 번째 배열에 여러개가 추가될 수있음, 순서의 의미를 여라가지로 정보를 입력가능)
        a[first].push_back(second);

        // 두번 째 인자값은 첫 번째보다 우선순위가 낮고, 첫 번째가 두번째를 가르키고있다. (indication 개념)
        ind[second]++;
    
    }
    queue<int> q;

    for (int i = 1; i <= n; i++){
        if (ind[i] == 0){

            // 한번도 가르킴을 받지 않은 노드는 최상위노드, 먼저 우선순위가 있다. 여러개가 있을 경우 같은 순위의 우선순위이다.
            q.push(i);
        }
    }

    while(!q.empty()){

        // DFS, BFS모두 가능하지만, BFS가 생각하기 편리함. DFS도 구현해볼만함.
        int node = q.front();
        q.pop();

        // q에 있는 값은 가르키는 것이 하나도 없는 것으로, 최상위 노드로서, 하나씩 출력하면서 pop을 해준다.

        cout << node << ' ';
        

        // 해당 최상위 노드를 pop했기 때문에, 그 최상위 노드가 가르키고 있는 값은 모두 ind 즉, 가르키는 값을 1개씩 낮춰준다. 
        int node_size = a[node].size();

        for (int i = 0; i < node_size; i++){

            int y = a[node][i];

            ind[y]--;

            if(ind[y] == 0){
                // 가르키는 값을 하나씩 낮췄는데, 그 노드를 가르키는 값이 없다면, 그 노드는 최상위 노드가 된다. 그래서 q에 최상위 노드 정보를 삽입해주면 된다.
                q.push(y);
            }

        }

    }

    cout << '\n';
    
}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;

}