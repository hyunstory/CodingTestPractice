#include <iostream>

using namespace std;

int map[10][10];

void solution(){
    int max_x, max_y;

    int maxV = 0;

    for (int i = 1; i <= 9; i++)
        for(int j = 1; j <= 9; j++){
            cin >> map[i][j];

            if (maxV < map[i][j]){
                max_x = i;
                max_y = j;
                maxV = map[i][j];
            }

        }

    cout << maxV << '\n';
    cout << max_x << ' ' << max_y << '\n';

    
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}