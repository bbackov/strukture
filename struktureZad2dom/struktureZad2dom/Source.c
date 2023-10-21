#define CTR_SECURE_NO_WARNINGS_
#include <stdio.h>
#include <stdlib.h>
#define MAXDUZINA 80



typedef struct Osoba osoba;
typedef osoba* pozicija;

 struct Osoba {
	char ime[MAXDUZINA];
	char prezime[MAXDUZINA];
	int god;
	pozicija next;
};

int upisnapocetak(pozicija,char[MAXDUZINA], char[MAXDUZINA], int);
int ispis(pozicija );
int upisnakraj(pozicija, char[MAXDUZINA], char[MAXDUZINA], int);
int trazi(pozicija, char[MAXDUZINA]);

int main(){

	osoba head;
	head.next = NULL;

	upisnapocetak(&head, "ime1", "prezime1", 0001);
	upisnapocetak(&head, "ime2", "prezime2", 0002);
	upisnakraj(&head, "ime3", "prezime3", 0003);
	upisnakraj(&head, "ime4", "prezime4", 0004);
	ispis(head.next);
	trazi(head.next, "prezime3");

	return 0;
}

int upisnapocetak(pozicija p, char imef[MAXDUZINA], char prezimef[MAXDUZINA], int x) {
	pozicija new;
	new = (pozicija)malloc(sizeof(osoba));
	if (new == NULL) {
		printf("greška pri alociranju memorije");
		return -1;
	}

	new->next = p->next;
	p->next = new;

	strcpy(new->ime, imef);      
	strcpy(new->prezime, prezimef);
	new->god = x;

	return 1;
}

int ispis(pozicija p) {

	printf("\nime:\tprezime:\tgod:\n");

	while (p != NULL) {
		printf("%s\t%s\t%d\n", p->ime, p->prezime, p->god);
		p = p->next;
	}
	return 1;
}

int upisnakraj(pozicija p, char imef[MAXDUZINA], char prezimef[MAXDUZINA], int x) {
	pozicija new;
	new = (pozicija)malloc(sizeof(osoba));
	if (new == NULL) {
		printf("greška pri alociranju memorije");
		return -1;
	}

	while (p->next != NULL) {
		p = p->next;
	}

	new->next = p->next;
	p->next = new;

	strcpy(new->ime, imef);
	strcpy(new->prezime, prezimef);
	new->god = x;

	return 1;
}


int trazi(pozicija p, char prez[MAXDUZINA]) {

	int n=1;
	
	while (p != NULL) {
		if (prez==p->prezime) {
			printf("clan se nalazi na poziciji broj:%d ", n);
			return 1;
		}
		n++;
		p = p->next;
	}
	printf("clan ne postoji");

	return 1;
}