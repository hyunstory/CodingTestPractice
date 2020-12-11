/*

hash_table을 통해 참조하기 때문에 각 node를 정렬할 필요가 없다!! 정말 빠르다

6만5천개의 key값을 넣어도 속도가 아주 빠르지만, 
key가 많아질수록 해쉬 충돌이 일어날 수 있지만, 그래도 빠르다.

// !-- 고려해보야할 사항 -- //
단, 문자열을 키로 사용하는 경우 문자열이 길어질 수록 unordered_map이 map에 비해 성능이 확 떨어질 수 있다.
유사도가 높은 문자열은 map의 성능을 떨어뜨린다.

// ------------------- //

정렬된 map을 사용해야하는게 아니라면 unorderd_map을 사용하면 좋다!


*/


#include <iostream>
#include <unordered_map>


void solution(){


}
int main(){


    solution();

    return 0;
}