#include <iostream>
#include <algorithm>
#include <cmath>


using namespace std;

const int MAX = 1001;

int map[MAX][MAX];
int dp[MAX][MAX];


void solution(){
    int n, m;

    int width, ans = 0;

    scanf("%d %d", &n, &m);

    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= m; j++){
            scanf("%1d", &map[i][j]);
            if (map[i][j] == 1) dp[i][j] = 1;
        }
    }

    

    int max_len = 0;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++){
            if (map[i][j] != 0){
                map[i][j] = min(map[i - 1][j - 1], min(map[i-1][j], map[i][j - 1])) + 1;
                if (max_len < map[i][j]) max_len = map[i][j];
            }
        }

    printf("%d\n", max_len*max_len);


}
int main(){


    solution();

    return 0;
}