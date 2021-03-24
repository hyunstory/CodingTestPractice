/*
나한테 필요한 것들만 작성

!<-- 원소를 수정하지 않는 작업들 -->
find : 범위 안에 원소들 중 값이 일치하는 원소를 찾는다.

count : 특정 값과 일치하는 원소의 개수를 센다.

!<-- 순열 관련 -->
is_permutation : 어떤 원소의 나열이 다른 원소의 나열의 순열임을 확인한다.

next_permutation : 특정 원소들의 다음 순열을 얻는다.

prev_permutation : 특정 원소들의 이전 순열을 얻는다.

!<-- 원소를 수정하는 작업들 -- >
swap : 두 원소를 서로 교환한다.

transform : 특정 범위의 원소들을 변환한다.

replace : 특정 범위의 원소들을 치환한다.

fill : 특정 범위를 어떤 값으로 채운다.

reverse : 특정 범위의 원소들의 순서를 거꾸로 한다.

rotate : 왼쪽으로 원소들을 회전시킨다 (첫번째 원소를 제외한 나머지 원소들을 왼쪽으로 쉬프트 한 후, 맨 왼쪽에 있었던 원소는 맨 뒤로 감)

백터.erase(unique(s.begin(),s.end()),s.end()) : 중복된 원소들을 제거한다. -> 중복된 원소를 멘 뒤에 보내고 그 값들을 지운다.

!<-- 정렬 -->
sort : 특정 범위의 원소들을 정렬한다.

is_sorted : 어떤 원소들이 정렬되어 있는지 확인한다.

!<-- 이진 탐색 -->
lower_bound : 특정 값보다 작지 않는 첫 번째 원소를 찾습니다. (하한)

upper_bound : 특정 값보다 큰 첫 번째 원소를 찾습니다. (상한)

* upper_bound - lower_bound = 같은 갯수 구하기

binary_search : 특정 값과 일치하는 원소를 찾습니다.

!<-- 집합 -->
set_union : 두 정렬된 원소들의 합집합을 구한다. (A\cup BA∪B)

set_intersection : 두 정렬된 원소들의 교집합을 구한다. (A\cap BA∩B)

set_difference : 두 정렬된 원소들의 차집합을 구한다. (A-BA−B)

!<-- heap -->
push_heap : 힙에 원소를 삽입한다.

pop_heap : 힙에서 원소를 제거한다. 맨 마지막으로 원소를 넣기 때문에 pop_back()을 꼭 수행해주어야만, 원소가 pop된다!!

make_heap : 특정 원소들을 힙으로 만든다.

sort_heap : 힙의 원소들을 정렬한다.

is_heap : 특정 범위의 원소들이 힙인지 확인한다.

!<-- 최대/최소 -->
min : 최소 원소를 찾는다.

max : 최대 원소를 찾는다.

min_element : 최소 원소를 찾는다. (이 때 해당 원소를 가리키는 반복자를 리턴함)

max_element : 최대 원소를 찾는다. (이 때 해당 원소를 가리키는 반복자를 리턴함)

minmax_element: 최솟값, 최댓값 원소의 iterator를 반환한다.
auto p = minmax_element(a.begin(), a.end());
cout << *p.first << '\n'; 은 최솟값
cout << *p.second << '\n'; 은 최댓값


*/

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;




