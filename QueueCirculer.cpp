#include<stdio.h>
#include<stdlib.h>
#define N 19

int Arr[N];
int last = 0;
int first = 0;
int count = 0;

void enqueue(int item){
	if(count >= N){
		printf("Queue is full");
	}
	else{
		Arr[last] = item;
		last = (last+1) % N;
		count++;
	}
}

int dequeue(){
    int temp;
	if(count == 0){
    	printf("No element to push");
    	return -1;
	}
    else{
    	temp = first;
    	first = (first + 1) % N;
    	count--;
    	return Arr[temp];
	}	
}

void reset(){
	count = 0;
	first = 0;
	last = 0;
}
void show(){
	for(int i=first;i<last;i++){
		printf("%d ",Arr[i]);
	}
	printf("\n");
}
int main(){

	enqueue(7);
	enqueue(5);
	enqueue(1);
	show();
	printf("Deleted :%d\n",dequeue());
	show();
	printf("Deleted :%d\n",dequeue());
	show();
	return 0;
}
