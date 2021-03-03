/*
유니온 파인드

백준 예제 문제 : 1717

2021년 1월 20일
이현승 작성

이전에 풀어 본 문제지만, 개념 정리를 다시한번 해보았다.

유니온 파인드는 어떤 노드의 최상의 부모노드를 가리킴으로써 하나의 큰 집합을 만들게 된다. 

처음, 각 노드마다 자신을 가리키는 것으로 초기화 후,

입력을 받으면서 노드가 가르키는 값을 설정한다. 

union과 find 연산은 동시에 이루어 지게 된다.
하나의 노드를 선택 후, 계속 탐색하면서 자기 자신이 나올 때까지 재귀호출로 탐색을 한다. 내 자신이 나오게 된다면,
반환하면서 각 노드에 있는 값을 최상의 부모노드 (자기 자신이 나왔던 노드)를 대입하면서 반환한다. 그럼 재귀 호출 했던 모든 노드에 최상의 부모 노드의 값이 들어있다.



MST에서 union find의 최상 부모가 같다는 의미는, 싸이클이 생겼다라고 할 수 있다. 
모든 노드를 따라가면서 union-find를해주면 최상의 부모가 같다면 싸이클이 생긴것이다. -> MST에서 크루스칼이 uion-find를 이용한 MST 알고리즘이다.

이 문제의 경우, 수가 큰 노드가 최상위 부모의 역할을 하게 된다.


*/

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m;

int tree[1000001];
int parent[1000001];

int find(int x) {
	if (x == tree[x]) return x;
	else return tree[x] = find(tree[x]);
}

// <!-- Merge 코드 !!! 중요합니다. 합칠 때 -->

void merge(int x, int y){
	x = find(x);
	y = find(y);

	if (x == y) return;

	//작은 것이 parent가 될수있도록

	if (x < y) parent[y] = x;
	else parent[x] = y;
}

///////////////////

void solution() {

	cin >> n >> m;

	for (int i = 0; i <= n; i++) tree[i] = i;

	for (int i = 0; i < m; i++) {
		int cmd, a, b;

		cin >> cmd >> a >> b;

		if (cmd == 0) {
			a = find(a);
			b = find(b);

			if (a > b) tree[a] = b;
			else if (a < b) tree[b] = a;
		}
		else if (cmd == 1) {
			a = find(a);
			b = find(b);
			if (a == b) cout << "YES\n";
			else cout << "NO\n";
		}
	}


}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();

	return 0;
}