#include<stdio.h>

void quicksort(int ptr[],int left,int right){
	
	int k,j,temp,q;
	
	k = left;
	j = right;
	q = ptr[(left+right)/2];
	
	do{
		while(k < right){
			if(ptr[k] < q){
				k++;
			}
			else
			break;
		}
		while(j > left){
			if(ptr[j] > q){
				j--;
			}
			else
			break;
		}
		/*while((ptr[k] < q) && (k < right))
		    k++;*/
		/*while((ptr[j] > q) && (j > left))
		    j--;*/
		if(k<=j){
			temp = ptr[k];
			ptr[k] = ptr[j];
			ptr[j] = temp;
			k++; j--;
		}
	}while(k<=j);
	
	if(left < j)
	    quicksort(ptr,left,j);
	if(k < right)
	    quicksort(ptr,k,right);
}


int main(){
	
	int arry[] = {5,3,8,12,92,78,65,21,1};
	
	quicksort(arry,0,8);
	for(int i=0;i<9;i++){
		printf("%d ",arry[i]);
	}
	return 0;
}
