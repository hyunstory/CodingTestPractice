
#include <iostream>
#include <string>

using namespace std;

void solution(){

    

    while(1){

        string a;

        int front = 0;
        int back = 0;

        bool pal = true;

        cin >> a;

        if (a == "0") exit(0);

        back = a.length() - 1;

        while (front < back){
            if (a[front] != a[back]){
                cout << "no" << '\n';
                pal = false;
                break;
            }
            front++;
            back--;

        }
        


        if (pal) cout << "yes" << '\n';
    }
    
}
int main(){


    solution();

    return 0;
}