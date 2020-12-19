#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> six;
vector<int> one;


void solution(){

    int n, m;

    int result = __INT_MAX__;

    cin >> n >> m;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        six.push_back(a);
        one.push_back(b);
    }

    sort(six.begin(), six.end());
    sort(one.begin(), one.end());

    if (n > 6){
        
        int temp1 = __INT_MAX__;

        for (int i = 0; i <= (n/6)+1; i++){
            temp1 = min(temp1, six[0]*i + one[0]*max(n-6*i, 0));
        }


        result = min(result, temp1);


    }

    else if ( n <= 6){
        result = min(six[0], n*one[0]);
        

    }



    cout << result << '\n';
}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}