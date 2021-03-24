#include <iostream>
#include <vector>

using namespace std;

const int MAX = 100001;
int n, m, k;

int ind[MAX];
vector<int> topo[MAX];
int con[MAX];


void exit_sig(){
    cout << "Lier!" << '\n';
    exit(0);
}
void solution(){

    cin >> n >> m >> k;

    for (int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;

        topo[a].push_back(b);
        ind[b]++;
    }
    for (int i = 0; i < k; i++){

        int cmd, num;
        cin >> cmd >> num;

        if (cmd == 1){

            if(ind[num] > 0) exit_sig();
            else{
                con[num]++;
                if (con[num] > 1) continue;

                for (int i = 0; i < topo[num].size(); i++){
                    int next = topo[num][i];
                    --ind[next];
                }
            }
            

        } else if (cmd == 2){
            if (con[num] == 0){
                exit_sig();
            } else {
                con[num]--;
                if (con[num] == 0){
                    for (int i = 0; i < topo[num].size(); i++){
                        int next = topo[num][i];
                        ind[next]++;
                    }
                }
            }
        }

    }

    cout << "King-God-Emperor" << '\n';


}

int main(){

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    solution();

    return 0;
    
}