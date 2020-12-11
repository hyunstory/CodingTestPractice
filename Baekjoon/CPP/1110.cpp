#include <iostream>

using namespace std;


void solution(){

    int n;

    cin >> n;

    int answer = n;
    int result = 0;

    while(1){

        int sum;

        int back = n % 10;
        n /= 10;
        int front = n % 10;

        sum = back + front;

        int next = back * 10 + (sum % 10);



        result++;

        if (next == answer)break;

        n = next;
    }

    cout << result << '\n';
}
int main(){


    solution();

    return 0;
}