#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct List{
	int id;
	char *name;
    struct List *next;
}Linking;

Linking *first = NULL,*last = NULL;

void insertion(Linking *node){
	if(first != NULL ){
		last->next = node;
		node->next = NULL;
		last = node;
		printf("Successful\n");
		}
	else{
		first = node;
		last = node;
		node->next = NULL;
		printf("Successful\n");
	
	}
}

void searching(int key){
	Linking *temp;
	temp = first;
    
    if(temp == NULL)
	    printf("There are no elements in the list to search!\n");
	    
    while(temp != NULL){
        if(temp->id == key){
        	printf("Student's name is :%s\n",temp->name);
        	break;
		}
		temp = temp->next;
	}
}

void deleting(int key){
	
	Linking *temp,*prev;
	temp = first;
	while(temp){
		if(key == temp->id){
			break;
		}
		prev = temp;
		temp = temp->next;
	}
	if(temp != NULL){
        if(temp == last){ //last element
		    last = prev;
	     	last->next = NULL;
		    free(prev);
		    printf("Successful\n");
	    }
	    else if(first == last){   //one element
		    first == NULL;
		    last == NULL;
		    printf("Successful\n");
	    }
	    else{ //middle element
		    prev->next = temp->next;
		    printf("Successful\n");
	    }
	}
	else
	    printf("The list doesnt include any elements like that!\n");
}

void display(){
	Linking *temp;
	temp = first;
	if(temp == NULL){
		printf("There are no elements to show!\n");
	}
	while(temp){
		printf("Id-%d , Name-%s\n",temp->id,temp->name);
		temp = temp->next;
	}
	
}

int main(){
	
    Linking *p,*t,*r,*k,*r1;
	p = (Linking *)malloc(sizeof(Linking));
    t = (Linking *)malloc(sizeof(Linking));
	k = (Linking *)malloc(sizeof(Linking));
	r = (Linking *)malloc(sizeof(Linking));
	r1 = (Linking *)malloc(sizeof(Linking));
	r1->id = 5;			
	p->id = 1;
	t->id = 2;
	k->id = 3;
	r->id = 4;
	p->name = "PErcan";
	t->name = "TErcan";
	k->name = "KErcan";
	r->name = "RErcan";
	r1->name = "R1Ercan";
	display();
	insertion(p);
	insertion(t);
	insertion(k);
	insertion(r);
	display();
	searching(3);
	display();
	deleting(2);
	display;
	insertion(r1);
	display();
	insertion(t);
	display();
	return 0;
}
