
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int rez(int, int, int(*)(int, int));
int mno(int, int);
int zbroj(int, int);

int main() {

	int x=0;
	int y=0;
	char c = 0;

	int (*p)(int, int) = NULL;

		printf("upisite dva broja:");
		scanf("%d %d",&x,&y);

		printf("za zbrajanje upisite '+' za mnozenje '*': ");
		scanf(" %c", &c);

		if (c == '+') {
			p = zbroj;
		}
		else {
			p=mno;
		}

		printf("rezultat je:%d", rez(x, y,p));

		return 0;
}

int rez(int x, int y , int(*p)(int, int) ) {
	
	
	return p(x, y);

}
int mno(int x, int y) {
	return x*y;
}
int zbroj(int x, int y)
{
	return x + y;
}