#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void sorting(char **names,int length){
	char *temp;
	int a,i;
    int sayac = 0;
	//ic ice dongü kullandým, önce ilk harflerini siralattým eðer aynýysa diðer harflere baktýrdým ona göre sýralattým
	//ASCII tablosunda alfabetik sýraya göre sýralý A-Z 65-91 kucuk harfler de a-z 97-123
	for(i=0;i<length;i++){
		for(a=i+1;a<length;a++){
			//burda ilk harfi kucukse i. elemana at dedim kucukten buyuge sýraladým
	        if(int(names[a][0]) < int(names[i][0])){
	       	    temp = names[i];
				names[i] = names[a];
				names[a] = temp;
			}//burda eðer aynýysa bu sefer içindekilere bak dedim mesela ercan ersan e ve r den sonra s ve c yi karþýlaþtýrýp sýralamasý için
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
    int n = sizeof(names)/sizeof(names[0]);//dizinin boyutunu aldým

    sorting(names,n);//fonksiyona gönderdim
	for(int i=0;i<n;i++)//print ettim
	    printf("%s ",names[i]);
	return 0;
}

  
