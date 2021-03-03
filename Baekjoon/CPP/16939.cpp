#include <iostream>
#include <cstring>

using namespace std;


int a[25];

int copied[25];

int table[6 + 1][8 + 1] = {
    {},// 공집합
    {0, 1, 3, 5, 7, 9, 11, 24, 22},
    {0, 2, 4, 6, 8, 10, 12, 23, 21},
    {0, 13, 14, 5, 6, 17, 18, 21, 22},
    {0, 15, 16, 7, 8, 19, 20, 23, 24},

    //추가된부분
    {0, 3, 4, 17, 19, 10, 9, 16, 14},
    {0, 1, 2, 18, 20, 12, 11, 15, 13}
};
int verify(){
    
    for (int i = 1; i <= 24; i++){

        for (int j = i + 1; j <= i + 3; j++){
            if (copied[j] != copied[i]){
                return 0;
            }
        }

        i += 3;
    }


    return 1;
}
void simul(){

    // 정방향

    for (int i = 1; i <= 6; i++){
        memcpy(copied, a, sizeof(a));

        copied[table[i][3]] = a[table[i][1]];
        copied[table[i][4]] = a[table[i][2]];

        copied[table[i][5]] = a[table[i][3]];
        copied[table[i][6]] = a[table[i][4]];

        copied[table[i][7]] = a[table[i][5]];
        copied[table[i][8]] = a[table[i][6]];

        copied[table[i][1]] = a[table[i][7]];
        copied[table[i][2]] = a[table[i][8]];
        
        
        if( verify() == 1 ){
            cout << 1 << '\n';
            return;
        }
    }

    // 역방향
    for (int i = 1; i <= 6; i++){
        memcpy(copied, a, sizeof(a));


        copied[table[i][1]] = a[table[i][3]];
        copied[table[i][2]] = a[table[i][4]];

        copied[table[i][3]] = a[table[i][5]];
        copied[table[i][4]] = a[table[i][6]];

        copied[table[i][5]] = a[table[i][7]];
        copied[table[i][6]] = a[table[i][8]];

        copied[table[i][7]] = a[table[i][1]];
        copied[table[i][8]] = a[table[i][2]];


        if( verify() == 1 ){
            cout << 1 << '\n';
            return;
        }

    }


    cout << 0 << '\n';

}
void solution(){

    // 입력
    for (int i = 1; i <= 24; i++){
        cin >> a[i];
    }

    

    // 시뮬레이션
    simul();    
}
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}