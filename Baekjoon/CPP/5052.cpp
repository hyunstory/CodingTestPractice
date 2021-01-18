#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;

int n;

const int MAX = 11;

struct Trie{
    int is_finish, is_child;
    Trie *Node[MAX];

    Trie(){
        is_finish = is_child = false;
        fill(Node, Node + MAX, nullptr);

    }
    ~Trie(){
        for (int i = 0; i < MAX; i++){
            if (Node[i]) delete Node[i];
        }

    }

    void insert(string &word, int word_size, int cur_idx){
        if (word[cur_idx] == '\0'){
            is_finish = true;
            return;
        }

        int word_idx = word.at(cur_idx) - '0';

        if (Node[word_idx] == NULL){
            is_child = true;
            Node[word_idx] = new Trie();
        }

        Node[word_idx]->insert(word, word_size, cur_idx + 1);

    }
    bool find(string &word, int word_size, int cur_idx){

        if (word[cur_idx] == '\0'){
            return false;
        }

        if (is_finish) return true;

        int word_idx = word.at(cur_idx) - '0';

        return Node[word_idx] -> find(word, word_size, cur_idx + 1);

        

    }

};

void solution(){

    int t;
    
    cin >> t;
    while(t--){
        cin >> n;
        Trie *root = new Trie();

        vector<pair<int,string>> v;

        bool is_yes = true;

        for (int i = 0; i < n; i++){
            string s;
            cin >> s;

            int s_size = s.length();
            root->insert(s, s_size, 0);

            v.push_back({s_size, s});

        } 

        for (int i = 0; i < n; i++){
            int s_size = v[i].first;
            string s = v[i].second;

            if (root->find(s, s_size, 0)){
                cout << "No" << '\n';
                is_yes = false;
                break;
            }

            
        }
        if(is_yes) cout << "YES" << '\n';
        delete root;

    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}