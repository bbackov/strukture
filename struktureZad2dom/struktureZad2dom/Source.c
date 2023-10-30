#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include<string.h>
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
int brisi(pozicija, char[MAXDUZINA]);
int upisiza(pozicija, char[MAXDUZINA], char[MAXDUZINA], int, char[MAXDUZINA]);
int upisispred(pozicija p, char ime[MAXDUZINA], char prez[MAXDUZINA], int god, char imef[MAXDUZINA]);
int sort(pozicija p);

int main(){

	osoba head;
	head.next = NULL;

	upisnapocetak(&head, "ime1", "prezime1", 0001);
	upisnapocetak(&head, "ime2", "prezime2", 0002);
	upisnakraj(&head, "ime3", "prezime3", 0003);
	upisnakraj(&head, "ime4", "prezime4", 0004);
	upisnakraj(&head, "ime5", "prezime5", 0005);
	ispis(head.next);
	trazi(head.next, "prezime4");
	brisi(&head, "ime2");
	ispis(head.next);
	upisiza(&head, "ime6", "prezime6", 0006,"ime3");
	printf("\n");
	ispis(head.next);
	upisispred(&head, "ime7", "prezime7", 0007, "ime3");
	printf("\n");
	ispis(head.next);

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
		if (!strcmp(p->prezime, prez)) {
			printf("clan se nalazi na poziciji broj:%d ", n);
			return 1;
		}
		n++;
		p = p->next;
	}
	printf("clan ne postoji");

	return -1;
}

int brisi(pozicija p, char imef[MAXDUZINA]) {
	
	

	while (p->next->next != NULL) {
		pozicija temp = NULL;
		if (p->next!=NULL && !strcmp(p->next->ime, imef)) {
			temp = p -> next;
			p->next = p->next->next;
			free(temp);
			return 1;
		}
		
		p = p->next;
		
	}
	printf("clan ne postoji");
	return -1;
}

int upisiza(pozicija p, char ime[MAXDUZINA], char prez[MAXDUZINA], int god, char imef[MAXDUZINA]) {

	pozicija novi = NULL;


	while (p != NULL) {
		if (!strcmp(p->ime, imef)) {
			novi = (pozicija)malloc(sizeof(osoba));
			if (novi == NULL) {
				printf("greška pri alociranju memorije");
				return -1;
			}

			novi->next = p->next;
			p->next = novi;
			strcpy(novi->ime, ime);
			strcpy(novi->prezime, prez);
			novi->god = god;
			return 1;
			
		}
		
		p = p->next;
	}
	if (p == NULL) {
printf("clan ne postoji");
return -1;
	}
	

	

	
}

int upisispred(pozicija p, char ime[MAXDUZINA], char prez[MAXDUZINA], int god, char imef[MAXDUZINA]) {

	pozicija novi = NULL;
	pozicija prosli = NULL;


	while (p != NULL) {
		if (!strcmp(p->ime, imef)) {
			novi = (pozicija)malloc(sizeof(osoba));
			if (novi == NULL) {
				printf("greška pri alociranju memorije");
				return -1;
			}


			novi->next = prosli->next;
			prosli->next=novi;



			strcpy(novi->ime, ime);
			strcpy(novi->prezime, prez);
			novi->god = god;
			return 1;

		}
	    prosli = p;
		p = p->next;
	
	}
	if (p == NULL) {
		printf("clan ne postoji");
		return -1;
	}

}

int sort(pozicija p) {

	for (int i = 0; (p + i) != NULL; i++) {

	}
}