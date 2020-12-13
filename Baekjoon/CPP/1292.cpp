#include <iostream>

using namespace std;

void solution(){

    int a, b;

    cin >> a >> b;

    int result;
    int cnt = 0;

    for (int i = 1; i <= 46; i++){
        for (int j = 1; j <= i; j++){
            cnt++;

            if (cnt >= a && cnt <= b){
                result += i;
            }
            if (cnt == b) break;
        }
        if (cnt == b) break;

    }    


    cout << result << '\n';
    
}
int main(){

    solution();

    return 0;
}