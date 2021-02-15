#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int k;

int st[1001];

vector<pair<int, pair<int, int>>> v; // 번호, 추천, 올드


bool compare(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
    if (a.second.first == b.second.first) return a.second.second > b.second.second;
    else return a.second.first > b.second.first;

    
}
bool resCom(pair<int,pair<int,int>> &a, pair<int,pair<int,int>> &b){
    return a.first < b.first;
}

int isIn(int val){
    int v_size = v.size();

    for (int i = 0; i < v_size; i++){
        int t = v[i].first;
        if (t == val) return i;
    }

    return -1;
}
void solution(){
    cin >> n >> k;

    for (int i = 1; i <= k; i++){
        cin >> st[i];
        int val = st[i];

        int o = isIn(val); // 음수는 존재 x, 양수는 인덱스 알려주기
        if (o >= 0){
            v[o].second.first++;
        }
        else {
            //액자에 없음

            if (v.size() >= n){
                sort(v.begin(), v.end(), compare);

                v.pop_back();
            }

            pair<int, pair<int,int>> p;
            p.first = val;
            p.second.first = 1;
            p.second.second = i;
            v.push_back(p);
        }
    }
    

    sort(v.begin(), v.end(), resCom);
    int v_size = v.size();
    for (int i = 0; i < v_size; i++){
        cout << v[i].first << ' ';
    }


}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}