#include <iostream>

using namespace std;

const int MAX = 10000;

int n, m;

int inst[MAX];

long long bs(){
    long long low = 0, high = 2000000000LL * 30LL;
    long long result = -1;

    while(low <= high){
        long long mid = (low + high) / 2;
        long long children = m;

        for (int i = 0; i < m; i++){
            children += mid / inst[i];

        }

        if (children >= n){
            result = mid;
            high = mid - 1;
        }
        else low = mid + 1;
    }

    return result;
}

void solution(){

    cin >> n >> m;

    for (int i = 0; i < m; i++) cin >> inst[i];

    if (n <= m){
        cout << n << '\n';
        return;
    }


    long long t = bs();

    long long children = m;

    for (int i = 0; i < m; i++) children += (t - 1) / inst[i];


    for (int i = 0; i < m; i++){

        if (!(t % inst[i])) children++;

        if (children == n){
            cout << i + 1 << '\n';
            break;
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