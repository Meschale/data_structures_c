#include<stdio.h>
#include<stdlib.h>

void Insert(int *ptr,int number,int top,int position){
	if(position == 0){
		int temp = ptr[0];
	    ptr[0] = number;
		for(int i=1;i<=(top+1);i++){
			int temp1 = ptr[i];
			ptr[i] = temp; 
			temp = temp1;
		}	
	}
	else if(position == (top+1)){
	    ptr[top+1] = number;	
	}
	else{
		for(int i=position;i<=(top+1);i++){
		    int temp = ptr[position];
			ptr[i] = number;
			number = temp; 		
		}
	}
}

void Delete(int *ptr,int element,int top){
	for(int i=(element-1);i<top+1;i++){
		ptr[i]=ptr[i+1];
	}
	//ptr[top] = null;
	ptr = (int*)realloc(ptr,sizeof(int)*(top+1));
}

void Display(int *ptr,int top){

    for(int i=0;i<=top;i++){
    	printf("%d. element is %d\n",i+1,ptr[i]);
	}
}

void Sort(int *ptr,int size){
	for(int i=1;i<(size-1);i++){
		int temp = ptr[i];
		for(int a=i-1;a>=0;a--){
			if(temp < ptr[a]){
				ptr[a+1] = ptr[a];
				ptr[a] = temp;
			}
		}
	}
}

void Reverse(int *ptr,int size){
    for(int i=1;i<(size-1);i++){
		int temp = ptr[i];
		for(int a=i-1;a>=0;a--){
			if(temp > ptr[a]){
				ptr[a+1] = ptr[a];
				ptr[a] = temp;
			}
		}
	}
}

int main(){
	
	
	int islem;
	int top = -1;
	int size=1;
	int *ptr = (int*)malloc(sizeof(int)*size);
	int count;
	int number;
	int choice;
	int order;
	do{
		printf("1-Insert\n");
		printf("2-Delete\n");
		printf("3-Display\n");
		printf("4-Sort\n");
		printf("5-Reverse\n");
		printf("6-Quit\n");
		scanf("%d",&islem);
		
		switch(islem){
			
			case 1:
			    printf("How many elements are you gonna enter :");
			    scanf("%d",&count);
			    size += count;
			    ptr = (int*)realloc(ptr,sizeof(int)*size);
				for(int i=0;i<count;i++){
					printf("1-I am gonna choose where it will be put in\n");
					printf("2-Put it in the last order\n");
					printf("3-Put it in the first order\n");
					scanf("%d",&choice);
					if(choice == 1){
					printf("%d. element that you wanna insert :",i+1);
					scanf("%d",&number);
					printf("%d. element will be inserted after which element :");
					scanf("%d",&order);
					Insert(ptr,number,top,order);
					top++;	
					}
					else if(choice == 2){
						printf("%d. element that you wanna insert :",i+1);
					    scanf("%d",&number);
					    order = (top+1);
						Insert(ptr,number,top,order);
					    top++;
					}
					else if(choice == 3){
						printf("%d. element that you wanna insert :",i+1);
					    scanf("%d",&number);
					    order = 0;
						Insert(ptr,number,top,order);
					    top++;
					}
					else{
						printf("There is no choise like that.");
						i--;
					}
				}
				break;
			case 2:
				if(top<0){
			    	printf("There aren'nt enough elements to delete\n");
		    	}
				else{
					printf("How many elements are you gonna delete :");
			        scanf("%d",&count);
			        Display(ptr,top);
			        for(int i=0;i<count;i++){
			        	printf("Which elemet that you wanna delete :",i+1);
					    scanf("%d",&number);
					    Delete(ptr,number,top);
					    top--;
					    size--;
					}
				}
				break;
			case 3:
			    if(top<0){
			    	printf("There is nothing to display\n");
				}
				else{
					Display(ptr,top);
				}
				break;
			case 4:
	              Sort(ptr,size);
				  Display(ptr,top);
				break;
			case 5:
	              Reverse(ptr,size);
				  Display(ptr,top);
				break;
			case 6:
				
				break;
            default:
            	islem = 6;
		}
	
	}while(islem !=6 );
	

	return 0;
}
