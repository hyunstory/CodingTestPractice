
#include <iostream>
#include <cmath>

using namespace std;
#define MAX 1000000 + 1

int DP[MAX];

// 0은  3나누기
// 1은  2나누기
// 2는 1 빼기


int N, result;

int start(int n){
    
    if (n == 1){
        return 0;
    }
    
    if (DP[n] > 0){
        return DP[n];
    }
    
    
    DP[n] = start(n-1) + 1;
    
    if (n % 3 == 0){
        int Q = start(n / 3) + 1;
        if (DP[n] > Q){
            DP[n] = Q;
        }
    }
    
    if (n%2 == 0){
        int Q = start(n / 2) + 1;
        if (DP[n] > Q){
            DP[n] = Q;
        }
    }
    
    
    

    
    return DP[n];
    
}


void solution(){
    
    cin >> N;
    

    int result = start(N);
        
        
        
    
    
    cout << result << '\n';
    
}

int main() {

    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    
    solution();
    
    return 0;
}
