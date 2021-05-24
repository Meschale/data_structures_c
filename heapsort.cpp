#include<stdio.h>
#include<stdlib.h>

int left(int i);
int right(int i);
void build_heap(int arry[],int n);
void heapify(int arry[],int i);
void heapsort(int arry[],int n);
void show(int arry[], int size);
int heap_size;

int main(){
	
	int arry[] = {5,10,7,8,1,14,21,29,3};
	
	int n = sizeof(arry)/sizeof(arry[0]);
	
	heapsort(arry,n);
	show(arry,n);
	return 0;
}


void heapsort(int arry[],int n){
    int i,temp;
	build_heap(arry,n);	 
	  
    for (i = n-1; i >= 1; i--){
   // exchange the root with the ith element
      temp = arry[i];
      arry[i] = arry[0];
      arry[0] = temp;
      heap_size--;
      heapify(arry,0);
   }

 	
}

void build_heap(int arry[],int n){
	int i;
	heap_size=(n-1);
	
	for(i=(n-1)/2;i>=0;i--){
		heapify(arry,i);
	}
}

void heapify(int arry[],int i){
	int left_child,right_child,max,temp;
	
	left_child = left(i);
	right_child = right(i);
	
	if ((left_child <= heap_size) &&
       (arry[left_child] > arry[i]))
      max = left_child;
   else
      max = i;
    if ((right_child <= heap_size) &&
       (arry[right_child] > arry[max]))
         max = right_child;
         
	if(max != i){
		temp = arry[max];
        arry[max]= arry[i];
        arry[i] = temp;
        heapify(arry, max);
	}
}

int left(int i){
    return (2*i+1);	
}

int right(int i){
    return (2*i+2);	
}

void show(int arry[],int size){
	for(int i=0;i<size;i++){
		printf("%d ",arry[i]);
	}
}
