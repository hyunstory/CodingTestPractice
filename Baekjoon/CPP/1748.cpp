#include <iostream>
#include <cstring>
#include <string>
#include <cmath>

using namespace std;


long long result;
int n;

void find_count(int size){
    
    //long long sum = 9;
    long long sum = 0;
    
    for (int i = 1; i < size; i++){
        
        sum += (pow(10, i) - pow(10, i-1)) * i;
    }
    
    //int mod = n % (int) ( pow (10, ( size - 1)));
    
    sum += size * (n - (pow(10, size -1) -1));
    
    result = sum;
    
    
    
}

void solution(){
    
   
    
    cin >> n;
    
    string str1 = to_string(n);
    int count = (int) str1.length();
    
   
    
    
    if (count == 1){
        result = n;
    }
    
    else {
        find_count(count);
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
