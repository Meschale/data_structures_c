#include<stdio.h>
#include<stdlib.h>
#define N 200

int Arr[N];
int last = 0;
int first = 0;

void enqueue(int item){
	if(last >= N){
		printf("Stack is full");
	}
	else{
		Arr[last] = item;
		last++;
	}
}

int dequeue(){
    int temp;
	if(last==first){
    	printf("No element to push");
    	return -1;
	}
    else{
    	temp = first;
    	first++;
    	return Arr[temp];
	}	
}

void show(){
	for(int i=first;i<last;i++){
		printf("%d ",Arr[i]);
	}
}
int main(){
	int number;
    printf("Enter number :");
	scanf("%d",&number);
	enqueue(number);
	printf("\n");
	printf("Enter number :");
	scanf("%d",&number);
	printf("\n");
	enqueue(number);
	printf("Enter number :");
	scanf("%d",&number);
	enqueue(number);
	printf("\n");	
	show();
	printf("Deleted :%d\n",dequeue());
	printf("Deleted :%d\n",dequeue());
	show();
	return 0;
}
