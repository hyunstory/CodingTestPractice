#include <iostream>

using namespace std;

long long factorial(int n){
    if (n == 1 || n == 0){
        return 1;
    }
    return n * factorial(n - 1);
}
void solution(){
    int n;
    cin >> n;
    
    long long result = factorial(n);
    
    cout << result << '\n';
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();
    
    return 0;
}