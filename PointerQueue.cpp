#include<stdio.h>
#include<stdlib.h>

typedef struct A{
    int item;
	struct A *next; 	
}B;

B *first=NULL, *last=NULL;

int enqueue(int item){
	
	A *p;
    p = (A*)malloc(sizeof(A));
	if(p == NULL){
		printf("Memory couldnt be taken..");
	}
	p->item = item;
	p->next = NULL;	
	if(first == NULL){
		first = p;
		last = p;
	}
	else{
		last->next = p;
		last = last->next;
	}
	printf("Added :%d\n",item);
}

void dequeue(){
   if(first == NULL){
   	    printf("No element to return..");
   }
   else{
   	    A *p;
   	    int item;
   	    p = first;
   	    first = first->next;
   	    if(first==NULL)
   	        last = NULL;
   	    item = p->item;
   	    free(p);
   	    printf("Dequeued :%d\n",item);
   }
}

void show(){
	A *q;
	q = first;
    while(q){
    	printf(".%d. \n",q->item);
    	q = q->next;
	}
}

void reset(){
	A *p;
	p = first;
	while(p){
	    first = first->next;
		free(p);
		p = first;	
	}
	last = NULL;
}
int main(){
    enqueue(1);
    enqueue(21);
    enqueue(9);
    show();
    dequeue();
    enqueue(54);
    show();
    dequeue();
    enqueue(4);
    show();
    reset();
	return 0;
}
