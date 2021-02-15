/*
인디그리를 생각하면서 푸는 문제

루트라면 degree가 0이고,
나머지는 degree가 1이다.

트리의 특징은 노드 개수 = 간선 + 1을 특징을 갖는다.
이 특징을 이용해서 문제를 풀면된다.

indi 즉, 가리키고 있는 값이 2개가 넘는 것은 트리가 아니므로 표시해준다.
*/

#include <iostream>
#include <map>

using namespace std;



void solution(){
    int t = 1;

    bool is_run = true;

    while(1){

        bool isTree = true;
        int a, b;
        int cnt = 0;
        map<int, int> m;
        map<int, int> indi;

        while((cin >> a >> b) && (a || b)){
            if (a == -1 && b == -1) return;
            cnt++;

            if (m.find(a) == m.end()){
                m[a] = 1;
            }
            if (m.find(b) == m.end()){
                m[b] = 1;
            }
            if (indi.find(b) == indi.end()){
                indi[b] = 1;
            }
            else{
                isTree = false;
            }
        }

        if (cnt > 0 && m.size() != cnt + 1) isTree = false;

        if (isTree) cout << "Case " << t << " is a tree." << '\n';
        else cout << "Case " << t << " is not a tree." << '\n';

        t++;
    }


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}