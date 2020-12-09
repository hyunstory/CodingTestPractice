#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;


void solution(){
    int x, y, w, h;

    cin >> x >> y >> w >> h;

    int wd1 = abs(x - w);
    int wd2  = abs(0 - x);
    int wd = min(wd1, wd2);

    int hd1 = abs(y - h);
    int hd2 = abs(0 - y);
    int hd = min(hd1, hd2);
    
    int minV = min(wd, hd);

    cout << minV << '\n';

}
int main(){


    solution();


    return 0;
}