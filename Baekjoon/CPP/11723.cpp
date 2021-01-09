#include <iostream>
#include <set>
#include <string>

using namespace std;

set<int> s;


void cmd(string a, int b){
    
        if(a == "add") s.insert(b);


        else if (a == "remove") s.erase(b);


        else if( a == "check") cout << (s.find(b) != s.end()) << '\n';


        else if( a == "toggle"){
            if (s.find(b) != s.end()){
                s.erase(b);
            }else{s.insert(b);}
        }

        else if( a == "all"){
            for (int i = 1; i <= 20; i++) s.insert(i);
        }

        else if( a == "empty"){
            s.clear();
        }
        

    
}
void solution(){
    int n;

    cin >> n;

    for (int i = 0; i < n; i++){
        string a;
        int b;
        cin >> a;

        if(a == "all" || a == "empty") b = 0;
        else cin >> b;

        cmd(a, b);
    }
    
}
int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}