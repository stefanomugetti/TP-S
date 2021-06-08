#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "Controller.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna -1 (ERROR), >= 0(EXITO)
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char nombreAux[128];
	char sueldoAux[128];
	char horasTrabajadasAux[128];
	char idAux[128];

	int flagOnce=0;
	int indice=-1;

	int idEmp;
	int idMax;
	int pIdMaxEncontrado=-1;//retorna error en caso de no encontrar un maximo

	Employee* pE;

	if(pFile != NULL)
	{
		indice=0;
		do
		{
			if(fscanf(pFile,"%[^,],%[^,],%[^,],%[^\n]\n",idAux,nombreAux,horasTrabajadasAux,sueldoAux)==4)
			{
				if(flagOnce!=0)
				{
					pE = employee_newParamTxt(idAux,nombreAux,horasTrabajadasAux,sueldoAux);
					if(pE != NULL)
					{
						ll_add(pArrayListEmployee,pE);
						idEmp = atoi(idAux);
						if(indice==0)
						{
							idMax = idEmp; // me guardo el 1ero como MAX
						}
						else
						{
							if(idEmp>idMax)
							{
								idMax = idEmp;
							}
						}
						indice++;
					}
				}
			}
			else
			{
				printf("Error.\n");
			}
			flagOnce=1;
		}while(!feof(pFile));

		pIdMaxEncontrado = idMax; // lo devuelvo en la variable externa (del main)
	}
		return pIdMaxEncontrado;
	}
/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return retorna -1 (ERROR), >=(EXITO)
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	Employee* pE=NULL;
	Employee auxEmployee;
	int ret=-1;
	int flagMax;
	int idMax;
	int idEmp;
	int i;

	if(pFile!=NULL && pArrayListEmployee != NULL)
	{
		do
		{
			if(fread(&auxEmployee, sizeof(Employee), 1, pFile)==1)
			{
				pE = employee_newParametros(auxEmployee.id, auxEmployee.nombre, auxEmployee.horasTrabajadas, auxEmployee.sueldo);
				if(pE != NULL)
				{
					idEmp=auxEmployee.id;
					if(ll_add(pArrayListEmployee, pE) == 0 &&
						flagMax == 0)
					{
						flagMax=idEmp;
					}
					if(idEmp >= idMax)
					{
						idMax=idEmp;
						ret=idMax;
					}
				}
				else
				{
					employee_delete(pE);
				}
			}
			i++;
		}while(!feof(pFile));
				printf("i dio:%d vueltas",i);
	}
	return ret;
}
