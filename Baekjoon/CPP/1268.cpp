#include <iostream>
using namespace std;

int main() {


  int arr[1001][6];
  int cnt[1001];
  
  int n;
  cin >> n;
 

  for(int i = 1; i <= n; i++){
      cnt[i] = 0;
  }

  for(int i = 1; i <= n; i++){
    for(int j = 1; j <= 5; j++){
      int num;
      cin >> num;
      
      arr[i][j] = num;
    }
  }
  

  for(int i = 1; i <= n; i++){ 
    for(int j = 1; j <= n; j++){ 
      for(int k = 1; k <= 5; k++){ 
        if(arr[i][k] == arr[j][k]){
          cnt[i]++;
          break;
        }
      }
    }
  }
  
  int max = 0;
  int max_student = 0;
  for(int i = 1; i<= n; i++){
    if(cnt[i] > max){
      max = cnt[i];
      max_student = i;
    }

    else if(cnt[i] == max){
      if(max_student > i){
        max_student = i;
      }
    }
  }

  cout << max_student << endl;
  return 0;
}