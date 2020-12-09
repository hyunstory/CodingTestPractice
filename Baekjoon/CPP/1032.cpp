#include <iostream>
#include <string>

using namespace std;


void solution(){

    int n;
    cin >> n;
 
    string result;
    string line;
    
    cin >> line;

    result = line;

    for (int i = 1; i < n; i++){
        string temp;
        cin >> temp;

        for (int j = 0; j < line.length(); j++){
            if (line[j] != temp[j]){
                result[j] = '?';
            }
        }
    }

    cout << result << '\n';
}
int main(){

    solution();


    return 0;
}