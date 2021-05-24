#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sorting(char **names,int length){
	char *temp;
	int a,i;
    int sayac = 0;
	//ic ice dong� kulland�m, �nce ilk harflerini siralatt�m e�er ayn�ysa di�er harflere bakt�rd�m ona g�re s�ralatt�m
	//ASCII tablosunda alfabetik s�raya g�re s�ral� A-Z 65-91 kucuk harfler de a-z 97-123
	for(i=0;i<length;i++){
		for(a=i+1;a<length;a++){
			//burda ilk harfi kucukse i. elemana at dedim kucukten buyuge s�ralad�m
	        if(int(names[a][0]) < int(names[i][0])){
	       	    temp = names[i];
				names[i] = names[a];
				names[a] = temp;
			}//burda e�er ayn�ysa bu sefer i�indekilere bak dedim mesela ercan ersan e ve r den sonra s ve c yi kar��la�t�r�p s�ralamas� i�in
			else if(int(names[a][0]) == int(names[i][0])){
				while((strlen(names[a]) >= sayac) && (strlen(names[i]) >= sayac) ){
            	    if(int(names[i][sayac]) > int(names[a][sayac])){
    		            temp = names[i];
				        names[i] = names[a];
				        names[a] = temp;
    		            break;
		            }
		            sayac++;
	            }
	            sayac = 0;
			}
		}
	}
}

int main(){
	//isimleri belirledim
	char *names[] =  {"Devrim","Ercan","Ali","Mercan","Sercan","Ersan","Tezcan","Ahmet"};
    int n = sizeof(names)/sizeof(names[0]);//dizinin boyutunu ald�m

    sorting(names,n);//fonksiyona g�nderdim
	for(int i=0;i<n;i++)//print ettim
	    printf("%s ",names[i]);
	return 0;
}

  
