#include <iostream>

using namespace std;

int map[8][8]; // 0은 흰색, 1은 검정색
char input_map[8][8];

void make_map(){


    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            if ((i % 2) == 0 && (j % 2 == 0)) map[i][j] = 0;
            else if((i % 2) == 1 && (j % 2 == 1)) map[i][j] = 0;
            else map[i][j] = 1;  
        }
    }
}
void solution(){

    make_map();
    int result = 0;

    for (int i = 0; i < 8; i++){
        for (int j = 0; j < 8; j++){
            char temp;
            cin >> temp;

            if (temp == 'F' && map[i][j] == 0) result++;

        }
    }

    cout << result << '\n';

}

int main(){


    solution();


    return 0;
}