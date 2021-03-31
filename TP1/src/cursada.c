/*
 * cursada.c
 *
 *  Created on: Mar 25, 2021
 *      Author: Stefano
 */

#include <stdio.h>
#include <stdlib.h>
#include "cursada.h"

int utn_getNumero(int* numeroIngresado,char* pTexto,char* pTextoError,int min,int max,int reintentos)
{
	int retorno=-1;

for(int i=0;reintentos>=i;reintentos--)
{
	printf("%s\n",pTexto);
	fflush(stdin);
	if(scanf("%d",numeroIngresado)==1)
	{
		if(min <= max && (*numeroIngresado) >= min && (*numeroIngresado)<= max)
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

int utn_getFloat(float* numeroIngresado,char* pTexto,char* pTextoError,int min,int max,int reintentos)
{
	int retorno=-1;

for(int i=0;reintentos>=i;reintentos--)
{
		printf("%s\n",pTexto);
		fflush(stdin);
	if(scanf("%f",numeroIngresado)==1)
	{
		if(min<max && *numeroIngresado >= min && *numeroIngresado <= max)
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

int utn_getChar(char* charIngresado,char* pTexto,char* pTextoError,char min,char max,int reintentos)
{
	int retorno=-1;
	char bufferChar;

for(int i=0;reintentos >= i;reintentos--)
{
	printf("%s",pTexto);
	fflush(stdin);
	if(scanf(" %c",&bufferChar)==1)
	{
		if(bufferChar >=min && bufferChar <=max)
		{
			*charIngresado=bufferChar;
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