void solution(){

vector<int> v;
vector<int> s;

//!<-- 원소를 수정하지 않는 작업들 -->
//find : 범위 안에 원소들 중 값이 일치하는 원소를 찾는다.
if(find(v.begin(), v.end(), 1) != v.end()){
    // 원소는 존재함.
}

//count : 특정 값과 일치하는 원소의 개수를 센다.
int mycount = count(v.begin(), v.end(), 1);

//!<-- 순열 관련 -->
//next_permutation : 특정 원소들의 다음 순열을 얻는다. // 조합 (순열?조합->조합?)
do{

    for (int i = 0; i < v.size();i++){
        cout << v[i] << ' ';
    }
    cout << '\n';

}while(next_permutation(v.begin(), v.end())); // 조합 구하기

//prev_permutation : 특정 원소들의 이전 순열을 얻는다.
prev_permutation(v.begin(), v.end());


//!<-- 원소를 수정하는 작업들 -- >
//swap : 두 원소를 서로 교환한다.
int a = 1, b = 2;
swap(a, b);

//transform : 특정 범위의 원소들을 변환한다.
transform(v.begin(), v.end(), v.begin(), ::toupper);

//replace : 특정 범위의 원소들을 치환한다.
replace(v.begin(), v.end(), 8, 88); //8 -> 88

//fill : 특정 범위를 어떤 값으로 채운다.
fill(v.begin(), v.end(), 0);

//reverse : 특정 범위의 원소들의 순서를 거꾸로 한다.
reverse(v.begin(), v.end());

//rotate : 왼쪽으로 원소들을 회전시킨다 (첫번째 원소를 제외한 나머지 원소들을 왼쪽으로 쉬프트 한 후, 맨 왼쪽에 있었던 원소는 맨 뒤로 감)
// 원형 큐 만들때 사용하면 좋을 듯!!
rotate(v.begin(), v.begin() + 1, v.end()); // 1칸씩 rotate하겠다.

v.erase(unique(s.begin(),s.end()),s.end());

//!<-- 정렬 -->
//sort : 특정 범위의 원소들을 정렬한다.
sort(v.begin(), v.end()); // 오름차순 정렬
//내림차순 정렬
sort(v.begin(), v.end(), greater<int>()); // **** 중요한점 !!! 정렬시에는 grater<int>() 활성화

//is_sorted : 어떤 원소들이 정렬되어 있는지 확인한다.
if (is_sorted(v.begin(), v.end())){
    // 정렬 되어있음.
}


//!<-- 이진 탐색 -->
//lower_bound : 특정 값과 같거나 작지 않는 첫 번째 원소를 찾습니다. (하한) 111222 맨 왼쪽 1
auto lower = lower_bound(v.begin(), v.end(), 4); // iter 반환

//upper_bound : 특정 값보다 큰 첫 번째 원소를 찾습니다. (상한)   111222 2 맨왼쪽
auto upper = upper_bound(v.begin(), v.end(), 4);

//* upper_bound - lower_bound = 같은 갯수 구하기

//binary_search : 특정 값과 일치하는 원소를 찾습니다.
if(binary_search(v.begin(), v.end(), 3)){
    // 있음
}

//!<-- 집합 -->
//set_union : 두 정렬된 원소들의 합집합을 구한다. (A\cup BA∪B)

// 공간 할당이 중요함..!!
vector<int> vec1;
vector<int> vec2;
vector<int> buf(vec1.size() + vec2.size());
auto iter = set_union(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buf.begin()); // 두개의 컨테이너 시작 끝, 그리고 담을 컨테이너의 시작점 삽입.
buf.erase(iter, buf.end()); // 합집합, 교집합 후, 끝점을 반환하기 때문에, 그 부분부터 buf.end()까지 삭제하면 공간을 불필요하게 쓸 필요가 없다.

//set_intersection : 두 정렬된 원소들의 교집합을 구한다. (A\cap BA∩B)
buf.resize(vec1.size() + vec2.size());
auto iter = set_intersection(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buf.begin()); // 두개의 컨터이너의 시작 끝, 그리고 담을 컨테이너의 시작점 삽입
buf.erase(iter, buf.end()); 

//set_difference : 두 정렬된 원소들의 차집합을 구한다. (A-BA−B)
buf.resize(vec1.size() + vec2.size());
auto iter = set_difference(vec1.begin(), vec1.end(), vec2.begin(), vec2.end(), buf.begin());
buf.erase(iter, buf.end());


//!<-- heap -->
//push_heap : 힙에 원소를 삽입한다. 이미 만들어진 heap에 추가하는 형식
push_heap(v.begin(), v.end(), greater<int>()); // O(logN) 최대 logN

//pop_heap : 힙에서 원소를 제거한다. root노드를 제거

//*********** 중요함!!!! pop_heap은 맨 마지막으로 보내버린다!!! pop_back을 해주어야함!!!
pop_heap(v.begin(), v.end()); //-> 맨 마지막으로 보내기 때문에 pop_back()을 무조건 해줘야한다.
// +
v.pop_back();
//************

//make_heap : 특정 원소들을 힙으로 만든다.
make_heap(v.begin(), v.end(), greater<int>()); // log(N), 최대 3N 

//sort_heap : 섞인 힙의 원소들을 정렬한다. 
sort_heap(v.begin(), v.end());

//is_heap : 특정 범위의 원소들이 힙인지 확인한다.
if (is_heap(v.begin(), v.end())){
    // heap이 맞음.
}

//!<-- 최대/최소 -->
//min : 최소 원소를 찾는다.
min(1, 2);

//max : 최대 원소를 찾는다.
max(1, 2);

//min_element : 최소 원소를 찾는다. (이 때 해당 원소를 가리키는 반복자를 리턴함)
cout << *min_element(v.begin(), v.end());

//max_element : 최대 원소를 찾는다. (이 때 해당 원소를 가리키는 반복자를 리턴함)
cout << *max_element(v.begin(), v.end());



}
int main(){

    solution();

    return 0;
}