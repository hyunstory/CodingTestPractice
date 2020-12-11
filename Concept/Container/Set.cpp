/*
이현승
2020년12월11일

set은 노드 기반 컨테이너 이며, 균형 이진트리로 구성되어있다.

key라고 불리는 원소들의 집합으로 이루어진 컨테이너이다. 원소 = key

!!! key값은 중복 허용이 되지 않는다.

!! 원소가 insert 멤버 함수에 의해 삽이이 되면, 원소는 자동 정렬  default는 오름차순!!!

set은 중위 순위로 출력이 가능하다
*/

#include <iostream>
#include <set>

using namespace std;

// !-- 정렬 기준 바꾸는 방법 -- //
/*구조체를 만들어서 operato()(){}함수를 만든다. */
struct pred{
    bool operator() (const string &a, const string &b) const{
        if (a.size() == b.size()) return a < b;
        else return a.size(), b.size();

    }
};



void solution(){

    //선언 방법
    set<int> s;
    set<int> s1;
    set<pair<int, string>> s2;

    // 생성자와 연산자
    set<int> s(pred); //pred에 의해 정렬기준을 세운다.

    // s1을 복사
    set<int> s3(s1);

    // set의 멤버 함수

    set<int> ::iterator iter, start, end;

    // reverse begin end
    s1.rbegin(); s1.rend();

    // 원소제거 
    s.clear();

    // 특정 원소개수 반환
    //s.count(1) -> 1혹은 0이다. find 대신 사용하기 좋다.

    //삽입
    //s.insert(값);
    
    //특정 위치부터 삽입
    //s.insert(inter, k);

    // 지우기
    s.erase(iter);
    s.erase(start, end);

    // 찾기
    //s.find(v) -> iter반환, 없으면 end반환
    //s.count(v) -> 있으면 1, 없으면 0

    // 기타

    s.swap(s1);

    s1.size();






}

int main(){

    solution();

    return 0;
}