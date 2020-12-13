#include <iostream>
#include <cmath>

using namespace std;

int n;
long long result;
void solution(){
    
    cin >> n;
    
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        
        result += abs(temp);
    }
    
    for (int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        
        result += abs(temp);
    }
    
    cout << result << '\n';
}
int main(){
    
    solution();
    
    return 0;
    
}