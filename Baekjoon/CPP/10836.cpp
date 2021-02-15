#include <iostream>
#include <vector>
using namespace std;

int m, n;

void solution(){

    cin >> m >> n;

    vector<int> arrs(2*m + 2, 1);
    while(n--){
        int z, o, t;
        cin >> z >> o >> t;

        for (int i = z; i < z + o; i++){
            arrs[i]++;
        }
        for (int i = z + o; i < 2*m -1; i++){
            arrs[i] += 2;
        }
    }

    for (int i = 0; i < m; i++){
        for (int j = 0; j < m; j++){
            if (j == 0){
                cout << arrs[m - i - 1] << ' ';
            } else{
                cout << arrs[m + j - 1] << ' ';
            }
        }
        cout << '\n';
    }
    
    
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}