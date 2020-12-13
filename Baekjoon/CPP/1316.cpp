#include <iostream>
#include <map>

using namespace std;

map<char, int> table;

void solution(){

    int n;
    string ss;

    int result = 0;

    cin >> n;

    while(n--){
        cin >> ss;

        bool grp = true;
        char concent = '#';

        for (int i = 0; i < ss.length(); i++){
            

            if (table.find(ss[i]) == table.end()){
                concent = ss[i];
                table[ss[i]] = 1;
                
            }
            else if (concent == ss[i]){
                continue;
            }
            else{
                grp = false;
            }
        }

        if (grp) result++;
        

        ss.clear();
        table.clear();
    }

    cout << result << '\n';
}
int main(){

    solution();

    return 0;
}