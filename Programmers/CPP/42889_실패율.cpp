#include <string>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

bool compare(pair<double, int> &a, pair<double, int> &b){
    if (a.first == b.first) return a.second < b.second;
    else return a.first > b.first;
}

int cnt[501];

vector<pair<double, int> > failure;

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    
    int stage_size = stages.size();
    
    for (int i = 0; i < stage_size; i++){
        cnt[stages[i]]++;
    }
    
    int mo = stage_size;
    
    for (int i = 1; i <= N; i++){
        
        if (!stage_size || cnt[i] == 0) failure.push_back({0, i}); // 0/x가 0이 아닐 수 있다. 이부분 주의해야한다. 0/x로 나눌 땐 컴퓨터에서는 항상 0이 아닐 수 있음.. 주의하기를..
        
        else{
            double t = (double)cnt[i] / mo;
        
            failure.push_back({t, i});
        }
        
        mo -= cnt[i];
        
    }
    
    sort(failure.begin(), failure.end(), compare);
    
    int failure_size = failure.size();
    
    for (int i = 0; i < failure_size; i++){
        auto p = failure[i];
        
        answer.push_back(p.second);
    }
    
    
    return answer;
}

int main(){
    vector<int> test;
    solution(0, test);

    return 0;
}