#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<string.h>


typedef struct Polinom {
    int koeficijent;
    int eksponent;
    struct Polinom* next;
} Polinom;

typedef Polinom* PolinomPozicija;


void dodajClan(PolinomPozicija p, int koeficijent, int eksponent) {
    PolinomPozicija novi = (PolinomPozicija)malloc(sizeof(Polinom));
    if (novi == NULL) {
        printf("Greška pri alociranju memorije.\n");
        exit(1);
    }

    novi->koeficijent = koeficijent;
    novi->eksponent = eksponent;
    novi->next = p->next;
    p->next = novi;
}


PolinomPozicija zbrojiPolinome(PolinomPozicija p1, PolinomPozicija p2) {
    Polinom rezultat;
    PolinomPozicija temp = &rezultat;
    temp->next = NULL;

    while (p1->next != NULL && p2->next != NULL) {
        if (p1->next->eksponent > p2->next->eksponent) {
            dodajClan(temp, p1->next->koeficijent, p1->next->eksponent);
            p1 = p1->next;
        }
        else if (p1->next->eksponent < p2->next->eksponent) {
            dodajClan(temp, p2->next->koeficijent, p2->next->eksponent);
            p2 = p2->next;
        }
        else {
            dodajClan(temp, p1->next->koeficijent + p2->next->koeficijent, p1->next->eksponent);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1->next != NULL) {
        dodajClan(temp, p1->next->koeficijent, p1->next->eksponent);
        p1 = p1->next;
    }

    while (p2->next != NULL) {
        dodajClan(temp, p2->next->koeficijent, p2->next->eksponent);
        p2 = p2->next;
    }

    return rezultat.next;
}


PolinomPozicija pomnoziPolinome(PolinomPozicija p1, PolinomPozicija p2) {
    Polinom rezultat;
    PolinomPozicija temp = &rezultat;
    temp->next = NULL;

    PolinomPozicija temp1 = p1->next;
    while (temp1 != NULL) {
        PolinomPozicija temp2 = p2->next;
        while (temp2 != NULL) {
            int koeficijent = temp1->koeficijent * temp2->koeficijent;
            int eksponent = temp1->eksponent + temp2->eksponent;
            dodajClan(temp, koeficijent, eksponent);
            temp2 = temp2->next;
        }
        temp1 = temp1->next;
    }

    return rezultat.next;
}


void ispisiPolinom(PolinomPozicija p) {
    while (p->next != NULL) {
        p = p->next;
        printf("%dx^%d ", p->koeficijent, p->eksponent);
        if (p->next != NULL) {
            printf("+ ");
        }
    }
    printf("\n");
}



int main() {
    Polinom polinom1, polinom2;
    PolinomPozicija p1 = &polinom1;
    PolinomPozicija p2 = &polinom2;
    p1->next = NULL;
    p2->next = NULL;
    int koeficijent, eksponent;

    
    FILE* datoteka = fopen("polinomi.txt", "r");
    if (datoteka == NULL) {
        printf("Greška pri otvaranju datoteke.\n");
        return 1;
    }


    while (fscanf(datoteka, "%d %d", &koeficijent, &eksponent) == 2) {
        dodajClan(p1, koeficijent, eksponent);
    }

    while (fscanf(datoteka, "%d %d", &koeficijent, &eksponent) == 2) {
        dodajClan(p2, koeficijent, eksponent);
    }

    fclose(datoteka);

    
    PolinomPozicija rezultatZbroj = zbrojiPolinome(p1, p2);
    PolinomPozicija rezultatUmnozak = pomnoziPolinome(p1, p2);

    printf("Polinom 1: ");
    ispisiPolinom(p1);

    printf("Polinom 2: ");
    ispisiPolinom(p2);

    printf("Zbroj polinoma: ");
    ispisiPolinom(rezultatZbroj);

    printf("Umnožak polinoma: ");
    ispisiPolinom(rezultatUmnozak);

  

    return 0;
}