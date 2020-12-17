/*
Trie예제 문제 - 백준 14426, 접두사 찾는 문제


*/

#include <iostream>
#include <vector>
#include <cstring>
#include <string>

using namespace std;

#define SIZE 30


struct Trie {
	bool is_child, is_finish;

	Trie *Node[SIZE];

	Trie() {
		is_child = is_finish = false;
		fill(Node, Node + SIZE, nullptr);
	}
	~Trie() {
		for (int i = 0; i < SIZE; i++) {
			if (Node[i]) delete Node[i];
		}

	}

	void insert(string &word, int word_size, int idx) {
		if (idx >= word_size) {
			is_finish = true;
			return;
		}

		int word_idx = word.at(idx) - 'a';

		if (Node[word_idx] == NULL) {
			is_child = true;
			Node[word_idx] = new Trie();
		}

		Node[word_idx]->insert(word, word_size, idx + 1);

	}

	bool find(string &word, int word_size, int idx) {

		if (idx >= word_size) {
			if (is_child || is_finish) {  // 접두사 찾는 문제가 아니라, 단순 문자열 찾는 문제라면, is_finish가 true일 때 Return true를 한다.
				return true;
			}
			else return false;
		}

		int word_idx = word.at(idx) - 'a';

		if (Node[word_idx] == NULL || !is_child || is_finish) {
			return false;
		}

		bool res = Node[word_idx]->find(word, word_size, idx + 1);

		return res;

	}
};


void solution() {

	int n, m;

	cin >> n >> m;

	Trie root;

	for (int i = 0; i < n; i++) {
		string t;
		cin >> t;

		root.insert(t, t.length(), 0);
		
	}
	int res = 0;
	for (int i = 0; i < m; i++) {
		string t;

		cin >> t;

		if (root.find(t, t.length(), 0)) {
			res++;
		}
	}


	cout << res;

}


int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	solution();


	return 0;
}