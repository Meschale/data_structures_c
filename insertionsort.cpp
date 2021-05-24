// C program for insertion sort 
#include <stdio.h> 
#include <math.h> 

/* Function to sort an array using insertion sort*/
void insertionSort(int arr[], int n);
void insertionsort(int arry[],int n);
// A utility function to print an array of size n 
void printArray(int arr[], int n);

int main()
{
	int arr[] = { 12, 11, 13, 5, 6 };
	int n = sizeof(arr) / sizeof(arr[0]);
    
    insertionsort(arr, n);
	//insertionSort(arr, n);
	printArray(arr, n);

	return 0;
}

void printArray(int arr[], int n)
{
	int i;
	for (i = 0; i < n; i++)
		printf("%d ", arr[i]);
	printf("\n");
}

void insertionSort(int arr[], int n)
{
	int i, key, j;
	for (i = 1; i < n; i++)
	{
		key = arr[i];
		j = i - 1;

		/* Move elements of arr[0..i-1], that are greater than key, to one position ahead of their current position */
		while (j >= 0 && arr[j] > key)
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = key;
	}
	/*
	int i, k, key;
   for (i = 1; i < n; i++)
   { 
      key = D[i];
      
      for (k = i-1; k>=0 && key <= D[k]; k--)
         D[k+1] = D[k];   // shift operation
      D[k+1] = key;  // insert key
   }

	*/
}
void insertionsort(int arry[],int n){
	int temp;
	for(int i=1;i<n;i++){
		for(int a=i-1;a>=0;a--){
			if(arry[a]>arry[a+1]){
			    temp = arry[a];
			    arry[a] = arry[a+1];
			    arry[a+1] = temp;
			}
			else
			break;
		}
	}
	
}
