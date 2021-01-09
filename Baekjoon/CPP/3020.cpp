#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

int n, h;

const int MAX = 200001;
const int INF = __INT_MAX__;






void solution(){

    cin >> n >> h;


    vector<int> bottom(n/2), top(n/2);
    for (int i = 0; i < n/2; i++){

        cin >> bottom[i] >> top[i];
        
    }

    sort(bottom.begin(), bottom.end());
    sort(top.begin(), top.end());

    int result = INF;

    int cnt = 1;

    for (int i = 1; i <= h; i++){ 

        int temp = bottom.size() - (lower_bound(bottom.begin(), bottom.end(), i) - bottom.begin()); // 바닥에 있는 값은 해 당 위치의 값 바로 밑에있는것까지 카운트해서 전체에서 빼고

        temp += top.size() - (upper_bound(top.begin(), top.end(), h - i) - top.begin()); // 탑은 그 위치에 있는 값까지 포함하여 전체에서 뺀다. 

        if (result == temp) cnt++;

        else if(result > temp){ // 더 작은 것을 찾았을 땐, 작은 값을 result로 놓고, cnt = 1로 다시 바꿔줌. 
            result = temp;
            cnt = 1;
        }

    }

    cout << result << ' ' << cnt << '\n';




}

int main(){


    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();

    return 0;
}