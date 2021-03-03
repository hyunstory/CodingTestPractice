#include <iostream>
#include <cstring>

using namespace std;

const int MAX = 100001;
int n, cnt;

int arr[MAX];
bool check[MAX];
bool finish[MAX]; //방문이 끝났는지 여부

void go(int idx){

    check[idx] = true;

    int next = arr[idx];

    if (!check[next]) go(next);


    else if (!finish[next]){

        for (int i = next; i != idx; i = arr[i]) cnt++;

        cnt++; //자신을 센다

    }
    
    finish[idx] = true; //더 이상 해당 노드를 방문할 일이 없다
}

void solution(){
    int t;

    cin >> t;

    while(t--){

        memset(check, false, sizeof(check));

        memset(finish, false, sizeof(finish));

        cin >> n;

        for (int i = 1; i <= n; i++) cin >> arr[i];

        cnt = 0;

        for (int i = 1; i <= n; i++) if (!check[i]) go(i); 

        cout << n - cnt << '\n';

    }

}

int main(void){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();
    
    return 0;
}

