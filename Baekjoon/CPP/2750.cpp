/*

2021년 1월 16일(토)
이현승


직접 Quick sort, Heap sort, Merge sort, Bubble sort, Selection sort, Insertion sort 6가지로 구현해보기!!




*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> answer;
vector<int> input;
vector<int> temp(1001,0);

int partition(vector<int> &v, int left, int right){

    int pivot = v[left];
    int low = left;
    int high = right + 1; // left는 피봇이 있기 때문

    do{
        do{
            low++;
        }while(low <= right && v[low] < pivot);

        do{
            high--;
        }while(left <= high && v[high] > pivot);

        if (low < high) swap(v[low], v[high]);

    }while(low < high);

    swap(v[left], v[high]); // 마지막에 피봇을 정가운데에 위치시킨다.

    return high;

}

void quickSort(vector<int> &v, int left, int right){
    
    if (left < right){

        int pivot = partition(v, left, right);

        quickSort(v, left, pivot - 1);
        quickSort(v, pivot + 1, right);
    }
    

}

void Merge(vector<int> &res, int left, int mid, int right){

    int lv = left;
    int rv = mid + 1;
    int t_idx = left;

    while(lv <= mid && rv <= right){
        if (res[lv] <= res[rv]) temp[t_idx++] = res[lv++];
        else temp[t_idx++] = res[rv++];
    }

    if (lv > mid){ // left의 인덱스가 mid를 넘어가면 Right에 남아있는 값들을 다 넣어준다. rv부터 right까지 다 넣어준다.
        for (int p = rv; p <= right; p++){
            temp[t_idx++] = res[p];
        }
    }
    else{
        for (int p = lv; p <= mid; p++){
            temp[t_idx++] = res[p];
        }
    }

    // 그대로 복사해주기
    for (int p = left; p <= right; p++){
        res[p] = temp[p];
    }

}
void MergeSort(vector<int> &res, int left, int right){
    
    if (left < right){
        int mid = (left + right) / 2;

        MergeSort(res, left, mid);
        MergeSort(res, mid + 1, right);
        Merge(res, left, mid, right);

    }

}

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

void InsertionSort(vector<int> &res, int n){
    int temp, key;

    for(int i = 1; i < n; i++){
        int key = res[i];

        for (temp = i - 1; temp >= 0 && res[temp] > key; temp--){
            res[temp + 1] = res[temp];
        }

        res[temp + 1] = key;

    }
    
}
void BubbleSort(vector<int> &res, int n){
    for (int i = n - 1; i >= 0; i--){
        for (int j = 0; j < i; j++){
            if (res[j] > res[j + 1]){
                swap(res[j], res[j + 1]);
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
        input.push_back(temp);
    }

    int size = input.size();

    //quickSort(input, 0, size - 1);
    //HeapSort();
    //MergeSort(input, 0, size - 1);
    //BubbleSort(input, n);
    //SelectionSort(input, n);
    //InsertionSort(input, n);

    for (int i = 0; i < size; i++){
        cout << input[i] << '\n';
    }


}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}