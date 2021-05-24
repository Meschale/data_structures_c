#include<stdio.h>
#include<stdlib.h>

typedef struct ogr{
	int id;
	int grade;
    struct ogr* next;
    struct ogr* prev;
}ogr;

ogr *first = NULL,*last = NULL;

void ekleme(struct ogr* p);
int cikarma(int id);
int arama(int id);
void listeleme();
int aramaTers(int id);
void listelemeTers();

int main(){
	
	int choice;
	int control = 1;
	int id;
	int result;
	struct ogr* p;
	do{
		printf("1-Ekleme\n");
		printf("2-Cikarma\n");
		printf("3-Arama\n");
		printf("4-Listeleme\n");
		printf("4-Arama(Tersten)\n");
		printf("6-Listeleme(Tersten)\n");
		printf("7-Cikis\n");
		printf("Seciminizi giriniz :");
		scanf("%d",&choice);
		switch(choice){		
			case 1:
				p = (ogr*)malloc(sizeof(ogr));
				printf("Eklemek istediginiz ogrencinin numarasi :");
				scanf("%d",&p->id);
				printf("Eklemek istediginiz ogrencinin notu :");
				scanf("%d",&p->grade);
				printf("\n");
				ekleme(p);
				break;
			case 2:
				printf("\n");
				printf("Cikartmak istediginiz ogrencinin numarasi :");
				scanf("%d",&id);
				result = cikarma(id);
				result == -1 ? printf("Yeterli eleman yok veya id hatali.\n") : printf("Cikarma islemi basarili.\n");
				break;
			case 3:
				printf("\n");
				printf("Aramak istediginiz ogrencinin numarasi :");
				scanf("%d",&id);
				result = arama(id);
				result == -1 ? printf("Yeterli eleman yok veya id hatali.\n") : printf("Aradiginiz id'li ogrencinin notu :%d.\n",result);
				break;
			case 4:
				listeleme();
				break;
			case 5:
				printf("\n");
				printf("Aramak(Tersten) istediginiz ogrencinin numarasi :");
				scanf("%d",&id);
				result = aramaTers(id);
				result == -1 ? printf("Yeterli eleman yok veya id hatali.\n") : printf("Aradiginiz id'li ogrencinin notu :%d.\n",result);
				break;
			case 6:
				listelemeTers();
				break;
			case 7:
			    control = 0;
				break;
			default:
				printf("Hatali tuslama...\n");
		}
	}while(control == 1);
	return 0;
}
void ekleme(struct ogr* p){
	if(first == NULL){
		first = p;
		last = p;
		p->next = NULL;
		p->prev = NULL;
	}
	else{
		p->prev = last;
		last->next = p;
		last = p;
		last->next = NULL;
	}
};
int cikarma(int id){
	ogr* temp;
	temp = first;
	if(first == NULL)
	   return -1;
	while(temp){
    	if(id == temp->id){  
    	    if(temp == first && temp->next != NULL){//ilk eleman ama listede 1 den cok eleman
		    	first = first->next;
		    	first->prev = NULL;
		    	free(temp);
		    	return 1;
			}
			else if(temp == first && temp->next == NULL){//ilk eleman ve listede 1 eleman
		    	first = NULL;
		    	last = NULL;
		    	free(temp);
		    	return 1;
			}
		    else if(temp->next == NULL){//son eleman
		    	last = last->prev;
				last->next = NULL;
		    	free(temp);
		    	return 1;
			}
			else{//ortadan
			    temp->prev->next = temp->next;
			    temp->next->prev = temp->prev;
				free(temp);
				return 1;
			}
		}
    	temp = temp->next;
	}
	return -1;
};
int arama(int id){
	ogr* temp;
	temp = first;
	if(temp == NULL)
	   return -1;
	while(temp){
    	if(id == temp->id){  
    	    return temp->grade;
		}
    	temp = temp->next;
	}
	return -1;
};
void listeleme(){
	ogr* temp;
    temp = first;
	while(temp){
    	printf("\n%d numarali ogrencinin notu = %d\n",temp->id,temp->grade);
    	temp = temp->next;
	}
};
int aramaTers(int id){
	ogr* temp;
	temp = last;
	if(temp == NULL)
	   return -1;
	while(temp){
    	if(id == temp->id){  
    	    return temp->grade;
		}
    	temp = temp->prev;
	}
	return -1;
};
void listelemeTers(){
	ogr* temp;
    temp = last;
	while(temp){
    	printf("\n%d numarali ogrencinin notu = %d\n",temp->id,temp->grade);
    	temp = temp->prev;
	}
};

