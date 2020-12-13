#include <iostream>
#include <set>
#include <string>
#include <deque>
#include <algorithm>

using namespace std;


// map은 저장할 때 자동으로 key에 따라 오름차순으로 저장한다.
// map은 중복을 허용하지 않아, 중복된 key를 입력하면 역할을 제대로 하지 않는다.


void solution() {


	int n, m;

	cin >> n >> m;

	set<string> s1;
	set<string> s2;

	deque<string> result;

	


	for (int i = 0; i < n; i++) {
		string temp;

		cin >> temp;
		s1.insert(temp);
		

	}

	for (int i = 0; i < m; i++) {
		string temp;
		cin >> temp;
		s2.insert(temp);


	}



	set<string>::iterator iter1;
	set<string>::iterator iter2;

	for (iter1 = s1.begin(); iter1 != s1.end(); ++iter1) {
		
		//cout << *iter1 << '\n';
		string temp = (*iter1);

		iter2 = s2.find(temp);

		if (iter2 != s2.end()) {
			result.push_back(temp);
		}
	}

	cout << result.size() << '\n';
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << '\n';
	}
	

}

int main() {



	solution();

	return 0;
}