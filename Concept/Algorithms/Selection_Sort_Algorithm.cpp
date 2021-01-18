/*

Selection Sort
2021년 1월 18일
이현승 작성

선택 정렬..

예전에 매칭 플랫폼 만들었을 때 PHP 사용했던 알고리즘.. 


인덱스 0부터 n-1까지, 한 개의 인덱스 기준으로
j = i + 1 인덱스를 하나하나 다 비교하는 알고리즘. 
가장 작은값을 찾았다면 swap.

n을 각 원소마다 n씩 돌기 때문에
최악, 최상, 평균 모두 O(N^2) 이 된다. 

정렬 중에서 구현하기 가장 쉬운 정렬.. 하지만 그 만큼 시간복잡도가 꽤 있다.

*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> res;

void SelectionSort(vector<int> &res, int n){
    int cur;

    for (int i = 0; i < n - 1; i++){
        cur = i;

        for (int j = i + 1; j < n; j++){
            if (res[cur] > res[j]) cur = j;
        }

        if (cur != i){
            swap(res[cur], res[i]);
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

    SelectionSort(res, n);

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