#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

#define MAX 1024

typedef struct Polinom {
    int koeficijent;
    int eksponent;
    struct Polinom* next;
} Polinom;

typedef Polinom* PolinomPozicija;

int unos(PolinomPozicija, PolinomPozicija);
int novielement(PolinomPozicija, int, int);
int ispis(PolinomPozicija);
int zbrajanje(PolinomPozicija,PolinomPozicija,PolinomPozicija);
int mnozenje(PolinomPozicija, PolinomPozicija, PolinomPozicija);


int main() {
   
    Polinom prvi;
    Polinom drugi;
    Polinom zbroj;
    Polinom umnozak;

    prvi.next = NULL;
    drugi.next = NULL;
    zbroj.next = NULL;
    umnozak.next = NULL;

    unos(&prvi, &drugi);
    ispis(prvi.next);
    printf("\n");
    ispis(drugi.next);
    printf("\n");
    zbrajanje(prvi.next, drugi.next, &zbroj);
    ispis(zbroj.next);
    printf("\n");
    mnozenje(prvi.next, drugi.next, &umnozak);
    ispis(umnozak.next);
    return 0;
}

int unos(PolinomPozicija glavni1, PolinomPozicija glavni2) {

    FILE* file = NULL;
    char buffer[MAX];
    int buffercount=0;
    int bufferdod = 0;
    int koficijent, potencija;

   file= fopen("polinomi.txt", "r");
   if (file == NULL) {
       printf("grška pri ucitavanju datoteke");
       return -1;
   }

   fgets(buffer, MAX, file);

   while (sscanf(buffer + bufferdod, "%dx^%d%n", &koficijent, &potencija, &buffercount)==2) {

       novielement(glavni1, koficijent, potencija);
       bufferdod += buffercount;

   }

   fgets(buffer, MAX, file);
   bufferdod = 0;

   while (sscanf(buffer + bufferdod, " %dx^%d%n", &koficijent, &potencija, &buffercount) == 2) {

       novielement(glavni2, koficijent, potencija);
       bufferdod += buffercount;

   }

   fclose(file);
   return 1;

}

int novielement(PolinomPozicija glavni, int koeficijent, int potencija){

    PolinomPozicija novi = NULL;
    PolinomPozicija temp;
   
   
    
    while(glavni->next!=NULL && glavni->next->eksponent>potencija){
        
        glavni = glavni->next;
    }

    if (glavni->next == NULL) {

        novi = (PolinomPozicija)malloc(sizeof(Polinom));
        novi->eksponent = potencija;
        novi->koeficijent = koeficijent;

        novi->next = glavni->next;
        glavni->next = novi;
        return 1;
    }
    else if (glavni->next->eksponent == potencija) {
       
        glavni->next->koeficijent += koeficijent;
        if (glavni->next->koeficijent !=0) {
            temp = glavni->next;
          glavni->next = glavni->next->next;
            free(temp);
            return 1;
        }
        return 1;
    }
    else {
        novi = (PolinomPozicija)malloc(sizeof(Polinom));
        novi->eksponent = potencija;
        novi->koeficijent = koeficijent;

        novi->next = glavni->next;
        glavni->next = novi;
        return 1;
    }
    return -1;
}

int ispis(PolinomPozicija glavni) {

    while (glavni != NULL) {
        if (glavni->koeficijent > 0) {
            printf("+%dx^%d", glavni->koeficijent, glavni->eksponent);
        }
        else {
            printf("%dx^%d", glavni->koeficijent, glavni->eksponent);
        }
        glavni = glavni->next;
    }
    return 0;
}

int zbrajanje(PolinomPozicija prvi, PolinomPozicija drugi, PolinomPozicija zbroj) {
    
    int koef=0;

    while (prvi != NULL && drugi != NULL) {
        
        if (prvi->eksponent == drugi->eksponent) {
            koef = prvi->koeficijent + drugi->koeficijent;
            if (koef != 0) {
                novielement(zbroj, koef, prvi->eksponent);
                
            }
            prvi = prvi->next;
            drugi = drugi->next;
        }
        else if (prvi->eksponent > drugi->eksponent) {
            novielement(zbroj, prvi->koeficijent, prvi->eksponent);
            prvi = prvi->next;
        }
        else {
            novielement(zbroj, drugi->koeficijent, drugi->eksponent);
            drugi = drugi->next;
        }
    }

    if (prvi != NULL) {
        while (prvi != NULL) {
            novielement(zbroj, prvi->koeficijent, prvi->eksponent);
            prvi = prvi->next;
        }
    }
    if (drugi != NULL) {
        while(drugi!=NULL){
            novielement(zbroj, drugi->koeficijent, drugi->eksponent);
            drugi = drugi->next;
        }
    
    }

}

int mnozenje(PolinomPozicija prvi, PolinomPozicija drugi, PolinomPozicija mnozenje) {

    PolinomPozicija pocetak1 = prvi;
    PolinomPozicija pocetak2 = drugi;

    while (prvi != NULL) {
        while (drugi != NULL) {

            novielement(mnozenje, prvi->koeficijent * drugi->koeficijent, prvi->eksponent + drugi->eksponent);
            drugi = drugi->next;
        }
        drugi = pocetak2;
        prvi = prvi->next;
    }
    return 1;
}