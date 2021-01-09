/*
이현승
2021년 1월 6일
소수 찾기는 에라토스테네스의 채를 이용해서 푼다.

2, 3, 4, 순으로 배수를 제거해주면 되는데, 
어디까지 구해주냐면, 구하고 싶은 소수의 제곱근까지만 구해준다.
예를 들어서, 10000의 숫자 중 소수를 구하고 싶다면,
100까지만 배수를 체크해주면서 지워주면된다.
그 원리는 소수는 제곱까지  소수가 아닌 수들이 들어있기 때문...

처음 시작할 때 2부터 시작이 아닌, 2*2, 3*2, 4*2부터 시작. 2와 3은 소수이기 떄문이다.

그리고 제일 중요한 초기값 0, 1은 소수가 아니므로, check[] = true를 한 후 시작한다. 
초기화하는 것이 제일 중요하다!
*/

#include <iostream>
#include <vector>

using namespace std;
const int endPoint = 3000000;

vector<bool> check(endPoint, false);


void make_table(){
    int s = 0;


    for (int i = 2; i <= 1200; i++){
        int start = i * 2;

        for (int j = start; j <= endPoint - 1; j += i){

            if (check[j]) continue;
            check[j] = true;
            
           
        }
        
    }
}
void solution(){

    check[0] = true;
    check[1] = true;
    make_table();

    int n, m;

    cin >> n >> m;
    

    for (int i = n; i <= m; i++){
        if (!check[i]) cout << i << '\n';
    }
}
int main(){


    solution();

    return 0;
}