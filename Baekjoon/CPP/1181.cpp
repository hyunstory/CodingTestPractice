#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
#include <set>

using namespace std;

vector<pair<int, string>> v;
set<string> s;

bool compare(const pair<int, string> &a, const pair<int, string> &b){
    
    
    if (a.first == b.first){
        int minV;
        minV = min(a.second.length(), b.second.length());
        
        for (int i = 0; i < minV; i++){
            if (a.second[i] == b.second[i]) continue;

            return a.second[i] < b.second[i];

        }
    }
    return a.first < b.first;

    
}
void solution(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++){
        string temp;
        cin >> temp;

        
        if (s.find(temp) == s.end()) {
            v.push_back(make_pair(temp.length(), temp));
        

            s.insert(temp);
        }

    }

    sort(v.begin(), v.end(), compare);


    for (int i = 0; i < v.size(); i++){
        cout << v[i].second << '\n';
    }

}
int main(){

    solution();

    return 0;
}