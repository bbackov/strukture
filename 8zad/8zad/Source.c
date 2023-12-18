/*
Napisati program koji omogucava rad s binarnim stablom pretrazivanja.Treba
omoguciti unosenje novog elementa u stablo, ispis elemenata(inorder, preorder, postorder i
level order), brisanje i pronalazenje nekog elementa.
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 30

typedef struct nebitno {
	int number;
	struct nebitno* left;
	struct nebitno* right;
}node_;

typedef node_* node;

int menu();
node treemaker(node root, int x);
node createnode(int x);
int inorderprint(node root);
int preorderprint(node root);
int postorderprint(node root);
int levelorderprint(node root);
node delnum(node root, int x);
node find(node root, int x);

int main()
{
	char n;
	int x = 0;
	int g;

	node root;
	root = malloc(sizeof(node_));

	do {
		n = menu();

		switch (n)
		{
		case '1':
			printf("\nUnesite vrijednost koju zelite unijeti u stablo: ");
			scanf("%d", &g);
			printf("\n");
			if (x == 0)
			{
				root->number = g;
				root->left = NULL;
				root->right = NULL;
			}
			else {
				treemaker(root, g);
			}
			x++;
			break;

		case '2':
			if (root->number == NULL)
			{
				printf("\nLista je prazna\n\n");
				break;
			}
			inorderprint(root);
			break;

		case '3':
			if (root->number == NULL)
			{
				printf("\nLista je prazna\n\n");
				break;
			}
			preorderprint(root);
			break;

		case '4':
			if (root->number == NULL)
			{
				printf("\nLista je prazna\n\n");
				break;
			}
			postorderprint(root);
			break;

		case '5':
			if (root->number == NULL)
			{
				printf("\nLista je prazna\n\n");
				break;
			}

			levelorderprint(root);
			break;

		case '6':
			if (root->number == NULL)
			{
				printf("\nLista je prazna\n\n");
				break;
			}
			printf("\nUnesite vrijednost broja koju zelite izbrisati: \n");
			scanf("%d", &g);

			delnum(root, g);
			break;

		case '7':
			if (root->number == NULL)
			{
				printf("\nLista je prazna\n\n");
				break;
			}
			printf("\nUnesite vrijednost broja koju zelite pronaci: \n");
			scanf("%d", &g);

			find(root, g);
			break;
		}
	} while (1);
}

int menu()
{
	char c[MAX_LINE];

	do {
		printf("Pritisnite \"1\" za unos elemenata u stablo\n");
		printf("Pritisnite \"2\" za ispis stabla(inorder)\n");
		printf("Pritisnite \"3\" za ispis stabla(preorder)\n");
		printf("Pritisnite \"4\" za ispis stabla(postorder)\n");
		printf("Pritisnite \"5\" za ispis stabla(levelorder)\n");
		printf("Pritisnite \"6\" za brisanje odredenog elementa\n");
		printf("Pritisnite \"7\" za pronalazak odredenog elementa\n");
		printf("Pritisnite \"0\" za izlaz iz programa\n");
		printf("Unos: ");

		scanf("%s", c);

		if (strlen(c) == 1)
		{
			if (strcmp(c, "0") >= 0 && strcmp(c, "7") <= 0)
			{
				return c[0];
			}
		}

	} while (1);
}

node treemaker(node root, int x)
{
	if (root == NULL)
	{
		return createnode(x);
	}
	if (root->number >= x)
	{
		root->left = treemaker(root->left, x);
	}
	if (root->number < x)
	{
		root->right = treemaker(root->right, x);
	}

	return root;
}

node createnode(int x)
{
	node ptr = malloc(sizeof(node_));
	ptr->number = x;

	ptr->left = NULL;
	ptr->right = NULL;

	return ptr;
}

int inorderprint(node root)
{
	if (root == NULL)
	{
		return 0;
	}

	inorderprint(root->left);
	printf("%d\n", root->number);
	inorderprint(root->right);
}

int preorderprint(node root)
{
	if (root == NULL)
	{
		return 0;
	}

	printf("%d\n", root->number);

	preorderprint(root->left);
	preorderprint(root->right);
}

int postorderprint(node root)
{
	if (root == NULL)
	{
		return 0;
	}

	postorderprint(root->left);
	postorderprint(root->right);

	printf("%d\n", root->number);
}

int levelorderprint(node root)
{
	if (root == NULL)
		return;

	node queue[100];
	int front = 0, rear = 0;

	queue[rear++] = root;

	while (front < rear) {
		node current = queue[front++];

		printf("%d\n", current->number);

		if (current->left != NULL)
			queue[rear++] = current->left;

		if (current->right != NULL)
			queue[rear++] = current->right;
	}

	return 0;
}

node delnum(node root, int x)
{
	if (root == NULL)
	{
		return root;
	}

	if (root->number < x)
	{
		root->right = delnum(root->right, x);
	}

	if (root->number > x)
	{
		root->left = delnum(root->left, x);
	}

	if (root->number == x)
	{
		if (root->left == NULL)
		{
			node temp = root->right;
			free(root);
			return temp;

		}
		else if (root->right == NULL)
		{
			node temp = root->left;
			free(root);
			return temp;
		}

		node temp = root->right;
		while (temp->left != NULL)
		{
			temp = temp->left;
		}
		root->number = temp->number;
		root->right = delnum(root->right, temp->number);
	}

	return root;
}

node find(node root, int x)
{
	if (root == NULL)
	{
		printf("\nVrijednost ne postoji\n\n");
		return root;
	}
	if (root->number == x)
	{
		printf("\nClan %d se nalazi u stablu\n\n", x);
		return root;
	}
	if (root->number < x)
	{
		find(root->right, x);
	}
	if (root->number > x)
	{
		find(root->left, x);
	}
}