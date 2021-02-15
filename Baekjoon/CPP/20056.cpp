#include <iostream>
#include <deque>

using namespace std;

const int MAX = 51;

int n, m, k;

struct Fireball{
    int x;
    int y;
    int m;
    int s;
    int dir;
    Fireball(int x, int y, int m, int s, int dir): x(x), y(y), m(m), s(s), dir(dir){}
}Fireball;
int dx[] = {-1, -1, 0, 1, 1, 1, 0, 0};
int dy[] = {0, 1, 1, 1, 0, -1, -1, -1};

int mapCount[MAX][MAX];


deque<Fireball> fb;

pair<int, int> moveWhileCheckingSpace(int x, int y, int dir, int speed);

int getMass(){


}

void isZeroIncluded(){

}

void MergeAndDivide(){

}

void move(){

    



}
void solution(){
    cin >> n >> m >> k;

    for (int i = 0; i < m; i++){
        int x, y, mass, speed, dir;

        fb.push_back(Fireball(x, y, mass, speed, dir));
    }



    // 명령어 k번 실행
    while(k--){

        // 이동
        move();

        // 합치기 + 나누기 작업
        MergeAndDivide();

        // 질량이 Null이 있는지 확인
        isZeroIncluded();
    }


    // 파이어 볼 검사 후, 질량 누적 합 구하고 출력
    cout << getMass() << '\n';

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}

pair<int, int> moveWhileCheckingSpace(int x, int y, int dir, int speed){


}