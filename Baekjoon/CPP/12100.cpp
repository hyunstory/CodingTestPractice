/*
삼성 입사 문제

블록에 있는 값들을 한쪽으로 밀어 넣고, 하나씩 비교하면서 같은 숫자가 있으면 *2를 해준다.
대신, 변경 된 값은 지나친다. 

dfs로 경우의 수를 구한다음, 시뮬레이션을 돌려보는 것인데,
실수 했던 부부은 dfs로 경우의 수를 다 구한다음에 시뮬레이션을 했는데, 이건 그렇게 하면 안된다.
맵의 상태정보를 저장하고 있어야지만, dfs에서 함수가 return되고, 다음 경우의 수를 계산하기 위해서는 이전의 맵의 상태가 저장 되어있어야 하고,
이전으로 맵을 되돌린다음 다음 경우의 수를 구하고, 

depth가 5가되면 여태까지 구한 map에서 최댓값을 구해주는 형식이다.

상태 정보를 dfs함수에 변수로 저장되어 계산해야한다. 아주 괜찮은 문제.

이 문제에서 키 포인트

1. 숫자들은 한쪽 방향으로 몰아 넣은다음, 같은 것 비교하기 (큐 사용, idx변수를 사용해서 빈 공간 찾기) -> queue에 다 저장 후 0으로 한쪽 라인 초기화, 큐를 하나씩 pop하면서 빈공간 혹은 같은 숫자에 기록
2. 맵의 상태정보를 dfs 함수내에 각 각 다 저장하기. 시뮬레이션을 돌리고, depth가 5가 될 때 맵 내에서 최댓값 찾아주기. 


*/

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int map[21][21];

int maxV;

// 0은 위, 1은 아래, 2는 왼 좌, 3은 오른 우

vector<int> moved;
vector<int> recon;

int n;

void swipeUp(){

    queue<int> q;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (map[j][i])q.push(map[j][i]);

                map[j][i] = 0;

            }

        int idx = 0;
 
        while (!q.empty()){
            int data = q.front();
            q.pop();
            
            if (map[idx][i] == 0) map[idx][i] = data;

            else if (map[idx][i] == data){
                map[idx][i] *= 2;
                idx++;
            }
            else{
                idx++;
                map[idx][i] = data;
            }
        }
    }
}
void swipeDown(){

    queue<int> q;

    for (int i = 0; i < n; i++){
        for (int j = n - 1; j >= 0; j--){
            if (map[j][i])q.push(map[j][i]);

                map[j][i] = 0;

            }

        int idx = n - 1;
 
        while (!q.empty()){
            int data = q.front();
            q.pop();
            
            if (map[idx][i] == 0) map[idx][i] = data;

            else if (map[idx][i] == data){
                map[idx][i] *= 2;
                idx--;
            }
            else{
                idx--;
                map[idx][i] = data;
            }
        }
    }

}
void swipeLeft(){

    queue<int> q;

    for (int i = 0; i < n; i++){
        for (int j = 0; j < n; j++){
            if (map[i][j])q.push(map[i][j]);

                map[i][j] = 0;

            }

        int idx = 0;
 
        while (!q.empty()){
            int data = q.front();
            q.pop();
            
            if (map[i][idx] == 0) map[i][idx] = data;

            else if (map[i][idx] == data){
                map[i][idx] *= 2;
                idx++;
            }
            else{
                idx++;
                map[i][idx] = data;
            }
        }
    }

}
void swipeRight(){
    queue<int> q;

    for (int i = 0; i < n; i++){
        for (int j = n - 1; j >= 0; j--){
            if (map[i][j])q.push(map[i][j]);

                map[i][j] = 0;

            }

        int idx = n - 1;
 
        while (!q.empty()){
            int data = q.front();
            q.pop();
            
            if (map[i][idx] == 0) map[i][idx] = data;

            else if (map[i][idx] == data){
                map[i][idx] *= 2;
                idx--;
            }
            else{
                idx--;
                map[i][idx] = data;
            }
        }
    }

}

void simul(int dir){

        switch(dir){
            case 0: // 위로 올릴 때
            swipeUp();
            break;

            case 1: // 아래로 내릴 때
            swipeDown();
            break;

            case 2: // 왼쪽으로 옮길 때
            swipeLeft();
            break;

            case 3: // 오른 쪽으로 옮길 때
            swipeRight();
            break;
            
            default: break;
        }

}
void getMax(){
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            maxV = max(maxV, map[i][j]);
        }
}
void dfs(int depth){
    if (depth == 5){
        getMax();

        return;
    }
    int rightnow[21][21];

    memcpy(rightnow, map, sizeof(map));


    for (int i = 0; i < 4; i++){
        simul(i);

        dfs(depth + 1);
        memcpy(map, rightnow, sizeof(map));

    }
}
void solution(){
    cin >> n;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++){
            cin >> map[i][j];
    }
    
    dfs(0);

    cout << maxV << '\n';

}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}