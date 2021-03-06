/*
이현승
2020년12월11일

priority_queue는 우선순위 큐를 구현한 것이다.

priority_queue는 vector, deque랑 같이 사용할 수 있다.

queue라이브러리에 priority_queue가들어있다.

min heap, max heap으로 최댓값, 최솟값만 일정하게 출력할 때 가장 빠른 알고리즘.

heap정렬은 O(NlogN)이지만,

heap에 삽입은 O(logN)이라서 매번 원소를 삽입 후, 최솟값, 최댓값을 뽑아내기에는 가장 빠르다.



*/

#include <iostream>
#include <queue>

using namespace std;


//******중요!!

//customizing 비교

typedef struct ii{
        int cnt, i, j;
}ii;
bool operator <(ii u, ii v){ // > 로 바꾸면 인식을 못한다. 값을 받아와서 로직을 바꾼다. 0인덱스가 top, 정렬은 맨마지막인것처럼. 실제 top은 0인덱스****
        if (u.cnt == v.cnt) return u.i+u.j < v.i + v.j;
        return u.cnt > v.cnt;
}


void solution(){
    priority_queue<int> pq; // default 오름차순 less
    priority_queue<int, vector<int>, less<int> > pq_less; // 오름차순으로 정렬되는 생성자 -max heap 가장 큰것이 top에 위치해있다. 0인덱스가 top
    priority_queue<int, vector<int>, greater<int> > pq_greater; // 내림차순으로 정렬되는 생성자 - min heap 가장 작은것이 top에 위치해있다. 0인덱스가 top
    // ************ 위에서 greater<int>이다.. () 활성화 하지 않음!!**************

    
    priority_queue<ii> pq2; // struct ii와 operator <에 의해서 순서가 결정됨.
    

    

    


    pq.empty(); // 비어있는지
    pq.size(); // 사이즈 반환
    pq.top(); // 가장 위에 있는 원소 반환 오름차순이면 맨 마지막 배열인 가장 큰것, 내림차순이면 맨 마지막 배열인 가장 작은것
    pq.push(1); // 원소 삽입
    pq.pop(); // 맨 위에 있는, 맨 마지막에 있는 인자를 삭제한다. 

}
int main(){

    solution();

    return 0;
}
