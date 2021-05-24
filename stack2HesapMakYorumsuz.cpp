#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 30 

char text[N];
int sp=0;
int sayi[N];
int sp1=0;
void push(char c){
    if(sp==N){
    	printf("Stack is full!");
	}
    else{
    	text[sp] = c;
    	sp++;
	}
}

void pop(){
    int temp = sp;
    int sayac = 0;
    int toplam = 0;
    while(temp>0){
    	if(text[(temp - 1)] != '+' && text[(temp - 1)] != '-' && text[(temp - 1)] != '/' && text[(temp - 1)] != '*'){
    		if(text[(temp - 1)] == 32){
    			temp--;
    			sayac = 0;
    			continue;
			}
			if(text[(temp - 1)] == '1'){
    			toplam += 1*pow(10,sayac);
			}
			else if(text[(temp - 1)] == '2'){
			    toplam += 2*pow(10,sayac);
			}
			else if(text[(temp - 1)] == '3'){
			    toplam += 3*pow(10,sayac);
			}
			else if(text[(temp - 1)] == '4'){
    			toplam += 4*pow(10,sayac);
			}
			else if(text[(temp - 1)] == '5'){
			    toplam += 5*pow(10,sayac);
			}
			else if(text[(temp - 1)] == '6'){
			    toplam += 6*pow(10,sayac);
			}
			else if(text[(temp - 1)] == '7'){
    			toplam += 7*pow(10,sayac);
			}
			else if(text[(temp - 1)] == '8'){
			    toplam += 8*pow(10,sayac);
			}
			else if(text[(temp - 1)] == '9'){
			    toplam += 9*pow(10,sayac);
			}
		}
		if(text[(temp - 1)] == '+'){
			sayi[sp1] = toplam;
			sp1++;
			toplam = 0;
			sayac = -1;
			sayi[sp1] = -1;
			sp1++;
		}
		else if(text[(temp - 1)] == '-'){
			sayi[sp1] = toplam;
			sp1++;
			toplam = 0;
			sayac = -1;
			sayi[sp1] = -2;
			sp1++;
		}
		else if(text[(temp - 1)] == '*'){
			sayi[sp1] = toplam;
			sp1++;
			toplam = 0;
			sayac = -1;
			sayi[sp1] = -3;
			sp1++;
		}
		else if(text[(temp - 1)] == '/'){
			sayi[sp1] = toplam;
			sp1++;
			toplam = 0;
			sayac = -1;
			sayi[sp1] = -4;
			sp1++;
		}
		sayac++;
		temp--;
	}
    sayi[sp1] = toplam;
}
void operation(){
	int res=0;
	int temp,temp1 = sp1;
	
	while(temp > 0){
		if(sayi[temp] == -3){
			sayi[temp-1] = sayi[temp+1]*sayi[temp-1];
			for(int i=temp;i<temp1-1;i++){
				sayi[i] = sayi[i+2];
			}
			temp1=(temp1-2);
		}
		if(sayi[temp] == -4){
			sayi[temp-1] = sayi[temp+1]/sayi[temp-1];
			for(int i=temp;i<temp1-1;i++){
				sayi[i] = sayi[i+2];
			}
			temp1=(temp1-2);
		}
		temp--;
	}
	
	sp1 = temp1;

	while(sp1 != 0){
		if(sayi[sp1-1] == -3){
		    res = sayi[(sp1)]*sayi[(sp1-2)];
		    sayi[sp1-2] = res;
		    sp1 = sp1-2;
		}
		else if(sayi[sp1-1] == -4){
		    res = sayi[(sp1)]/sayi[(sp1-2)];
		    sayi[sp1-2] = res;
		    sp1 = sp1-2;
		}
		else if(sayi[sp1-1] == -1){
		    res = sayi[(sp1)]+sayi[(sp1-2)];
		    sayi[sp1-2] = res;
		    sp1 = sp1-2;
		}
		else if(sayi[sp1-1] == -2){
		    res = sayi[(sp1)]-sayi[(sp1-2)];
		    sayi[sp1-2] = res;
		    sp1 = sp1-2;
		}
	}
	if(temp1 == 0){
		printf("The result is :%d",sayi[0]);
	}
	else
	printf("The result is :%d",res);
}
int error(){

    for(int i=0;i<sp1;i++){
    	if(text[i] != '1' || text[i] != '2' || text[i] != '3' || text[i] != '4' ||  text[i] != '5' || text[i] != '6' || text[i] != '7' || text[i] != '8' ||  text[i] != '9' ||  text[i] != '0' ||  text[i] != '+' ||  text[i] != '-' ||  text[i] != '/' ||  text[i] != '*' ||  text[i] != 32) 
	    {
	    	return 0;
		}
		else
		    return 1;
	}
}
int main(){
    
    //for example 16     +23, is gonna print 39.... 18*2+3 is gonna print 39
    
    char c;
    
    while((c = getchar()) != '\n')
        push(c);
    
    if(error() == 0){
    	pop();
        operation();
	}
	else
	{
		printf("Please just enter integer numbers and (+,-,/,*) operators");
	}

return 0;
}
