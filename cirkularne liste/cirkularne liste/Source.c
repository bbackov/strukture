#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


typedef struct nebitno {
	int broj;
	struct nebitno* next;
	

}list;
typedef list* pozicija;

pozicija novi();
int upisP(pozicija,int);
int ispis(pozicija);
int upisK(pozicija,int);
int sort(pozicija);

int main() {

	list head;
	head.next = NULL;

	upisP(&head, 1);
	upisP(&head,81);
	upisP(&head, 9);
	upisK(&head, 17);
	upisP(&head, 16);
	upisP(&head,5);
	ispis(head.next);
	upisK(&head, 90);
	upisP(&head,-16);
	printf("\n0debeli kurac\n");
	ispis(head.next);
	sort(head.next);
	printf("\n0debeli kurac\n");
	ispis(head.next);


	return 0;
}

pozicija novi() {
	pozicija new = (pozicija)malloc(sizeof(list));
	if (new == NULL) {
		return NULL;
	}

	return new;
}

int upisP(pozicija glavni,int broj1) {

	pozicija start = glavni->next;
	pozicija new = novi();
	if (new == NULL) {
		return -1;
	}

	if (glavni->next == NULL) {
		glavni->next = new;
		new->next = new;
		new->broj = broj1;
		
		return 1;
	}
	else {
		new->next = glavni->next;
		glavni->next = new;
		new->broj = broj1;
		glavni = new->next;
		do{
			glavni = glavni->next;
		} while (glavni->next != start);
		glavni->next = new;
		
	
		return 1;
	}

}
int ispis(pozicija glavni) {
	pozicija start = glavni;

	do {
		
			printf("X:%d\n", glavni->broj);
			glavni = glavni->next;
		
	} while (glavni != start);
	return 1;
}

int upisK(pozicija glavni,int broj1) {
	pozicija start = glavni->next;
	pozicija new = novi();
	if (new == NULL) {
		return -1;
	}

	if (glavni->next == NULL) {
		glavni->next = new;
		new->next = new;
		new->broj = broj1;

		return 1;
	}
	else {
		do {
			glavni=glavni->next;
		} while (glavni->next!=start);
		new->next = glavni->next;
		glavni -> next = new;
		new->broj = broj1;
		
	}
	
}

int sort(pozicija glavni) {
	pozicija start = glavni;
	pozicija temp;
	pozicija brojac = glavni;
	pozicija prev = glavni;


	while (glavni->next != start) {

		while(brojac->next != start) {
			if (brojac->broj > brojac->next->broj) {
				temp = brojac->next;
				brojac->next = temp->next;
				temp->next =brojac;
				

				prev->next = temp;
				
			}
			prev = brojac;
			brojac = brojac->next;
			
		} 
		prev = glavni;
		glavni = glavni->next;
		brojac = glavni;
	
	} 
	return 1;
}
