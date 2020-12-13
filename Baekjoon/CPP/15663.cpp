#include<algorithm>
#include<iostream>
using namespace std;
 
bool check[8]; // 중복된 수를 고르지 않기 위한 배열
int n, m, num[8], result[8];
 
// 입력받은 n개의 수들 중에서 골랐던 수열과 똑같은 수열을
// 고르지 않게 m개를 고르고 출력해주는 함수
void getResult(int count) {
 
    // m개를 골랐다면 출력합니다
    if (count == m) {
        for (int i = 0; i < m; i++)
            cout << result[i] << ' ';
        cout << '\n';
        return;
    }
    // prev_num에 직전에 골랐던 수를 저장합니다 이 변수를
    // 전역변수로 선언하지 않고 이 곳에 선언하여 계속 
    // 초기화가 되도록 해주는 이유는 맨 처음에 고르는 수는
    // 직전에 골랐던 수와 관계없이 고르기 위함입니다
    int prev_num = -1;
    // 또한 함수의 재귀 호출이 출력으로 인해 끝나게 되면
    // for문 안에서 다음 수를 고르게 되는데 그 때
    // prev_num에 저장된 수를 고르지 않기 위함입니다
    for (int i = 0; i < n; i++) {
        
        // 직전에 골랐던 수가 아니고 이미 고른 수가 아니라면
        if (!check[i] && prev_num != num[i]) {
            
            check[i] = true;          // 골라주고
            result[count] = num[i];   // 배열에 넣고
            prev_num = num[i];        // 직전에 고른 수에 저장
            getResult(count + 1);     // 다음 수를 고르러 갑니다
            check[i] = false;
        }
    }
}
 
int main(void) {
 
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> num[i];
 
    // 수열은 사전 순으로 출력해야 하므로
    // 입력을 받고 오름차순으로 정렬합니다
    sort(num, num + n);
 
    getResult(0);
    return 0;
}
