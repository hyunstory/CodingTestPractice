/*
이현승
2020년12월11일

container 간략하게 설명. 어렵지 않고 많이 쓰는 컨테이너라서 설명은 짧게되어있음

*/

#include <iostream>
#include <vector>

using namespace std;

void solution(){

    int n = 3; //임시 변수
    //생성
    vector<int> v;

    // 갯수초기화
    vector<int> v1(5);

    // 크기, 원소 초기화, 5개를 0으로 초기화
    vector<int> v2(5, 0);

    // 2의 값으로 5개의 원소 할당
    v.assign(5, 2);
    
    //벡터 복사
    v.assign(v1.begin(), v1.end());

    // 기본적인 기능 설명 생략, 이정도는 알아야함. 모르면 그냥..헤
    v[0];
    v.front();
    v.back();
    v.clear();
    //v.push_back(원소);
    v.pop_back();
    v.begin();
    v.end();
    v.rbegin();
    v.rend();
    v.size();

    v.swap(v1);

    //v.insert(2, 3, 4); // 2번째 위치에 3개의 4를 넣는다.

    //v.insert(2, 3); // 2번 째 위치에 3을 넣음

    v.empty();
    //크기 n으로 다시 바꾼다.
    v.resize(n);

    // 크기 n으로 0 으로원소 초기화
    v.resize(n, 0);
    
}
int main(){

    solution();

    return 0;
}