#include <iostream>
#include <cstring>

using namespace std;

#define MAX 50 + 1
int N;

char a[MAX][MAX];
char bu[MAX][MAX];


int fx[] = {0, 1};
int fy[] = {1, 0};

int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};


int result;



void solution(){
    
    cin >> N;
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            cin >> a[i][j];
        }
    
    memcpy(bu, a, sizeof(a));
    
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++){
            
            
            
            for (int k = 0; k < 2; k++){
                int nx = i + fx[k];
                int ny = j + fy[k];
                
                if (!(nx >= 0 && nx < N && ny >= 0 && ny < N) || a[i][j] == a[nx][ny]) continue;
                
                
                //바꾸기
                int temp = a[i][j];
                a[i][j] = a[nx][ny];
                a[nx][ny] = temp;
                    
                
                
                for (int ab = 0; ab < N; ab++)
                    for (int bc = 0; bc < N; bc++){
               
                        int x = ab;
                        int y = bc;
                
                    for (int p = 0; p < 2; p++){
                        int sum = 1;
                        
                        
                        while(1){
                            int nextX = x + fx[p];
                            int nextY = y + fy[p];
                            
                            if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && a[ab][bc] == a[nextX][nextY]) {
                                sum++;
                                
                            }
       
                            else break;
                            
                            
                            x = nextX;
                            y = nextY;
                            
                        
                        }
                        
                        result = max(result, sum);
                        
                    }
                    
                   
                }
                    
                
                
                
                memcpy(a, bu, sizeof(bu));
                
            }
            
            
            
            
            
        }
    if (result != 0){
    cout << result << '\n';
    }
    else cout << N << '\n';
}

int main(){
    
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    solution();
    
    
    return 0;
}
