#include <iostream>
#include <string>
#include <cstring>
#include <deque>

using namespace std;

#define MAX 11 + 1

int n;
int k;
char a[MAX];
int selected[MAX];
int max_arr[MAX];
int min_arr[MAX];
bool check[MAX];

long long max_value = 0;
long long min_value = 9999999999;


deque<char> dq;
deque<char> backup;

void print(){
    //max
    for (int i = 0; i < k; i++){
        
        cout << max_arr[i];
    }
    cout << '\n';
    
    //min
    for (int i = 0; i < k; i++){
        cout << min_arr[i];
    }
    cout << '\n';
}
void required_init(){
    
    for (int i = 0; i < 10; i++){
        a[i] = i;
    }
}

void validate(){
    
    bool flag = true;
    
    for (int i = 0; i < n; i++){
        
        char temp = dq[i];
        
        if ((temp == '<') && selected[i] > selected[i + 1]) flag = false;

        else if( (temp == '>') && selected[i] < selected[i + 1]) flag = false;
        
    }
    
    if (flag){
        
        string temp_str = "";
        for (int i = 0; i < k; i++){
            temp_str.append(to_string(selected[i]));
        }
        
        long long temp_val = atoll(temp_str.c_str());
        
        
        if (min_value > temp_val){
            min_value = temp_val;
            memcpy(min_arr, selected, sizeof(selected));
        }
        
        if (max_value < temp_val){
            max_value = temp_val;
            memcpy(max_arr, selected, sizeof(selected));
        }

    }
    
    
    
    
    
    
}

void go(int depth) {

    if (depth == k) {
        
        //검증
        validate();

        
        dq.assign(backup.begin(), backup.end());
        return;
    }

    for (int i = 0; i < 10; i++) {

        if (check[i]) continue;

        selected[depth] = a[i];
        check[i] = true;
        go(depth + 1);
        check[i] = false;

    }
}

void solution() {

    required_init();
    
    cin >> n;
    
    k = n + 1;

    char temp;
    
    for (int i = 0; i < n; i++) {
        cin >> temp;
        dq.push_back(temp);
    }

    backup.assign(dq.begin(), dq.end());
    
    go(0);
    
    print();

}
int main() {


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("Input.txt", "r", stdin);

    solution();


    return 0;
}
