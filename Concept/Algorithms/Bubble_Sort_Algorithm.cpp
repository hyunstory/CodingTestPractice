/*
Bubble Sort

2021년 1월 18일
이현승 작성


버블 소트
정렬하는 것이 마치 버블과 같다고 해서 버블소트라고 불리는 것으로 알고 있음

선택정렬과 비슷한 원리지만, 선택정렬은 매번 바꿔주지 않고 최소 or 최대값을 한개씩 찾아가는 것이지만,
버블정렬은 정렬 상태가 다른 두 개의 원소를 매번 swap해준다.


원리:
1. 맨 끝 i 원소 인덱스부터 시작한다.
2. 각 원소를 접근할 때마다, 0부터 i전까지 j와 j+1의 원소들을 비교를 하면서 대소관계가 반대로 되어있는 것을 swap시켜준다. 예를 들어 오름차순 정렬의 경우, (res[j] > res[j+1]) 는 swap해주기

끝. 구현은 간단하다.

그렇기 때문에 최고, 평균, 최악의 시간복잡도는 모두 O(N^2)이다.!!! 중요!



*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

void BubbleSort(vector<int> &res, int n){
    for (int i = n - 1; i >= 0; i--){

        for (int j = 0; j < i; j++){
            if (res[j] > res[j+ 1]){
                swap(res[j], res[j+1]);
            }
        }
    }
}

void solution(){

    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        res.push_back(temp);
    }

    BubbleSort(res, n);

    for (auto v: res){
        cout << v << '\n';
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}