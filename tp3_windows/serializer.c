/*
 * serializer.c
 *
 *  Created on: May 28, 2021
 *      Author: Stefano
 */
#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/*brief escribe los datos en el archivo formato txt
 * param pFile FILE*
 * param listaEmpleados linkedList*
 * return retorna -1(ERROR),0(EXITO)
 *
 */
int employee_serializerText(FILE* pFile,LinkedList* listaEmpleados)
{
	int ret=-1;
	int i;
	char nombre[126];
	int sueldo;
	int horasTrabajadas;
	int id;
	Employee* pE;
	if(pFile != NULL)
	{
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		ret=0;
		for(i=0; i<ll_len(listaEmpleados); i++)
		{
			pE=ll_get(listaEmpleados,i);
			if(pE != NULL)// lo imprimo
			{
				if(employee_getSueldo(pE,&sueldo)== 0 &&
				employee_getHorasTrabajadas(pE,&horasTrabajadas)== 0 &&
				employee_getId(pE,&id)== 0 &&
				employee_getNombre(pE, nombre)== 0)
				{
					fprintf(pFile,"%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
					printf("%d,%s,%d,%d\n",id,nombre,horasTrabajadas,sueldo);
				}
			}
		}
	}
	return ret;
}
int employee_serializerIdText(LinkedList* listaEmpleados)
{
	FILE* pFile;
	int ret=-1;
	int i;
	char nombre[126];
	int sueldo;
	int horasTrabajadas;
	int id;
	int idMax;
	Employee* pE;
	pFile=fopen("C:\\Users\\Stefano\\eclipse-workspace\\tp3_windows\\dataId.csv","w");
	if(pFile != NULL)
	{
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		ret=0;
		for(i=0; i<ll_len(listaEmpleados); i++)
		{
			pE=ll_get(listaEmpleados,i);
			if(pE != NULL)// lo imprimo
			{
				if(employee_getId(pE,&id)== 0)
				{
					fprintf(pFile,"%d\n",id,nombre,horasTrabajadas,sueldo);
					printf("%d",sueldo);

				}
			}
		}
	}
	return ret;
}
