#include<stdlib.h>
#include<stdio.h>

int G[6][6] = {
    {0,1,1,0,0,1},
    {1,0,1,1,1,0},
    {1,1,0,0,1,0},
    {0,1,0,0,1,0},
    {0,1,1,1,0,1},
	{1,0,0,0,1,0},
};

int visited[6] = {0,0,0,0,0,0};
int first = 0, last = 0, count = 0;
int Q[6];
void BFT();
void enqueue(int item);
int dequeue();
void calling();
bool isEmptyQueue();
int main(){
	calling();
	return 0;
}
void calling(){
    for(int i=0;i<6;i++){
    	if(visited[i] == 0){
    		enqueue(i);
    		BFT();
		}
	}
}
void BFT(){
	int n;
	while(isEmptyQueue()){
		n = dequeue();
		if(visited[n] == 1)
		    continue;
		visited[n] = 1;
		printf("%d\n",n);
		for(int i=0;i<6;i++){
			if((G[n][i] == 1) && (visited[i] == 0)){
				enqueue(i);
			}
		}
	}
}
void enqueue(int item){
	Q[last] = item;
	count++;
	last = (last + 1) % 6;
}
int dequeue(){
	int temp;
	temp = first;
	count--;
	first = (first + 1) % 6;
	return Q[temp];
}
bool isEmptyQueue(){
    if(count == 0){
    	return false;
	}	
    return true;
}
