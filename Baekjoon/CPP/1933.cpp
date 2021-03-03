#include <iostream>
#include <queue>
#include <vector>

using namespace std;

const int MAX = 100001;

priority_queue<long long, vector<long long>, less<long long> > v[MAX];



void solution(){
    int n;

    cin >> n;

    for (int i = 0; i < n; i++){
        long long l, h, r;
        

        cin >> l >> h >> r;

        for (long long j = l; j <= r; j++){

            v[j].push(h);
            
        }
        
    }
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}