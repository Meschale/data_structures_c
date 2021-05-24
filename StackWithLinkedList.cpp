#include<stdlib.h>
#include<stdio.h>

typedef struct s{
    int item;
    struct s* next;
}STACK;

STACK* sp = NULL;

int push(int item);
int pop();
void reset();
int top();
int size();

int main(){
	
	int control = 1;
	int choice;
	int result;
	int item;
	do{
		printf("1-Push\n");
		printf("2-Pop\n");
		printf("3-Reset\n");
		printf("4-Top\n");
		printf("5-Size\n");
		printf("Seciminizi giriniz :");
		scanf("%d",&choice);
		switch(choice){		
			case 1:
				printf("\n");
				printf("Eklemek istediginiz item :");
				scanf("%d",&item);
				printf("\n");
				push(item);
				break;
			case 2:
				result = pop();
				result == -1 ?  : printf("Cikarilan item :%d.\n",result);
				break;
			case 3:
				reset();
				printf("Resetleme islemi basarili..\n");
				break;
			case 4:
				result = top();
				result == NULL ? printf("Ýslem basarisiz..\n") : printf("En üstteki item :%d.\n",result);
				top();
				break;
			case 5:
				printf("\n");
				result = size();
				result == 0 ? printf("Hic item yok.\n") : printf("%d adet item var.\n",result);
				break;
			default:
				printf("Hatali tuslama...\n");
		}
	}while(control == 1);
	
	
	return 0;
}

int push(int item){
    STACK* p;
	p = (STACK*)malloc(sizeof(STACK));
	
	if(p==NULL){
		printf("Memory allocation error.\n");
	    return -1;
	}	
	else{
		p->item = item;
		p->next = sp;
		sp = p;
		return 0;
	}
}
int pop(){
	STACK* p;
	p = (STACK*)malloc(sizeof(STACK));
	int i;
	if(sp==NULL){
		printf("Stack is empty!");
		return -1;
	}
	else{
		p = sp;
		sp = sp->next;
		i = p->item;
		free(p);
		return i;
	}
}
void reset(){
	STACK* p;
	p = (STACK*)malloc(sizeof(STACK));
	while(sp){
		p = sp;
		sp = sp->next;
		free(p);
	}
}
int top(){
	return sp->item;
}
int size(){
    STACK* p;
    p = (STACK*)malloc(sizeof(STACK));
    int count = 0;
    p = sp;
	while(p){
    	p= p->next;
    	count++;
	}
	return count;
}
