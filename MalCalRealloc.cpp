#include<stdio.h>
#include<stdlib.h>


int main(){
	
	
	int *ptr;
	
	ptr = (int*)malloc(10*sizeof(int));
	
	for(int i=0;i<10;i++){
		ptr[i] = i;
	}
	
	for(int i=0;i<10;i++){	
		printf("%d ",ptr[i]);
	}
	printf("\n");
	ptr = (int*)realloc(ptr,sizeof(int)*20);
	
	
	for(int i=0;i<20;i++){
		ptr[i] = i;
	}
	
	for(int i=0;i<20;i++){	
		printf("%d ",ptr[i]);
	}
	
	
	
	
	
	return 0;
}
