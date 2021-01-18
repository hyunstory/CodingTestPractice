/*
Quick Sort.

2021년 1월 18일
이현승 작성

퀵소트

퀵소트는 분할 정복 알고리즘의 하나로, 평균적으로 매우 빠른 수행 속도를 자랑하는 정렬 방법이다. 
//머지소트 달리 퀵 소트는 비균등하게 분할한다. (피봇 선택한 것에 따라 수행 속도가 달라 질수 있다 )

과정: 
1. 리스트 안에 있는 한 요소를 선택한다. 이 요소를 피봇이라고 한다.
2. 피봇을 기준으로 비봇보다 작은 요소들을 모두 피봇의 왼쪽에 옮겨지고, 피봇보다 큰 요소들은 모두 피봇의 오른 쪽에 옮겨진다. 
3. 피봇을 제외한 왼쪽리스트와 오른쪽 리스트를 다시 정렬한다. (재귀함수을 이용하여 정렬 반복)
4. 부분 리스트들이 더 이상 분할이 불가능할 때까지 반복한다. ( 리스트의 크기가 1이거나 0일 때 까지)

분할 -> 정복 -> 결합(swap?)

퀵소트는 배열이 정렬이 되어있다면 최악의 시간복잡도인 O(n^2)이 나온다. 
왜냐하면, 피봇을 골랐는데 항상 그 배열 값들이 작거나 같기 때문에 n을 비교하고, n-1을 비교하고, n-2... n-n까지를 비교하기 때문이다.

하지만, 랜덤으로 되어있다면, 평균 O(NlogN)의 속도가 나온다. 
분할 정복을 제대로 할 수 있기 때문


*/


#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int partition(vector<int> &res, int left, int right){
    int low = left;                                 // low는 초기 pivot위치 이니까 피봇 다음부터 인 low +1부터 시작하게 된다. 
    int high = right + 1;                           // high는 처음에 시작할 때 high--을 하기 때문에, high를 +1해서 옮겨놓는다. low는 pivot위치점이라서 pivot다음부터 비교해야함
    int pivot = res[left];                          // 배열의 맨 처음 값을 pivot을 정하고 그 값을 저장해준다.

    do{
        do{
            low++;
        }while(low <= right && res[low] < pivot);   // low가 right 갈 때까지 && res[low] < pivot 이면 계속 low-- 위치 이동

        do{
            high--;
        }while(high >= left && res[high] > pivot);  // hight가 left에 갈 때까지 && res[high] > pivot 이면 계속 high++ 위치 이동

        if (low < high) swap(res[low], res[high]);  // low나 high가 pivot을 기준점으로 맞지 않는 결과를 찾았기 때문에 low와 high를 바꾸주면 된다.
    }while(low < high);                             // low가 high를 지나 칠 때까지 계속 반복

    swap(res[left], res[high]);                     // do-while문이 끝났다는 것은, high가 low를 지나쳤다는 의미이기 때문에 사실 high가 pivot의 low를 가리키고 있음
                                                    // 그래서 high에 있는 값과 left의 있는 값을 서로 교환해주면 됨. 그럼 high에 있는 값이 pivot기준점이 될거임. 
    return high;                                    // high에 있는 값이 새로운 pivot기준점이 된다. 이 기준점은 다음 분할정복 때 기준점으로 삼는다.
}

void QuickSort(vector<int> &res, int left, int right){

    if (left < right){                              // left < right이면 계속 분할을 시켜 정복한다. 이 조건문의 의미는 부분 리스트들이 0이거나 1이 될때까지 계속 나누겠다는 의미
        
        int pivot = partition(res, left, right);    // left right범위에서 피봇위치를 결정해주고 피봇 기준으로 작은 것 큰 것을 정렬한다. 

        QuickSort(res, left, pivot - 1);            // 피봇 기준으로 left에 있는 값 다시 분할 (pivot은 포함되면 안된다)
        QuickSort(res, pivot + 1, right);           // 피봇 기준으로 right에 있는 값 다시 분할 (pivot은 포함되면 안된다)
    }
}

void solution(){

    int n;

    vector<int> res;

    cin >> n;

    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        res.push_back(temp);
    }
    int size = res.size();

    QuickSort(res, 0, size - 1);

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