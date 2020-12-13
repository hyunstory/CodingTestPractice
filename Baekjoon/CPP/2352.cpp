#include <cstdio>
#define MAX 40000

int main(){
	int n;
	scanf("%d", &n);
	int len = 0;
	static int a[MAX], min[MAX];
	for(int i = 0; i < n; ++i){
		scanf("%d", &a[i]);
		int low = 1, high = len;
		while(low <= high){
			int mid = (low + high + 1) / 2;
			if(a[min[mid]] < a[i]){
				low = mid + 1;
			}else{
				high = mid - 1;
			}
		}
		int new_len = low;
		min[new_len] = i;
		if(new_len > len){
			len = new_len;
		}
	}
	printf("%d", len);
	return 0;
}