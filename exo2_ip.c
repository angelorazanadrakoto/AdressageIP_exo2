#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "exo2_ip.h"

int main()
{
	debug_ip();
	return 0;
}
/*--------------------------------------------------------------------------------*/
void debug_ip()
{
	number n1;
	int i, j, k, l;
	char IP[32];
	n1.nb = -1, n1.nb2 = -1, n1.nb3 = -1, n1.nb4 = -1;
	do
	{
		printf("IP: ");
		scanf("%s", IP);
		sscanf(IP, "%d.%d.%d.%d", &n1.nb, &n1.nb2, &n1.nb3, &n1.nb4);
	} while (n1.nb == -1 || n1.nb2 == -1 || n1.nb3 == -1 || n1.nb4 == -1);
	if (n1.nb2 > 255 || n1.nb3 > 255 || n1.nb4 > 255)
	{
		printf("\t______________________________\n");
		printf("\t|ADRESSE IP NON VALIDE!!!|\n");
		printf("\t------------------------------\n");
		exit(1);
	}
	calcul_binaire(n1);
	IPclass(n1);
}
/*--------------------------------------------------------------------------------*/
void calcul_binaire(number n1)
{
	int i, j, k, l;
	int bin[8]={0};
    int bin2[8]={0};
    int bin3[8]={0};
    int bin4[8]={0};
	for (i = 0; n1.nb > 0; i++)
	{
		bin[i] = n1.nb % 2;
		n1.nb = n1.nb / 2;
	}
	for (j = 0; n1.nb2 > 0; j++)
	{
		bin2[j] = n1.nb2 % 2;
		n1.nb2 = n1.nb2 / 2;
	}
	for (k = 0; n1.nb3 > 0; k++)
	{
		bin3[k] = n1.nb3 % 2;
		n1.nb3 = n1.nb3 / 2;
	}
	for (l = 0; n1.nb4 > 0; l++)
	{
		bin4[l] = n1.nb4 % 2;
		n1.nb4 = n1.nb4 / 2;
	}
	affichage_binaire(n1, bin, bin2, bin3, bin4);
}
/*--------------------------------------------------------------------------------*/
void affichage_binaire(number n1, int bin[8], int bin2[8], int bin3[8], int bin4[8])
{
	int i, j, k, l;						printf("\t__________________________________\n");
    printf("\tAFFICHAGE EN BINAIRE !!!\n\t");
	for (i = 7; i >= 0; i--)
	{
		printf("%d", bin[i]);
	}
	printf(".");
	for (j = 7; j >= 0; j--)
	{
		printf("%d", bin2[j]);
	}
	printf(".");
	for (k = 7; k >= 0; k--)
	{
		printf("%d", bin3[k]);
	}
	printf(".");
	for (l = 7; l >= 0; l--)
	{
		printf("%d", bin4[l]);
	}
	printf("\n\t----------------------------------\n");
}
/*--------------------------------------------------------------------------------*/
void IPclass(number n1)
{
    if(n1.nb>=0 && n1.nb<128)
    {
        printf("\t__________________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE A|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t----------------------------------\n");
    }
    else if(n1.nb>=128 && n1.nb<192)
    {
        printf("\t__________________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE B|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t----------------------------------\n");
    }
    else if(n1.nb>=192 && n1.nb<224)
    {
        printf("\t__________________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE C|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t----------------------------------\n");
    }
    else if(n1.nb>=224 && n1.nb<240)
    {
        printf("\t__________________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE D|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t----------------------------------\n");
    }
    else if(n1.nb>=240 && n1.nb<256)
    {
        printf("\t_________________________________\n");
        printf("\t|%d.%d.%d.%d|IP DE CLASSE E|\n", n1.nb, n1.nb2, n1.nb3, n1.nb4);
        printf("\t---------------------------------\n");
    }
    else if(n1.nb>255)
    {
        printf("\t_________________________________\n");
        printf("\t|ADRESSE IP NON VALIDE!!!|\n");
        printf("\t---------------------------------\n");
        exit(1);
    }
}
/*--------------------------------------------------------------------------------*/