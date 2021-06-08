#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "serializer.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int ret=-1;
	int idMax;
	pFile = fopen(path,"r");
	if(pFile != NULL)
	{
		idMax=parser_EmployeeFromText(pFile,pArrayListEmployee);
		if(idMax >= 0)
		{
			employee_marcarIdMax(idMax);
			printf("Parsear funcionando.\n");
			ret=0;
		}
		fclose(pFile);
	}
    return ret;
}


/*brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
*/

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	FILE* pFile;
	int ret=-1;
	int idMax;
	if(path != NULL)
	{
		pFile = fopen(path,"rb+");
		if(pFile != NULL)
		{
			idMax=parser_EmployeeFromBinary(pFile,pArrayListEmployee);
			if(idMax >= 0)
			{
				employee_marcarIdMax(idMax);
				printf("Parsear bin funcionando.\n");
				ret=0;
			}
			fclose(pFile);
		}
	}
	return ret;
}

/*brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{

	int retorno=-1;
	Employee* pE;
	char nombre[128];
	int sueldo;
	int horasTrabajadas;//CAMBIAR VARIABLES A CHAR
	int idGenerado;

	if(employee_pedirDatos(nombre, &horasTrabajadas, &sueldo)==0)
	{
			idGenerado=employee_generarId();//GENERO EL ID UNICO
			pE=employee_newParametros(idGenerado, nombre, horasTrabajadas, sueldo);//CONSTRUYO EL ESPACIO DE MEMORIA Y LO CARGO AL ARRAY
			if(pE != NULL)
			{
				ll_add(pArrayListEmployee, pE);
				retorno=0;
			}
	}
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	int auxId;
	int indiceEncontrado;
	Employee* pE;
	char auxNombre[128];
	int sueldo;
	int horasTrabajadas;
	int i;
	int auxIndice;
	if(ll_len(pArrayListEmployee) > 0)
	{
		if(get_int(&auxId, 7, "Ingrese un ID a modificar:\n", "Error", 1, 10000, 2, 0))
		{
			for(i=0;i<ll_len(pArrayListEmployee);i++)
				{
					pE=(Employee*)ll_get(pArrayListEmployee, i);
					indiceEncontrado=employee_buscarPorId2(pE, auxId, ll_len(pArrayListEmployee));
					if(indiceEncontrado >= 0)
					{
						  auxIndice = i;	//Invente esto para solucionar el problema de que no conseguia el indice correcto
						  break;
					}
				}
				if(auxIndice >= 0)
				{
					if(employee_pedirDatos(auxNombre, &horasTrabajadas, &sueldo) == 0)
					{
						if(employee_setNombre(pE,auxNombre) == 0 &&
							employee_setHorasTrabajadas(pE,horasTrabajadas) == 0 &&
							employee_setSueldo(pE,sueldo) == 0)
						{
							retorno=0;
						}
					}
				}
			else
			{
				printf("ID no encontrado.\n");
			}
		}
	}
	return retorno;
}

/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
		int retorno=-1;
		int auxId;
		int indiceEncontrado=-1;
		int i;
		int auxIndice=-1;
		Employee* pE;
		if(ll_len(pArrayListEmployee) > 0)
		{
			if(get_int(&auxId,7,"Ingrese un ID:\n","Error",1,10000,2,0))
			{
				for(i=0;i<ll_len(pArrayListEmployee);i++)
				{
					pE=(Employee*)ll_get(pArrayListEmployee, i);
					indiceEncontrado=employee_buscarPorId2(pE, auxId, ll_len(pArrayListEmployee));
					if(indiceEncontrado >= 0)
					{
						  auxIndice = i;	//Invente esto para solucionar el problema de que no conseguia el indice correcto
						  break;
					}
				}
				if(auxIndice >= 0)
				{
					ll_remove(pArrayListEmployee, auxIndice);
					employee_delete(pE);
					retorno=0;
				}
				else
				{
					printf("ID no encontrado.\n");
				}
			}
		}
		return retorno;
	}

/** \brief Listar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	Employee* pE;
	int id;
	int horasTrabajadas;
	int sueldo;
	char nombre[256];
	if(pArrayListEmployee != NULL)
	{
		ret=0;
		for(int i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pE = (Employee*)ll_get(pArrayListEmployee, i);
			if(pE != NULL)
			{
				if(employee_getHorasTrabajadas(pE,&horasTrabajadas) == 0 &&
					employee_getId(pE,&id)== 0 &&
					employee_getNombre(pE, nombre)== 0 &&
					employee_getSueldo(pE,&sueldo)== 0)

				printf("Id:%d||Nombre:%s||Horas Trabajadas:%d||Sueldo:%d\n",id,nombre,horasTrabajadas,sueldo);
			}
		}
	}
	return ret;
}

/** \brief Ordenar empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	int ret=-1;
	int newLimit;
	if(pArrayListEmployee != NULL)
	{
		newLimit=ll_len(pArrayListEmployee)-1;
		ret=0;
		for(int i=0;i<newLimit;i++)
		{
			ll_sort(pArrayListEmployee,employee_ordenarPorSueldo,1);//tarda aprox 6 seg en terminar de ejecutarse
			newLimit--;
		}
	}
	return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	FILE* pFile;

	pFile=fopen(path,"w");
	if(pFile != NULL)
	{
		if(employee_serializerText(pFile,pArrayListEmployee)==0)
		{
			ret=0;
			printf("Serializer funciona.");
		}
		fclose(pFile);
	}
    return ret;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int ret=-1;
	Employee* pE;
	FILE* pFile;
	int i;

	pFile = fopen(path,"wb+");
	if(pFile!=NULL)
	{
		ret=0;
		for(i=0; i<ll_len(pArrayListEmployee); i++)
		{
			pE=(Employee*)ll_get(pArrayListEmployee,i);
			fwrite(pE,sizeof(Employee),1,pFile);
		}
		fclose(pFile);
	}
	return ret;
}
