#include <iostream>
#include <vector>

using namespace std;

const int MAX = 501;
int map[MAX][MAX];

int n, m;

vector<bool> tMem;
int result;

void solution(){
    
    cin >> n >> m;

    for (int i = 1; i <= m; i++){
        int height;
        cin >> height;
        int bottom = n;
        while(height--){
            map[bottom - height][i] = 1;
        }
    }

    for (int i = 1; i <= n; i++){
        int wall = 0;
        for (int j = 1; j <= m; j++){

            int point = map[i][j];

            if (point == 1 && wall == 1){
                result += tMem.size();
                tMem.clear();
            }
            else if (point == 1 && !wall){
                wall = 1;
            }
            else if (point == 0 && wall == 1){
                tMem.push_back(true);
            }

            
            
        }
        tMem.clear();
    }

    cout << result << '\n';

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}