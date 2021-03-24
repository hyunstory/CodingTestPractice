/*
C++의 list는 더블 링크드리스트(double linked list)와 구조가 같다.

list는 sequence container의 일종으로 선서를 유지하는 구조이다.
노드기반 컨테이너

vector, deque와 다르게 멤버함수에서 정렬(sort, merge), 이어붙이기(splice)가 있다.

원소를 탐색할 때 반복자(at(), [])사용이 불가능, 양방향 반복자(++, --)만 이용해서 탐색이 가능하다.

push_back(), push_front(), pop_front(), pop_back() 멤버 함수를 이용해서 list 양 끝에서 삽입, 삭제가 가능하다.

insert(), erase() 멤버 함수를 통해서 노드 중간에서도 삽입, 삭제가 가능하다.

선언 list<[Data type]> [변수이름];




*/

#include <iostream>
#include <list>

using namespace std;

bool cmp(const int &first, const int &second){
    return first > second;
}

bool predi(int num){
    return num >= 100 && num <= 200;
}

void solution(){
    list<int> lt1;          // 비어있는 ㅣist 컨테이너 lt1 생성
    list<int> lt2(10);      // 0으로 초기화 된 원소 10개를 가진 list를 생성
    list<int> lt3(lt1);     // lt1을 lt3로 복사

    lt1.assign(3, 4);       // 4로 초기화된 3개의 원소를 할당
    lt1.front();            // 가장 첫번째 원소
    lt1.back();             // 가장 마지막 원소
    lt1.begin();            // 가장 첫번째 iterator
    lt1.end();              // 가장 마지막 iterator

    lt1.rbegin();
    lt1.rend();

    lt1.push_back(1);
    lt1.push_back(2);
    lt1.push_front(0);
    lt1.pop_front();
    lt1.pop_back();

    lt1.insert(lt1.begin(), 0); // begin위치에 0을 삽입
    lt1.erase(lt1.begin());     // begin위치에 있는 것 삭제

    lt1.size();

    lt1.remove(0);          // 해당 원소를 모두 제거

    lt1.reverse();

    lt1.sort();             // 오름차순
    lt1.sort(cmp);          // 내림차순 커스터마이징

    lt1.swap(lt2);          //lt1과 lt2 교환

    lt2.splice(lt1.begin(), lt1); // iter가 가르키는 곳에 lt1의 모든 원소를 잘라 붙인다.

    lt1.unique();           // 인접한 노드의 값이 같으면 1개만 만든다.
    lt1.merge(lt2);         // lt1과 lt2를 합치는데, 오름차순으로 합친다.
    lt1.merge(lt2, cmp);    // lt1과 lt2를 합치는데, 내침차순으로 합친다.

    lt1.remove_if(predi);   // predi에 맞는 조건을 가진 원소를 삭제하기


    //출력:
    for (auto iter = lt1.begin(); iter != lt.end(); iter++){
        cout << *iter << ' ';
    }

}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}