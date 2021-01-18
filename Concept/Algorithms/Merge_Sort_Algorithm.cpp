/*

Merge Sort

2021년 1월 18일
이현승 작성

머지소트 - 존 폰 노이만 천재 아저씨가 만든 알고리즘. 반신반인이라고도 불렸음. 자기가 만든 컴퓨터 보다 암산이 더 빠를정도.

이 정렬은 (left + right) / 2 을 나누어 정렬한다. 분할 정복 알고리즘 하나이고, 안정 정렬에 속한다.
평균적으로 O(NlogN)이 나온다. 최악의 경우도, O(NlogN)을 보장한다.

분할정복은 대게 재귀 호출(순환호출)을 사용하여 구현한다. 

과정: 
1. 리스트 길이가 0, 1이면 이미 정렬된 것으로 본다.
2. 정렬되지 않은 리스트를 절반으로 나누어 길이가 0, 1이 될 때까지 계속 자르면서 재귀 호출한다. mid = (left + right) / 2 -> left, mid || mid + 1, right
3. 길이가 0,1이 된다면, 재귀적으로 합병 정렬을 이용해 정렬한다. 두개의 리스트를 대소 비교해서 또 다른 리스트에 임시 저장 후, 모두 비교가 되었다면 다시 원래 리스트로 복사

*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> res;
vector<int> temp(1001, 0);

void Merge(vector<int> &res, int left, int mid, int right){
    int lv = left;          // 두 개의 리스트 중 왼쪽에 해당하는 리스트의 첫 번째 인덱스
    int rv = mid + 1;       // 두 개의 리스트 중 오른쪽에 해당하는 리스트의 첫 번째 인덱스. 왼쪽은 left~mid, 오른쪽은 mid+1~right이기 때문에 mid+1이 오른쪽의 첫번째 인덱스이다.
    int temp_idx = left;    // 임시로 만든 배열의 인덱스는 왼쪽 배열에 있는 인덱스 값을 넣어준다. (init)

    while(lv <= mid && rv <= right){                            // 왼쪽 배열, 오른쪽 배열 하나 중이라도 지정한 범위를 넘어가면 break, 지정범위: (left ~ mid, mid+1 ~ right)
        if (res[lv] <= res[rv]) temp[temp_idx++] = res[lv++];   // 후위 연산자를 사용하면서 왼쪽에 있는 배열 값이 더 작다면 왼쪽에 있는 값을 임시 배열에 저장 (오름차순 정렬의 경우는 반대로)
        else temp[temp_idx++] = res[rv++];                      // 후위 연산자를 사용하면서 오른쪽에 있는 배열 값이 더 작다면 오른쪽에 있는 값을 임시 배열에 저장 (오름차순 정렬의 경우는 반대로)
    }

    if (lv > mid){                                              // 만약 왼쪽 배열이 최초로 지정 범위를 벗어났다면, 오른쪽에 남은 값들을 임시 배열에 다 저장.
        for (int p = rv; p <= right; p++){
            temp[temp_idx++] = res[p];
        }
    }
    else{                                                       // 만약 오른쪽 배열이 최초로 지정 범위를 벗어났다면, 왼쪽에 남은 값들을 임시 배열에 다 저장.
        for (int p = lv; p <= mid; p++){
            temp[temp_idx++] = res[p];
        }
    }

    for (int p = left; p <= right; p++){                        // 임시 배열에 저장된 값들 모두 원래 배열에 복사
        res[p] = temp[p];

    }
}

void MergeSort(vector<int> &res, int left, int right){

    if (left < right){
        int mid = (left + right) / 2;

        MergeSort(res, left, mid);          // 리스트 길이가 0 혹은 1이 될 때까지 나누어 준다.
        MergeSort(res, mid + 1, right);     // 리스트 길이가 0 혹은 1이 될 때까지 나누어 준다.
        Merge(res, left, mid, right);       // 길이가 0 혹은 1이 되었다면 Merge하면서 정렬한다.
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

    int size = res.size();

    MergeSort(res, 0, size - 1);

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