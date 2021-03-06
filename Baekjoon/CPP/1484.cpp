#include <iostream>

using namespace std;

const int MAX = 100001;

void solution(){

    int G;

    cin >> G;

    bool no = true;

    int j = 1;

    int left = 1;
    int right = 1;

    while(left <= right && right < G){

        int sum = left + right;
        int subtract = right - left;
        int res = sum*subtract;

        if( res == G){
            cout << right << '\n';
            no = false;
            right++;
        } else if (res < G){
            right++;
        } else{
            left ++;
        }

        
        
    }

    if (no) cout << -1 << '\n';

}
int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}