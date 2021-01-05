#include <iostream>

using namespace std;


int number[10];

void init(){

    number[0] = 4;
    number[1] = 2;

    for (int i = 2; i <= 9; i++){
        number[i] = 3;
    }
}

void solution(){

    init();

    while(true){
        int sum = 0;

        sum += 1;

        int a;

        cin >> a;

        if (a == 0){
            break;
        }

        while(a != 0){

            sum += number[a % 10];
            sum += 1;

            a /= 10;
        }

        cout << sum << '\n';
    
    }


}
int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();


    return 0;
}