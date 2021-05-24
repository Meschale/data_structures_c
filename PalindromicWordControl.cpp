#include<stdlib.h>
#include<stdio.h>
#include<string.h>

char STACK[5];
int sp = 0;
void push(char item){
	STACK[sp] = item;
	sp++;
}
char pop(){
	return STACK[--sp];
}

char Queue[5];
int spQ = 0;
int q = 0;

void enqueue(char item){
	Queue[spQ] = item;
	spQ++;
}
char dequeue(){
	return Queue[q++];
}
bool PalWithoutQueue(char word[]){
	int len = strlen(word);
	int l = 0;
	int r = (len-1);
	
	while(r>l){
		if(word[l++] != word[r--]){
		    return false;
		}
	}
	return true;
}
bool PalWithQueueAndStack(char word[]){
	int len = strlen(word);
	char c;
	
	for(int i=0;i<len;i++){
		c = word[i];
		enqueue(c);
		push(c);
	}
	
	while( q < ((len/2) + 1) ){
    	if(dequeue() != pop()){
    		return false;
		}
	}
	return true;
}
int main(){
	
	char word[] = "saas";
	bool result;
	result = PalWithoutQueue(word);
    result == true ? printf("%s is a palindromic word\n",word) : printf("%s is not a palindromic word\n",word);	
	
    result = PalWithQueueAndStack(word);
    printf("%d",result);
	return 0;
}
