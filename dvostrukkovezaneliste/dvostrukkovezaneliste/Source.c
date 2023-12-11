#define _CRT_SECURE_NO_WARNINGS

#include<stdio.h>
#include<stdlib.h>


typedef struct nebitno {
	int broj;
	struct nebitno* next;
	struct nebitno* prev;

}list;
typedef list* pozicija;


int ispis(pozicija);
int upisP(pozicija,int);
int UpisK(pozicija, int);
int brisi(pozicija, int);
int sort(pozicija);
pozicija novi();


int main() {

	list head;
	head.next = NULL;
	head.prev = NULL;

	upisP(&head,3);
	upisP(&head, 7);
	upisK(&head, 1);
	upisP(&head, -5);
	ispis(head.next);
	printf("\ndebeli kurac\n");
	upisK(&head, 14);
	upisP(&head, -4);
	ispis(head.next);
	printf("\ndebeli kurac\n");
	brisi(head.next, 7);
	ispis(head.next);
	printf("\ndebeli kurac\n");
	sort(&head);
	ispis(head.next);
	printf("\ndebeli kurac\nx:%d", head.next->broj);
	printf("\ndebeli kurac\nx:%d", head.next->next->broj);

	return 0;
}

int upisP(pozicija nextv, int broj1) {
	pozicija new;
	
	new = novi();
	
	if (new == NULL) {
		return -1;
	}
	if (nextv->next == NULL) {
		new->next = NULL;
		new->prev = NULL;
		nextv->next = new;
		new->broj = broj1;
		
		return 1;
	}
	
	new->next = nextv->next;
	new->prev = NULL;
	new->next->prev = new;
	nextv->next = new;
	new->broj = broj1;
	return 1;
}

pozicija novi() {
	pozicija new = (pozicija)malloc(sizeof(list));
	if (new == NULL) {
		return NULL;
	}
	
	return new;
}

int ispis(pozicija glavni){
	
	while (glavni != NULL) {
		printf("X:%d\n", glavni->broj);
		glavni = glavni->next;
	}
	return 1;
}

int upisK(pozicija glavni, int broj1) {
	pozicija new;

	new = novi();
	if (new == NULL) {
		return -1;
	}

	while (glavni->next!=NULL) {
		glavni=glavni->next;
	}

	
	
	glavni->next = new;
	new->prev = glavni;
	new->next = NULL;
	new->broj = broj1;
	
	return 1;
}

int brisi(pozicija glavni,int broj1){

	pozicija temp;

	while (glavni != NULL && glavni->broj != broj1) {
		glavni = glavni->next;
	}
	if (glavni == NULL) {
		printf("element ne postoji");
		return -1;
	}
	else if (glavni->next == NULL) {
		temp = glavni;
		glavni->prev->next = glavni->next;
		free(temp);
		return 1;
	}
	else if (glavni->prev == NULL) {
		temp = glavni;
		glavni->next->prev = glavni->prev;
		free(temp);
		return 1;
	}
	else {

		temp = glavni;
		glavni->prev->next = glavni->next;
		glavni->next->prev = glavni->prev;

		free(temp);

		return 1;
	}
}



	int sort(pozicija glavni) {
	
	pozicija start = glavni;
	pozicija temp = NULL;

	while (start->next != NULL) {
		while (glavni->next != NULL) {
			if (glavni->broj > glavni->next->broj) {
				temp = glavni->next;
				glavni->next = temp->next;
				temp->next = glavni;
				temp->prev = glavni->prev;
				glavni->prev = temp;
				if (temp->prev != NULL) {
					temp->prev->next = temp;
				}
				else {
					start->next = temp;
				}
				if (glavni->next != NULL) {
					glavni->next->prev = glavni; 
				}
				
			}
			
				glavni = glavni->next;
			
		}
		start = start->next;
		glavni = start;
	}
	return 1;
}

