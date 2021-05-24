#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include <conio.h>
#include <time.h>


int main(){
	
	srand(time(NULL)); 
	int result,guess = -1;
	result = rand()%1000;
	printf("-Welcome to GUESS GAME!!\n");
	printf("I kept a number from 0 to 1000, what is your guess?\n");
	
	
	while(result != guess){
		scanf("%d",&guess);
	    if(guess < 0 || guess > 1000 ){
		    printf("Owww.You have entered a number that is not in range!\n");
		    continue;
	    }
		if(guess < result){
			printf("Please enter a number that is HIGHER than it!\n");
		}
		else if(guess > result){
			printf("Please enter a number that is LOWER than it!\n");
		}
	}
	printf("CORRECT!\n Do you wanna play again(y/n)");
	
}
