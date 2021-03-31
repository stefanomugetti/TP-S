#include <stdio.h>
#include <stdlib.h>
#include "cursada.h"
#include "operaciones.h"
#include "menu.h"

int main(void)
{
	setbuf(stdout,NULL);
	int num1;
	int num2;
	char opElegida;
	float resultado;

	utn_getNumero(&num1,"Ingrese el primer numero","Error, ingrese un valor valido.",-5000,5000,2);
	utn_getNumero(&num2,"Ingrese el segundo numero","Error, ingrese un valor valido.",-5000,5000,2);
	printf("Primer numero:%d\n Segundo numero:%d\n",num1,num2);

	utn_getMenu(&opElegida,"Elija una opcion:\n a)Suma\n b)Resta\n c)Multiplicacion\n d)Division\n e)Factorial\n"
			,"Elija una opcion valida.",'a','e',3);

	switch(opElegida)
	{
		case'a':
			if(utn_getSuma(&num1,&num2,&resultado)==0)
			{
				printf("\nEl resultado de %d + %d = %f",num1,num2,resultado);
			}
		break;
		case'b':
			if(utn_getResta(&num1,&num2,&resultado)==0)
			{
				printf("\nEl resultado de %d - %d = %f",num1,num2,resultado);
			}
		break;
		case'c':
			if(utn_getMultiplicacion(&num1,&num2,&resultado)==0)
			{
				printf("\nEl resultado de %d * %d = %f",num1,num2,resultado);
			}
		break;
		case'd':
			if(utn_getDivision(&num1,&num2,&resultado)==0)
			{
				printf("\nEl resultado de %d / %d = %f",num1,num2,resultado);
			}
		break;
		case'e':
			if(utn_getFactorial(&num1,&resultado)==0)
			{
				printf("\nEl factorial de %d = %f",num1,resultado);
			}
			if(utn_getFactorial(&num2,&resultado)==0)
			{
				printf("\nEl factorial de %d = %f",num2,resultado);
			}
		break;
	}
	return EXIT_SUCCESS;
}
