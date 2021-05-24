#include<stdio.h>
#include<stdlib.h>

void MergeSort(int *arry,int length);
void Merge(int *arry,int *L,int *R,int length);

int main(){
	
	int arry[7] = {5,6,8,4,2,3,1};
	int i=0;	
	
	MergeSort(arry,7);
	
	
    for(i=0;i<7;i++){
    	printf("%d ",arry[i]);
	}
	 
	return 0;
}

void MergeSort(int *arry,int length){  
     
    int mid = 0;
    int i=0;
    int *L,*R;
    mid = length/2;
    
    if(length < 2){
    	return;
	}
	
	else {
		L = (int*)malloc(sizeof(int)*mid);
	    R = (int*)malloc(sizeof(int)*(length-mid));
	    
	    for(i=0;i<mid;i++){
	    	L[i] = arry[i];
		}
		
		for(i=mid;i<length;i++){
			R[i-mid] = arry[i];
		}
		
		MergeSort(L,mid);
		MergeSort(R,length-mid);
		Merge(arry,L,R,length);
	}

}

void Merge(int *arry,int *L,int *R,int length){

    int i = 0,j = 0,k = 0;
	
	int mL,mR;
	
	mL=length/2;
	mR=length-mL;
	
	while(i<mL && j<mR){
		if(L[i] < R[j]){
			arry[k] = L[i];
			i++;
		}
		else{
			arry[k] = R[j];
			j++;		  
		}
		  k++;
	} 
	while(i<mL){
		arry[k] = L[i];
		i++;
		k++;
	}
	while(j<mR){
		arry[k] = R[j];
		j++;
	    k++;
	}
	
}
