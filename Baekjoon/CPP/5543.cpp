#include <stdio.h>

#include <string.h>



int main(){

	

	int burger1, burger2, burger3, coke, cider, i, cb = 0, cB;

	

	scanf("%d %d %d %d %d", &burger1, &burger2, &burger3, &coke, &cider);

	

	if(burger1 < burger2 && burger1 < burger3){

		

		cb = burger1;

	}

	

	else if (burger2 < burger1 && burger2 < burger3){

		

		cb = burger2;

	}

	

	else {

		

		cb = burger3;

	}

	

	if(coke < cider){

		

		cB = coke;

	}

	

	else {

		

		cB = cider;

	}

	

	printf("%d", cb + cB - 50);

}