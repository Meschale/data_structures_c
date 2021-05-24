#include<stdio.h>


int main(){
	
    unsigned long long int num=2;
	int sayac=0;
	
	while(num<1000000000){
		
	    unsigned long long int temp = num;
	    int digit_count = 0;
	    int sum = 0;
	    unsigned long long int result = 1;
	    int sum1;
	    while(temp>0){
	    	sum = sum + (temp % 10);
	    	temp = temp / 10;
	    	digit_count++;
		}
		sum1 = sum;
		for(int i = 0;i<30;i++){//30 because 2^30 goes over 1 billion
			if(result > num)
			    break;
			result = result * sum;
			
			if(result == num){
				sayac++;
	    	    printf("%d-) %d = (",sayac,num);
	    	    while(result > 0){
	    	    	if(result / 10 > 0){
	    	    		printf("%d + ",(result%10));
					}
					else if(result / 10 <= 0){
						printf("%d)",(result%10));
					}
	    	    	result = result / 10;
				}
				printf("Sum1 = %d",sum1);
				printf("^%d\n",(i+1));
				break;
		    }
		} 
		num++;
	}	
	return 0;
}
