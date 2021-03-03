#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>

using namespace std;

#define f first
#define s second

const int MAX = 100000;

int n;
pair<int, int> arr[MAX];
set<int> save;

int result[MAX];

int go(){

    priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;

    int seat = 0;

    for (int i = 0; i < n; i++){
        
        while(!pq.empty()){
            if (pq.top().f <= arr[i].f){
                save.insert(pq.top().s);
                pq.pop();
            } 
            else break;
        }

        if (save.empty()){
            pq.push({arr[i].s, seat});
            result[seat]++;
            seat++;
        } else{
            auto idx = save.begin();
            pq.push({arr[i].s, *idx});
            result[*idx]++;
            save.erase(idx);
        }
    }

    return seat;
}

void solution(){
    cin >> n;

    for (int i = 0; i < n; i++){
        cin >> arr[i].f >> arr[i].s;

    }

    sort(arr, arr + n);


    int seat = go();

    cout << seat << '\n';

    for (int i = 0; i < seat; i++) cout << result[i] << ' ';

    cout << '\n';

}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}