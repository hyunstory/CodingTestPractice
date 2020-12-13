#include <iostream>

using namespace std;


int T;
int M, N;

int gcd(int x, int y) {
    if (y == 0){
        return x;
    }
    else return gcd(y, x%y);
}

int lcm(int x, int y){
    return x * y /gcd(x, y);
}




void solution(){
    cin >> T;
    while(T--){
        int M, N, x, y;
        
        int result = -1;
        
        cin >> M >> N >> x >> y;
        
        int max = lcm(M, N);
        
        for (int i = 0; x + i * M <= max; i++){
            int cnt_y = ( x + i * M) - N * (int) (( x + i * M) / N);
            if ((y == cnt_y) || ((N == y) && (cnt_y == 0))){
                result = x + i*M; break;
            }
        }
        
        cout << result << '\n';
    }
    
}


int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();
    
    
    return 0;
}
