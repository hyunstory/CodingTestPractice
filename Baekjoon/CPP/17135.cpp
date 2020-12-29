#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define MAX 51

int n, m, d;
int arr[MAX][MAX];
int copy[MAX][MAX];


void solution(){

    cin >> n >> m >> d;

    vector<pair<int, int>> enemy;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++){
            cin >> arr[i][j];

            if (arr[i][j] == 1){
                enemy.push_back({i, j});
            }
        }


    vector<int> archer;

    for (int i = 0; i < m - 3; i++) archer.push_back(0);

    for (int i = 0; i < 3; i++) archer.push_back(1);

    int result = 0;

    do{
        int cnt = 0;

        vector<pair<int, int>> temp = enemy; // temp는 적

        vector<int> v;

        for (int i = 0; i < archer.size(); i++){
            if (archer[i] == 1){
                v.push_back(i); // 임의의 궁수 위치 가져옴. 처음에는 00...111이었음, v는 궁수의 임의 위치 y좌표
            }
        }

        while(!temp.empty()){
            int y = n;
            vector<int> target;

            for (int i = 0; i < v.size(); i++){

                int x = v[i];
                int idx = 0;

                int enemyX = temp[0].second;
                int dist = abs(y-temp[0].first) + abs(x - temp[0].second);

                for (int j = 1; j < temp.size(); j++){
                    int tempDist = abs(y - temp[j].first) + abs(x - temp[j].second);

                    if (dist > tempDist){
                        enemyX = temp[j].second;
                        dist = tempDist;
                        idx = j;
                    }

                    else if (dist == tempDist && enemyX > temp[j].second){
                        enemyX = temp[j].second;
                        idx = j;
                    }
                }

                if (dist <= d){
                    target.push_back(idx);
                }
            }

            target.erase(unique(target.begin(), target.end()), target.end());
            sort(target.begin(), target.end());

            int shoot = 0;

            for (int i = 0; i < target.size(); i++){
                temp.erase(temp.begin() + (target[i] - shoot++));
                cnt++;
            }

            if (temp.empty()) break;

            vector<pair<int, int>> copyTemp;

            for (int i = 0; i < temp.size(); i++){
                if (temp[i].first < n - 1){
                    copyTemp.push_back({temp[i].first + 1, temp[i].second});
                }
            }
            temp = copyTemp;
        }

        result = max(result, cnt);

    }while(next_permutation(archer.begin(), archer.end()));

    cout << result << '\n';


    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}