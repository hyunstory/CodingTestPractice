/*
    이현승
    2020년12월11일
    노드 기반으로 이루어져있고 균형 이진트리이다.     Red-black tree라고 불린다. (키의 분포가 고르지 못할 경우 balancing에 대한 비용이 들어가서 insert, delete에 성능이 저하될 수 있다.)
    최악의 경우 O(logN) 보장한다.
    수가 많아질수록 ( >512)  확 올라간다 

    // !-- 고려해보야할 사항 -- //
    유사도가 높은 문자열은 map의 성능을 떨어뜨린다.
    문자열을 키로 사용하는 경우 문자열이 길어질 수록 unordered_map이 map에 비해 성능이 확 떨어질 수 있다.
    

    // ------------------- //

    key와 value로 이루어져 있다.

    key는 고유한 값으로 중복이 불가능 ( 중복 key는 multimap 에서 가능!! 알아보기 mutimap)

    삽입이 되면 key값에 의해 자동으로 정렬이 된다. default 오름차순 less

    중위순회로 값을 찾을 수 있다.


    동적할당
*/

#include <iostream>
#include <map>

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

    // 생성 방법 map< [Data type1], [Data type2] > [변수이름]

    map<int, int> m;
    map<int, int> m1;
    map<string, int> m2;

    //m에 삽입하려면 pair 객체를 인자로 받아야한다. 

    // pred를 통해 정렬기준(오름, 내림을 세운다) default = less
    map<int, int> m(pred);

    //복사
    //map<int, int> m2(m1);

    //수정, 추가
    m1[1] = 2;

    
    // 맴버함수 목록

    m.begin();
    m.end();
    m.rbegin();
    m.rend();
    m.clear();
    //m.count(k); k(Key)가 있으면 1반환, 없으면 0반환
    //m.insert(k); k는 pair 객체이다
    //m.insert(iter, k); iter에 위치에 k삽입
    //m.erase(start, end);
    //m.find(k); // -> 찾았으면 해당 iter를 아니면, end를 반환
    
    m.size();

 



}
int main(){


    solution();

    return 0;
}
