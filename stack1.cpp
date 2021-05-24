#include<stdio.h>
#include<stdlib.h>
#define N 20

char text[N];
int sp=0;


void push(char c){
    if(sp==N){
    	printf("Stack is full!");
	}
    else{
    	text[sp] = c;
    	sp++;
	}
}

char pop(){
    return text[(sp-1)];
}

int main(){
    
    char c;
    
    while((c = getchar()) != '\n')
        push(c);
    

	  
    while(sp>0){
    	printf("%c",pop());
    	sp--;
	}
        


return 0;
}
