#include <stdio.h>

void show (int x, int b, int c, int d, int e, int f, int g, int h, int l )
{
	int i;
	char a[22];
	for (i = 0; i <5; i++)
		a[i]='|';
	for (i = 10; i <15; i++)
		a[i]='|';
	for (i = 19; i > 14; i--)
	{
		a[i]='-';
	}
		for (i = 5; i < 10; i++)
	{
		a[i]='-';
	}
	a[x-1]='S';
	a[b-1]='S';
	a[c-1]='B';
	a[d-1]='C';
	a[e-1]='C';
	a[f-1]='H';
	a[g-1]='H';
	a[h-1]='1';
	a[l-1]='2';
	for (i = 19; i > 14; i--)
	{
		printf("%c\t",a[i]);
	}
	printf("\n");
	printf("%c                               %c\n",a[0],a[14]);
	printf("%c                               %c\n",a[1],a[13]);
	printf("%c                               %c\n",a[2],a[12]);
    printf("%c                               %c\n",a[3],a[11]);
	printf("%c                               %c\n",a[4],a[10]);
	for (i = 5; i < 10; i++)
	{
		printf("%c\t",a[i]);
	}
	printf("\n");
}
