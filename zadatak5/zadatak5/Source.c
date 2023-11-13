#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024


typedef struct stog {
	int broj;
	struct stog* next;
}broj;
typedef broj* pozicija;

char* unos();
int racun(char*,pozicija);
int izracun(char,pozicija);
int push(pozicija);
int pop(pozicija);


int main() {

	broj head;
	head.next=NULL;
	char* izraz;
	izraz = unos();
	racun(izraz, &head);
	printf("rezultat je:%d", head.next->broj);

	return 0;
}

char* unos() {

	char* buffer = (char*)malloc(MAX_LINE * sizeof(char));
	if (buffer == NULL) {
		printf("greska pri citanju");
		return -1;
	}
	FILE* file = NULL;
	file = fopen("izraz.txt", "r");
	if (file == NULL) {
		printf("greska pri citanju");
		return -1;
	}

	fgets(buffer, MAX_LINE, file);


	return buffer;
}

int racun(char* izraz,pozicija head) {

	
	int broj;
	char operacija;
	int buffercount;


	while (*izraz != '\0' && *izraz != '\n') {
		
		if (sscanf(izraz, " %d %n", &broj, &buffercount) == 1) {

			push(head, broj);
		}
		else if (sscanf(izraz, " %c %n", &operacija, &buffercount) == 1) {
			if (operacija != '\0' && operacija != ' ' && operacija != '\n') {
				push(head, izracun(operacija,head));
			}
		}
		izraz += buffercount;
	}

	return 0;

}

int izracun(char op,pozicija head) {

	int broj1;
	int broj2;
	int rez=0;

	broj1 = pop(head);
	broj2 = pop(head);

	switch (op)
	{
	case '+':
		rez = broj1 + broj2;
		break;

	case '-':
		rez = broj2 - broj1;
		break;

	case '*':
		rez = broj2 * broj1;
		break;

	default:
		printf("greska pri izvodenjiu");
		break;
	}

	return rez;
}

int push(pozicija glavni,int broj) {

	pozicija novi;

	novi = (pozicija)malloc(sizeof(broj));
	if (novi == NULL) {
		printf("greska pri alociranju memorije");
		return -1;
	}
	novi->broj = broj;

	novi->next = glavni->next;
	glavni->next = novi;
	return 1;
}

int pop(pozicija glavni) {
	pozicija temp;
	int x;
	x = glavni->next->broj;
	temp = glavni->next;
	glavni->next = glavni->next->next;
	free(temp);

	return x;
}