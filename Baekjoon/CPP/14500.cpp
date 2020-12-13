//
//  main.cpp
//  코딩테스트준비
//
//  Created by David Lee on 2020/06/29.
//  Copyright © 2020 hyunseunglee. All rights reserved.
//

#include <iostream>

using namespace std;

#define MAX 500 + 1

int block[19][3][2] = {
    {{0,1}, {0,2}, {0,3}},
    {{1,0}, {2,0}, {3,0}},
    {{1,0}, {1,1}, {1,2}},
    {{0,1}, {1,0}, {2,0}},
    {{0,1}, {0,2}, {1,2}},
    {{1,0}, {2,0}, {2,-1}},
    {{0,1}, {0,2}, {-1,2}},
    {{1,0}, {2,0}, {2,1}},
    {{0,1}, {0,2}, {1,0}},
    {{0,1}, {1,1}, {2,1}},
    {{0,1}, {1,0}, {1,1}},
    {{0,1}, {-1,1}, {-1,2}},
    {{1,0}, {1,1}, {2,1}},
    {{0,1}, {1,1}, {1,2}},
    {{1,0}, {1,-1}, {2,-1}},
    {{0,1}, {0,2}, {-1,1}},
    {{0,1}, {0,2}, {1,1}},
    {{1,0}, {2,0}, {1,1}},
    {{1,0}, {2,0}, {1,-1}},
};

int input[MAX][MAX];
int N, M;
          



void solution(){
    
    
    cin >> N >> M;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++){
            cin >> input[i][j];
        }
    
    
    int ans = 0;
    for (int i=0; i < N; i++) {
        for (int j=0; j < M; j++) {
            for (int k=0; k<19; k++) {
                bool ok = true;
                int sum = input[i][j];
                for (int l=0; l<3; l++) {
                    int x = i+block[k][l][0];
                    int y = j+block[k][l][1];
                    if (0 <= x && x < N && 0 <= y && y < M) {
                        sum += input[x][y];
                    } else {
                        ok = false;
                        break;
                    }
                }
                if (ok && ans < sum) {
                    ans = sum;
                }
            }
        }
    }
    cout << ans << '\n';
    
    
    
}

int main() {

    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    solution();
    
    return 0;
}
