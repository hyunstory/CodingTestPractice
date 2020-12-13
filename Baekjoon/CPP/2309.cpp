#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>

using namespace std;

#define short_max 9
#define short_reg 7


bool FLAG_didfinish;
int short_person[short_max];
int selected_person[short_reg];


bool compare(int a, int b) {
    return a < b;
}
void cal_sum(){
    int sum = 0;
    for (int i = 0; i < short_reg; i++){
        sum += selected_person[i];
        
    }
    
    if (sum == 100){
        
        sort(selected_person, selected_person + short_reg, compare);
    
    
        if(!FLAG_didfinish){
        
            for (int i = 0; i < short_reg; i++){
              
                cout << selected_person[i] << '\n';
            }
            
            FLAG_didfinish = true;
        }
    }
    
}

void go(int start, int depth){
    
    if (depth == short_reg){
        
        cal_sum();
        
        return;
    }
    
    
    
    for (int i = start; i < short_max; i++){
        
        selected_person[depth] = short_person[i];
        go(i + 1, depth + 1);
    }
}

void solution(){
    
    
    for (int i = 0; i < short_max; i++){
        cin>> short_person[i];
    }
    
    
    go(0, 0);
    
    
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();
    
    
    return 0;
}
