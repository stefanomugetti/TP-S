/*
 * menu.c
 *
 *  Created on: Mar 27, 2021
 *      Author: Stefano
 */
#include <stdio.h>
#include <stdlib.h>
#include "cursada.h"
#include "operaciones.h"
#include "menu.h"

int utn_getMenu(char* pOpcionElegida,char*pTexto,char* pTextoError,char minimo,char maximo,int reintentos)
{
	int retorno= -1;

for(int i=0;reintentos>=i;reintentos--)
{
	printf("%s\n",pTexto);
	fflush(stdin);
	if(scanf("%c",pOpcionElegida)==1)
	{
		if(*pOpcionElegida >= minimo && *pOpcionElegida<=maximo)
		{
			retorno=0;
			break;
		}
		else
		{
			printf("%s\n",pTextoError);
		}
	}
	else
	{
		printf("%s\n",pTextoError);
	}
}
	return retorno;
}
