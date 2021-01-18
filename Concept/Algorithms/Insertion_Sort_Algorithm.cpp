/*
Insertion Sort

2021년 1월 18일
이현승 작성

삽입 정렬.

인덱스 1부터 key값으로 시작해서

해당 인덱스 이하에 있는 값들을 순차적으로 비교하면서 적당한 위치에 찾았다면 삽입하는 형식.
순차적으로 비교할 때 배열을 오른쪽으로 한칸씩 옮기면서 삽입한다. 

최상의 경우 O(N)이 나오지만,(정렬이 되어있는 경우)
최악은 O(N^2)
평균 O(N^2)의 시간복잡도를 가지고 있다. 

원리:
1. 인덱스를 1부터 n까지 선택한다.
2. 선택한 인덱스로부터 기준을 삼아 밑에 있는 인덱스들을 다 비교하면서 선택한 인덱스 값보다 작은 값을 찾는다(오름차순 정렬 기준)
3. 선택한 인덱스로부터 기준을 삼아 밑에 있는 인덱스를을 다 비교하면서 for이 끝날 때 까지 오른쪽으로 모두 1칸 shift한다.
4. for이 끝났다면 인덱스는 -1만큼 작아져있기 때문에 res[temp + 1] 즉, 1을 더해주어 해당 공간에 key값을 넣어준다.

1개씩 비교하면서 정렬하지만, 
이미 정렬이 되어있는 배열을 정렬하게 되면 약 O(N)정도의 시간복잡도가 나온다.
랜덤한 상황에서는 평균 O(N^2)의 시간복잡도가 나온다. 


*/

#include <iostream>
#include <vector>

using namespace std;

vector<int> res;


void InsertionSort(vector<int> &res, int n){
    int temp, key;

    for (int i = 1; i < n; i++){
        key = res[i];

        for (temp = i - 1; temp >= 0 && res[temp] > key; temp--){ // res[temp] > key 이부분이 중요하다.
            res[temp+1] = res[temp];
        }

        res[temp+1] = key; // for문에 의해 temp는 이미 -1만큼 진행한 상태이기 때문에 +1값을 해주어 옳바른 인덱스에 key값을 넣어준다. 
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

    InsertionSort(res, n);

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
