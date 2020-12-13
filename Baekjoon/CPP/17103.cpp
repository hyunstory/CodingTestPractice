
#include <iostream>
#include <cmath>

using namespace std;

#define MAX 1000000 + 1
//#define MAX 1000 + 1

int T, N, result;

int input[MAX];
int not_prime[MAX];

int cur_num;
void calculate_prime(){
    
    // 초기화
    not_prime[0] = true;
    not_prime[1] = true;
    
    int square_root = (int) sqrt(MAX);
    
    for (int i = 2; i <= square_root; i++){
        
        int index = i;
        if (not_prime[index]) continue;
        
        while(index <= MAX - 1){
            index += i;
            if (index > MAX - 1) break;
            
            not_prime[index] = true;
        }
    }
    
}

void solution(){
    
    cin >> T;
    
    for (int i = 0; i < T; i++){
        cin >> input[i];
    }
    
    calculate_prime();
    
    for (int i = 0; i < T; i++){
       
        
        int case_T = input[i];
        
        result = 0;
        
        int half_T = case_T / 2;
        
        for (int j = 2; j <= half_T; j++){
            
            if( !not_prime[j] && !not_prime[case_T - j]) result ++;
            
  
        }
        
        
        cout << result << '\n';
    }
    
}

int main() {

    
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout.tie(0);

    
    solution();
    
    return 0;
}
