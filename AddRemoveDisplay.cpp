#include<stdio.h>
#include<stdlib.h>

void Adding(int *arry,int number, int top){
	
	arry[top+1] = number;
	
}

void Removing(int *arry,int number,int top){
	for(int i=0;i<=top;i++){
		if(arry[i] == number){
            for(int a=i;a<top;a++){
            	arry[i]=arry[i+1];
			}
		}
	}
}

void Display(int *arry,int top){
	for(int i = 0;i<=top;i++){
		printf("%d. element is %d\n",i+1,arry[i]);
	}
}

int main(){
	
	
	int islem;
	int arry[10];
	int top = -1;
	int count;
	int number;
	do{
		printf("1-Adding\n");
		printf("2-Removing\n");
		printf("3-Display\n");
		printf("4-Quit\n");
		scanf("%d",&islem);
		
		switch(islem){
			
			case 1:
				if(top >= 10){
					printf("The array is full.\n");
				}
				else{
					printf("How many numbers are you gonna enter :");
					scanf("%d",&count);
					for(int i=0;i<count;i++){
						printf("%d. number that you wanna enter :",i+1);
						scanf("%d",&number);
					    Adding(arry,number,top);
						top++;		
					}
				}
				break;
			case 2:
				if(top<0){
					printf("There aren't enough elements to remove");
				}
				else{
					printf("How many numbers are you gonna remove :");
					scanf("%d",&count);
					for(int i=0;i<count;i++){
						printf("%d. number that you wanna remove :",i+1);
						scanf("%d",&number);
					    Removing(arry,number,top);
						top--;		
					}
				}
				break;
			case 3:
				if(top<0){
					printf("There aren't enough elements to display");
				}
				else{
					Display(arry,top);
				}
				break;
			case 4:
				break;
		}
	
	
	
	
	
	}while(islem !=4);
	

	return 0;
}
