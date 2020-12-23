/*
2020년 12월 23일
이현승

Two pointer 알고리즘

예제 백준 2003 수들의 합2


투포인터 알고리즘은 left, right 구간 사이에 있는 값들의 곱하거나 더해서 원하는 기능을 구현할 수 있다.

기본 예제를 투포인터를 써서 구하는 방법은

1. left, right가 인덱스 0을 가르켜 첫번째 값을 sum에 추가한다.
2. 만약 구하고자하는 m 값보다 sum이 작다면 ( right < n ) 이 되는 범위에서 right를 +1을 해주고,
+1이 된 값의 sum에 더해준다.
3. 만약 구하고자하는 m 값보다 sum이 크다면, (left < n) 이 되는 범위에서 left의 있는 값을 sum에서 뺀 다음,
left를 +1를 해준다. left가 right를 넘어 섰고, (left < n) 범위 안에 든다면, right = left로 다시 처음부터 다시 시작하고
sum의 값은 left있는 값 1개만 추가하여 left기준에서 처음부터 다시 시작한다.

while문이 돌아가는 조건은 left <= right이고, left < n이고, right < n일 때 동작하도록 설정한다.




*/
#include <iostream>
#include <vector>

using namespace std;


void solution(){

    int n, m;

    // 배열 크기 n값 입력, 목표하는 값 m 입력
    cin >> n >> m;


    // 0으로 채운 크기가 n+1개의 벡터를 생성한다. n+1의 이유는 left, right가 n을 넘어설수 있는 경우가 생김. 값은 0이기 때문에 곱셈만 아니고 덧셈이라면 초기값 0, 곱셈이라면 초기값 1 
    vector<int> arr(n+1, 0);

    for (int i = 0; i < n; i++){
        cin >> arr[i];  // 배열 입력
    }

    // left, right 모두 초기값 0인덱스를 가리키고 있음. sum은 초기값 0의 값만 들어있음
    int left = 0;
    int right = 0;
    int sum = arr[0];
    int result = 0;

    
    while(left <= right && right < n && left < n){

        // sum이 목표하는 값보다 작다면 right +1 값을 더해주고 right도 역시 +1로 이동시킴
        if (sum < m){
            sum += arr[++right];
        }

        // sum이 목표하는 값이랑 같다면, 같다는 카운트 result++를 해준 뒤, right +1 의 값을 sum에 넣어주고 right가 가르키는 값 역시 +1을 해준다.
        // 찾아도 계속 진행하는 이유는 (right < n)이 될 때까지 모든 경우의 수를 찾아야하기 때문이다.
        else if (sum == m){
            sum += arr[++right];
            result++;
        }

        // sum이 목표하는 값보다 크다면, left의 값을 sum에서 빼주고, left를 +1해준다.
        // left를 +1했는데, right범위보다 넘어가게 되면, right = left로 대입하고, sum을 left의 값 1개만 넣어주어서
        // 위치만 left부터 다시 시작한다.
        
        else if (sum > m){
            sum -= arr[left++];

            if (left > right){
                right = left;
                sum = arr[left];
            }
        }
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