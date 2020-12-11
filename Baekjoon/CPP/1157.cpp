#include <iostream>
#include <string>
#include <cctype>
#include <vector>


using namespace std;

vector<int> v('Z' + 1, 0);

void solution(){

    string a;

    cin >> a;

    if (a.length() == 1){
        cout << (char) toupper(a[0]) << '\n';
        exit(0);
    }


    for (int i = 0; i < a.length(); i++){

       v[toupper(a[i])]++;

    }


    int max = 1;
    char answer;
    bool same = false;
    for (int i = 'A'; i <= 'Z'; i++){
        
        if (max < v[i]){
            answer = i;
            max = v[i];
        }

    }
    int count = 1;

    for (int i = 'A'; i <= 'Z'; i++){
        if (v[i] == max){
            if (count >= 2){
                cout << '?' << '\n';
                exit(0);
            }
            count++;

        }
    }

    char ans = (char) answer;

    cout << ans << '\n';
    
    


}
int main(){

    solution();

    return 0;
}