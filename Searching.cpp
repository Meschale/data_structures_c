#include<stdio.h>
#include<string.h>
#include<stdlib.h>


struct STUDENT{
	
	char name[10];
	char surname [10];
	int id;
	
};

int searching(STUDENT **students,int length,int key){
	int left = 0;
	int right = (length -1);
	int mid;
	
    while(left <= right){
    	mid = (left+right)/2;
    	if(key == students[mid]->id){
    		return mid;
		}
		else if(key > students[mid]->id){
		    left = mid + 1; 
		}
	    else{
		    right = mid - 1;
		}
	}
	return -1;
/*	for(int i=0;i<length;i++){
		/*if(temp[i]->name == "Ercan"){
			printf("a");
		}
		//O(n) arama
		if(strcmp(temp[i]->name,"Ercan")== 0)
		printf("a");
	}*/
}

int main(){
	
	STUDENT *students[5];
	*students = (STUDENT*)malloc(sizeof(STUDENT));
	for(int i=0;i<5;i++){
		students[i] = (STUDENT*)malloc(sizeof(STUDENT));
	}
	//students = (STUDENT*)malloc(sizeof(STUDENT));
	
	strcpy(students[0]->name,"Ercan");
	//students[0]->name = "Ercan";
	strcpy(students[0]->surname ,"Dalmis");
	//students[0]->id = "2016555025";
	//strcpy(students[0]->id ,"2016555025");
	students[0]->id = 1;
	
	strcpy(students[1]->name,"Ercan1");
	//students[0]->name = "Ercan";
	strcpy(students[1]->surname ,"Dalmis");
	//students[0]->id = "2016555025";
	//strcpy(students[1]->id ,"2016555025");
	students[1]->id = 1;
	
	strcpy(students[2]->name,"Ercan2");
	//students[0]->name = "Ercan";
	strcpy(students[2]->surname ,"Dalmis");
	//students[0]->id = "2016555025";
	//strcpy(students[2]->id ,"2016555025");
	students[2]->id = 3;
	
	strcpy(students[3]->name,"Ercan3");
	//students[0]->name = "Ercan";
	strcpy(students[3]->surname ,"Dalmis");
	//students[0]->id = "2016555025";
	//strcpy(students[3]->id ,"2016555025");
	students[3]->id = 4;
	
	strcpy(students[4]->name,"Ercan");
	//students[0]->name = "Ercan";
	strcpy(students[4]->surname ,"Dalmis");
	//students[0]->id = "2016555025";
    //strcpy(students[4]->id ,"2016555025");
    students[4]->id = 5;
	
	printf("::: %d",searching(students,5,5));
	
	return 0;
}
