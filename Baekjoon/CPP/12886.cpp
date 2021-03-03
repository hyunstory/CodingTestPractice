#include <iostream>
#include <queue>
#include <tuple>

using namespace std;
const int MAX = 1600;

bool check[MAX][MAX];

int bfs(int i, int j, int k){

    queue < tuple < int, int, int> > q;

    q.push(make_tuple(i, j, k));

    int ok = 0;
    while(!q.empty()){

        int a = get<0>(q.front());
        int b = get<1>(q.front());
        int c = get<2>(q.front());
        q.pop();

        if ((a + b + c) % 3 != 0){
            return 0;
        }

        if (a == b && b == c){
            return 1;
        }

        
        // a b선택
        if ( a > b){

            int x = b + b;
            int y = a - b;


            if (!check[a][b] && !check[b][a]){
                q.push(make_tuple(y, x, c));
                check[a][b] = true;
                check[b][a] = true;
            }
            
            
        } else if ( a < b){
            int x = a + a;
            int y = b - a;

            

            if (!check[a][b] && !check[b][a]){
                q.push(make_tuple(x, y, c));
                check[a][b] = true;
                check[b][a] = true;
            }
            
        }

        // b c선택
        if ( b > c){

            int x = c + c;
            int y = b - c;


            if (!check[b][c] && !check[c][b]){
                q.push(make_tuple(a, y, x));
                check[b][c] = true;
                check[c][b] = true;
            }
            

        } else if ( b < c){
            int x = b + b;
            int y = c - b;

            

            if (!check[b][c] && !check[c][b]){
                q.push(make_tuple(a, x, y));
                check[b][c] = true;
                check[c][b] = true;
            }
            
        }

        // a c선택
        if ( a > c){
            int x = c + c;
            int y = a - c;

            

            if (!check[a][c] && !check[c][a]){
                q.push(make_tuple(y, b, x));
                check[a][c] = true;
                check[c][a] = true;
            }
            

        } else if ( a < c){
            int x = a + a;
            int y = c - a;

            

            if (!check[a][c] && !check[c][a]){
                q.push(make_tuple(x, b, y));
                check[a][c] = true;
                check[c][a] = true;
            }
            
        }
        

    }


    return ok;
}
void solution(){

    int a, b, c;

    cin >> a >> b >> c;

    cout << bfs(a, b, c) << '\n';

}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
}