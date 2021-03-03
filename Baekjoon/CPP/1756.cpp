#include <iostream>

using namespace std;

const int MAX = 300001;


int darr[MAX];
int narr[MAX];
int d, n;

int visit[MAX];

void solution(){
    cin >> d >> n;

    for (int i = 0; i < d; i++){
        cin >> darr[i];

        if (i != 0 && darr[i - 1] < darr[i]) darr[i] = darr[i-1];
    }

    for (int i = 0; i < n; i++){
        cin >> narr[i];
    }

    int cnt = 0;

    for (int i = d - 1; i >= 0; i--){

        if (narr[cnt] <= darr[i]){
            
            visit[cnt] = i + 1;
            cnt++;
        }

        if (cnt == n) break;   
    }   

    if (cnt == n) cout << visit[cnt - 1] << '\n';
    else cout << 0 << '\n';

}
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}