#include <iostream>
#include <string>
#include <cmath>

using namespace std;

void solution(){
    string a;

    cin >> a;

    int a_size = a.size();

    long long result = 0;
    int exp = 0;
    long long mul = 1;

    for (int i = a_size - 1; i >= 0; i--){


        int value = 0;
        if (a[i] >= 'A' && a[i] <= 'Z') value = (a[i] - 'A') + 10;

        else value = a[i] - '0';

        result += value * mul;

        mul *= 16;
        
    }

    cout << result << '\n';

}
int main(){



    solution();

    return 0;
}