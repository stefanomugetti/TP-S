/*
 * operaciones.c
 *
 *  Created on: Mar 27, 2021
 *      Author: Stefano
 */

#include <stdio.h>
#include <stdlib.h>
#include "cursada.h"

int utn_getSuma(int* pOperador1,int* pOperador2,float* resultado)
{
	*resultado=(float)*pOperador1+*pOperador2;
	return 0;
}
int utn_getMultiplicacion(int* pOperador1,int* pOperador2,float* resultado)
{
	*resultado=(float)(*pOperador1)*(*pOperador2);
	return 0;
}
int utn_getResta(int* pOperador1,int* pOperador2,float* resultado)
{

	*resultado=(float)*pOperador1-*pOperador2;
	return 0;
}
int utn_getDivision(int* pOperador1,int* pOperador2,float* resultado)
{
	int retorno = -1;
	if(*pOperador2 == 0)
	{
		printf("Error, no se puede dividir por 0\n");
	}
	else
	{
		*resultado=(float)*(pOperador1)/(*pOperador2);
				retorno=0;
	}

	return retorno;
}
int utn_getFactorial(int*pOperador,float*resultado)
{
	int retorno=-1;
	int producto=1;
if(*pOperador >0)
{
	for(int i=*pOperador;i>1;i--)
	{
		producto*=i;

	}
		*resultado=producto;
		retorno=0;
}
else
{
	printf("\nNo existe factoriales de numeros negativos");
}
	return retorno;
}

