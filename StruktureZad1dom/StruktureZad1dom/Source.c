#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define BUFFER 1024
#define MAXDUZINA 80


typedef struct {
	char ime[MAXDUZINA];
	char prezime[MAXDUZINA];
	int bodovi;
}student;

int brojr();
student* alokacija(int);
int upis(int,student*);
int ispis(int, student*);

int main(){

	int n;
	student* s = NULL;
	n = brojr();
	printf("broj redaka je:%d \n",n);
	s = alokacija(n);
	upis(n, s);
	ispis(n, s);

	return 0;
}

int brojr() {
	int brojac=0;
	FILE* f = NULL;
	char buffer[BUFFER];

	f = fopen("Text.txt","r");
	if (f == NULL) {
		printf("greška pri ucitavanju datoteke.");
		return -1;
	}
    
	while (!feof(f)) {
		fgets(buffer, sizeof(buffer), f);
		brojac++;
	}
	fclose(f);
	return brojac;
}

student* alokacija(int n) {
	student* s = NULL;
	s = (student*)malloc(n*sizeof(student));
	
	return s;
}

int upis(int n,student* s) {
	FILE* f = NULL;
	f = fopen("Text.txt", "r");
	if (f == NULL) {
		printf("greška pri ucitavanju datoteke.");
		return -1;
	}

	for (int i = 0; i < n; i++) {
		fscanf(f, "%s %s %d", s[i].ime, s[i].prezime, &s[i].bodovi);
	}
	
	fclose(f);
	return 1;
}

int ispis(int n, student* s) {

	printf("\nime:\tprezime:\tRB:\tAB\t\n");

	for (int i = 0; i < n; i++) {
		printf("%s\t%s\t%d\t%lf\n", (s + i)->ime, (s + i)->prezime, (s + i)->bodovi,(double)(s + i)->bodovi/50);
	}
	return 1;
}