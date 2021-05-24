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

void DFT();
void TraverseGraph(int node);

int main(){
	DFT();
	return 0;
}

void DFT(){
    for(int i=0;i<6;i++){
    	if(visited[i] == 0){
    		TraverseGraph(i);
		}
	}
}

void TraverseGraph(int node){
	visited[node] = 1;//because of calling this, you will be visiting.Then you say 'I visited this.'
    printf("%d\n",node);
    for(int i=0;i<6;i++){
    	if((G[node][i] == 1) && visited[i] == 0){
    		TraverseGraph(i);
		}
	}
}
