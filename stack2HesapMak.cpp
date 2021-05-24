#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define N 20 // Globaldeki dizinin boyutu

char text[N];//girilecek yazi(Bu uygulama icin hesap makinesine uygun seyler girilecek e.g. 16+12)
int sp=0;//stack pointerýmýz , text icin
int sayi[N];//girilen sayýlarý ve operasyolarý burdaki stackte tutacagýz
int sp1=0;//sayi dizisinin stack pointerý
void push(char c){
    if(sp==N){//stackte yer var mý diye kontrol islemi
    	printf("Stack is full!");
	}
    else{
    	text[sp] = c;
    	sp++;
	}
}

void pop(){
    int temp = sp;//stack pointerý kaybetmemek icin
    int sayac = 0;//sayý text ve bunu int yaparken textin basamagýna göre carpacagýz, 2.basamak iste 10^1 ile carpmak icin lazým olacak
    int toplam = 0;//textteki karakterlerin donusmus halini int olarak tutacagýz, operatorler de dahil
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
		}//asagýda operasyon kontrol var, eger textte operator var ise bunu sayi stackine -1(toplama),-2 (cýkarma),-3 (carpma),-4(bolme)
		if(text[(temp - 1)] == '+'){
			sayi[sp1] = toplam;//sayi bitti demektir ve sayýyý stacteki ust kýsma atarýz, en alt da olabilir lakin top dedigimiz kýsýma atýlacak
			sp1++;//stackte top'u arttýrýyoruz
			toplam = 0;//toplamý tekrar kullanabilmek icin sýfýrladýk
			sayac = -1;//if elselerin dýsýnda sayac artacak, 0 istedigimiz icin -1 verdik
			sayi[sp1] = -1;//Toplama operatorünün sembolü(bu program icin)
			sp1++;//top'u arttýrýyoruz, bir sonraki dongude diger sayi ya da operator gelecek
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
		temp--;//stackte geri geri 0 a kadar gidiyoruz
	}
    sayi[sp1] = toplam;//en son dongude atama dýsarýda kalýyor..
}
void operation(){
	int res=0;//Nihai sonucumuz
	int temp,temp1 = sp1;//yine islem yapacagýmýz icin tempi kullandýk(amac sp1i kaybetmemek)
	
	while(temp > 0){
		if(sayi[temp] == -3){//carpma islem onceligini kontrol ettiriyoruz var ise onu yapýyor
			sayi[temp-1] = sayi[temp+1]*sayi[temp-1];
			for(int i=temp;i<temp1-1;i++){
				sayi[i] = sayi[i+2];
			}
			temp1=(temp1-2);
		}
		if(sayi[temp] == -4){//bolme islem onceligini kontrol ettiriyoruz var ise onu yapýyor
			sayi[temp-1] = sayi[temp+1]/sayi[temp-1];
			for(int i=temp;i<temp1-1;i++){
				sayi[i] = sayi[i+2];
			}
			temp1=(temp1-2);
		}
		temp--;
	}
	
	sp1 = temp1;//islem sonrasi stackte top degisiyor(temp1 üzerinde degýsýklýk yaptýk ki sonradan atayabilelim)
	//top da temp1de tutuldugu icin (yukardaki whiledan dolayý)temp1i sp1e atadýk.
	while(sp1 != 0){//Islem onceliklerinden sonraki toplama ve cýkarma islemlerimiz..
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
		printf("The result is :%d",sayi[0]);//sonuc coktan cýkmýssa, yani toplama ve cýkarma islemi yok ise burda basýyoruz
	}
	else
	printf("The result is :%d",res);
}
int error(){

    for(int i=0;i<sp1;i++){//char kontrol
    	if(text[i] != '1' || text[i] != '2' || text[i] != '3' || text[i] != '4' ||  text[i] != '5' || text[i] != '6' || text[i] != '7' || text[i] != '8' ||  text[i] != '9' ||  text[i] != '0' ||  text[i] != '+' ||  text[i] != '-' ||  text[i] != '/' ||  text[i] != '*' ||  text[i] != 32) 
	    {
	    	return 0;
		}
		else
		    return 1;
	}
}
int main(){
    
    char c;
    
    while((c = getchar()) != '\n')//textimizi burda alýyoruz
        push(c);//burda stacke gonderiyoruz
    
    if(error() == 0){//hatali tuslama yoksa
    	pop();//islem operatorlerini secip sayýyý ters oldugu icin duzeltiyoruz
        operation();//sayi stackindeki islemleri yapacak fonksiyonumuz
	}
	else
	{//hata varsa
		printf("Please just enter integer numbers and (+,-,/,*) operators");
	}

return 0;
}
