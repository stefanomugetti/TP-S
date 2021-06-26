
#include <string.h>
#include "Employee.h"
#include <stdlib.h>
#include <stdio.h>
#include "utn.h"
#include "LinkedList.h"

Employee* employee_new(void)
{
	return (Employee*) malloc(sizeof(Employee));
}

Employee* employee_newParamTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr)
{
	Employee* auxEmpleado=employee_new();

	if(auxEmpleado != NULL)
	{
		if (employee_setNombre(auxEmpleado,nombreStr) != 0||
			employee_setSueldoTxt(auxEmpleado,sueldoStr) != 0 ||
			employee_setHorasTrabajadasTxt(auxEmpleado, horasTrabajadasStr) != 0 ||
			employee_setIdEmpleadoTxt(auxEmpleado,idStr) != 0 )
		{
			employee_delete(auxEmpleado);
			auxEmpleado = NULL;
		}
	}
	return auxEmpleado;
}
Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas,int sueldo)
{
	Employee* auxEmpleado=employee_new();

	if(auxEmpleado != NULL)
	{
		if (employee_setNombre(auxEmpleado,nombreStr) != 0 ||
			employee_setSueldo(auxEmpleado,sueldo) != 0 ||
			employee_setHorasTrabajadas(auxEmpleado, horasTrabajadas) != 0 ||
			employee_setId(auxEmpleado,id)!= 0)
		{
			employee_delete(auxEmpleado);
			auxEmpleado = NULL;
		}
	}
	return auxEmpleado;
}

void employee_delete(Employee* this)
{
	if(this != NULL)
	{
		free(this);
	}
}
/*brief setea en el campo nombre de la entidad, el nombre pasado por parametro
 * param this Employee*
 * param nombre char*
 * return retorna -1 (ERROR) , 0(EXITO)
 */
int employee_setNombre(Employee* this,char* nombre)//EL SET ES EL UNICO QUE ACCEDE AL CAMPO PARA ESCRIBIRLO--TIENE QUE RECIBIR EL PUNTERO A UN EMPLEADO(CONTEXTO)
{
	int retorno=-1;
	if(this != NULL && nombre != NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}
/*brief escribe en el puntero nombre pasado por parametro, lo que hay en el campo nombre de la entidad
 * param this employee*
 * param nombre char*
 * return retorna -1(ERROR),0(EXITO)
 */
int employee_getNombre(Employee* this,char* nombre)//EL GET ES EL UNICO QUE ACCESE AL CAMPO PARA LEERLO	PARA ACCEDER AL CAMPO, LLAMAR A ESTAS FUNCIONES (GET-SET)
{
	int ret=-1;
		if(this != NULL && nombre != NULL)
		{
			strncpy(nombre,this->nombre,128);
			ret=0;
		}
		return ret;
}
/*brief valida si el nombre ingresado como string es valido
 * param nombre
 *  char*
 * return devuelve -1(ERROR),1(EXITO)
 */
int isValidNombre(char* nombre)
{
	int i=0;
	int retorno = -1;
	if(nombre != NULL)
	{
		retorno = 1;
		while(nombre[i] != 0) // busco el final
		{
			if(!((nombre[i]>='a' && nombre[i]<='z') || (nombre[i]>='A' && nombre[i]<='Z') || nombre[i]==' ' || nombre[i]=='-' ))
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
/*brief setea en el campo sueldo de la entidad, el sueldo pasado por parametro
 * param this Employee*
 * param sueldo int
 * return retorna -1 (ERROR) , 0(EXITO)
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno=-1;
	if(this != NULL)
	{
		this->sueldo=sueldo;
		retorno=0;
	}
	return retorno;
}
/*brief escribe en el puntero sueldo pasado por parametro, lo que hay en el campo sueldo de la entidad
 * param this employee*
 * param sueldo int*
 * return retorna -1(ERROR),0(EXITO)
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int ret=-1;
	if(this != NULL && sueldo != NULL)
	{
		*sueldo=this->sueldo;
		ret=0;
	}
	return ret;
}
/*brief setea en el campo horasTrabajadas de la entidad, las horasTrabajdas pasado por parametro
 * param this Employee*
 * param horasTrabajadas int
 * return retorna -1 (ERROR) , 0(EXITO)
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno=-1;
	if(this != NULL)
	{
		this->horasTrabajadas=horasTrabajadas;
		retorno=0;
	}
	return retorno;
}
/*brief escribe en el puntero horasTrabajadas pasado por parametro, lo que hay en el campo horasTrabajadas de la entidad
 * param this employee*
 * param horasTrabajadas int*
 * return retorna -1(ERROR),0(EXITO)
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int ret=-1;
	if(this != NULL && horasTrabajadas != NULL)
	{
		*horasTrabajadas=this->horasTrabajadas;
		ret=0;
	}

	return ret;
}
/*brief setea en el campo id de la entidad, el id pasado por parametro
 * param this Employee*
 * param id int
 * return retorna -1 (ERROR) , 0(EXITO)
 */
int employee_setId(Employee* this,int id)
{
	int retorno=-1;
	if(this != NULL)
	{
		this->id=id;
		retorno=0;
	}
	return retorno;
}
/*brief escribe en el puntero id pasado por parametro, lo que hay en el campo id de la entidad
 * param this employee*
 * param id int*
 * return retorna -1(ERROR),0(EXITO)
 */
int employee_getId(Employee* this,int* id)
{
	int ret=-1;
	if(this != NULL && id != NULL)
	{
		*id=this->id;
		ret=0;
	}
	return ret;
}

//*************************************************************** set TXT
/*brief setea en el campo id de la entidad, el id pasado por parametro que viene como string, transformandolo a int
 * param this Employee*
 * param idEmpleadoTxt char*
 * return retorna -1 (ERROR) , 0(EXITO)
 */
int employee_setIdEmpleadoTxt(Employee* this,char* idEmpleadoTxt)
{
	int retorno=-1;
	if(this != NULL && isValidIdEmpleadoTxt(idEmpleadoTxt))
	{
		this->id=atoi(idEmpleadoTxt);
		retorno=0;
	}
	return retorno;
}
/*brief valida si el id ingresado como string es valido
 * param id char*
 * return devuelve -1(ERROR),1(EXITO)
 */
int isValidIdEmpleadoTxt(char* idTxt)
{
	int i=0;
	int retorno = -1;
	if(idTxt != NULL)
	{
		retorno = 1;
		while(idTxt [i] != 0) // busco el final
		{
			if(!(idTxt[i]>='0' && idTxt[i]<='9'))
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}

/*brief setea en el campo horasTrabajadas de la entidad, las horasTrabajadas pasado por parametro que viene como string, transformandolo a int
 * param this Employee*
 * param horasTrabajadasTxt char*
 * return retorna -1 (ERROR) , 0(EXITO)
 */
int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadasTxt)
{
	int retorno=-1;
	if(this != NULL && isValidHorasTrabajadasTxt(horasTrabajadasTxt))
	{
		this->horasTrabajadas=atoi(horasTrabajadasTxt);
		retorno=0;
	}
	return retorno;
}
/*brief valida si las horasTrabajadas ingresado como string es valido
 * param horasTrabajadasTxt char*
 * return devuelve -1(ERROR),1(EXITO)
 */
int isValidHorasTrabajadasTxt(char* HorasTrabajadasTxt)
{
	int i=0;
	int retorno = -1;
	if(HorasTrabajadasTxt != NULL)
	{
		retorno = 1;
		while(HorasTrabajadasTxt[i] != 0) // busco el final
		{
			if(!(HorasTrabajadasTxt[i]>='0' && HorasTrabajadasTxt[i]<='9'))
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}
/*brief setea en el campo sueldo de la entidad, el sueldo pasado por parametro que viene como string, transformandolo a int
 * param this Employee*
 * param sueldoTxt char*
 * return retorna -1 (ERROR) , 0(EXITO)
 */
int employee_setSueldoTxt(Employee* this,char* sueldoTxt)
{
	int retorno=-1;
	if(this != NULL && isValidSueldoTxt(sueldoTxt))
	{
		this->sueldo=atoi(sueldoTxt);
		retorno=0;
	}
	return retorno;
}
/*brief valida si el sueldo ingresado como string es valido
 * param sueldoTxt char*
 * return devuelve -1(ERROR),1(EXITO)
 */
int isValidSueldoTxt(char* sueldoTxt)
{
	int i=0;
	int retorno = -1;
	if(sueldoTxt != NULL)
	{
		retorno = 1;
		while(sueldoTxt[i] != 0) // busco el final
		{
			if(!(sueldoTxt[i]>='0' && sueldoTxt[i]<='9'))
			{
				retorno = 0;
				break;
			}
			i++;
		}
	}
	return retorno;
}


/*brief marca el idMaximo ingresado desde el archivo pasado por parametro
 * param idMax int
 */
static int contador=0;
void employee_marcarIdMax(int idMax)
{
	contador=idMax;
}
/*brief genera id unico
 *  return retorna contador
 */
int employee_generarId(void)
{
	contador++;
	return contador;
}
/*brief buscar el id pasado por parametro
 * param pE Employee*
 * param id int
 * param len int indica hasta donde buscar
 * return retorna -1(ERROR), >= 0 (EXITO)
 */
int employee_buscarPorId2(Employee* pE,int id,int len)
{
	int ret=-1;
	int i;
	int idAux;
	for(i=0; i<len; i++)
	{
		if(pE != NULL)
		{
			employee_getId(pE,&idAux);
			if(idAux>=0)
			{
				if(idAux==id)
				{
					ret=i;
					break;
				}
			}
		}
	}
	return ret;
}
/*brief buscar el id pasado por parametro y escribe el indice en el puntero indiceEncontrado pasado por parametro
 * param pE Employee*
 * param id int
 * param len int indica hasta donde buscar
 * param indiceEncontrado int*
 * return retorna -1(ERROR), 0 (EXITO)
 */
int employee_buscarPorId(Employee* pE,int id,int len,int* indiceEncontrado)
{
	int ret=-1;
	int idAux;
	for(int i=0; i<len; i++)
	{
		if(pE != NULL && indiceEncontrado != NULL && len >= 0 && id >= 0)
		{
			employee_getId(pE,&idAux);
			ret=0;
			if(id==idAux)
			{
				*indiceEncontrado = i;
				break;
			}
		}
	}
	return ret;
}
/*brief Pide los datos y los escribe en las variables por parametros
 * param nombre char*
 * param horasTrabajadas int*
 * param sueldo int*
 *
 * return retorna -1 (ERROR) , 0(EXITO)
 */
int employee_pedirDatos(char* nombre, int* horasTrabajadas, int* sueldo)
{
	int ret=-1;
	if(nombre != NULL && horasTrabajadas != NULL && sueldo != NULL)
	{
		if(get_name(nombre,20,"Ingrese un nombre:\n","Nombre invalido.\n",2)==1 &&//valida nombre razonable
		   get_int(horasTrabajadas,5,"Ingrese la cantidad de horas trabajadas:\n", "Horas invalidas.\n", 1, 700, 2, 0) == 1 &&//validan cantidades razonables
		   get_int(sueldo,8, "Ingrese sueldo:\n", "Sueldo invalido.\n",5000,200000, 2, 0)== 1)
		{
			ret=0;
		}
		else
		{
			printf("Error en la carga de datos.\n");
		}
	}
	return ret;
}
/** \brief Ordena a la lista por el campo sueldo.
 *
 * \param item1 void*
 * \param item2 void*
 * \param pArrayListEmployee LinkedList*
 * \return retorna 0 (ERROR), 1 (item1 > item2) o -1 (item1 <= item2)
 *
 */
int employee_ordenarPorSueldo(void* item1,void* item2)
{
	int ret=0;

	Employee* e1;
	Employee* e2;

	int auxSueldo1;
	int auxSueldo2;

	e1=(Employee*)item1;
	e2=(Employee*)item2;

	if(employee_getSueldo(e1,&auxSueldo1) ==0 &&
		employee_getSueldo(e2,&auxSueldo2)==0)
	{
		if(auxSueldo1 > auxSueldo2)
		{
			ret=1;
		}
		else
		{
			ret=-1;
		}
	}
	return ret;
}

/** \brief Busca en la lista el elemento que contiene al idPedido.
 *
 * \param pArrayListEmployee LinkedList* lista
 * \param idPedido int es el id a buscar
 * \return retorna NULL (ERROR), != NULL (EXITO)
 */
Employee* employee_buscarEmpPorId(LinkedList* pArrayListEmployee,int idPedido)
{
	Employee* ret=NULL;
	Employee* pE=NULL;
	int i;
	int idObtenido;

	if(pArrayListEmployee != NULL && idPedido > 0)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pE=ll_get(pArrayListEmployee,i);
			if(pE != NULL)
			{
				employee_getId(pE,&idObtenido);
				if(idPedido == idObtenido)
				{
					ret=pE;
					break;
				}
			}
		}
	}
	return ret;
}
/** \brief Busca en la lista el indice del elemento que contiene al idPedido.
 *
 * \param pArrayListEmployee LinkedList* lista
 * \param idPedido int es el id a buscar
 * \return retorna -1 (ERROR), >= 0 (EXITO)
 */
int employee_buscarIndicePorId(LinkedList* pArrayListEmployee,int idPedido)
{
	int ret=-1;
	Employee* pE=NULL;
	int i;
	int idObtenido;

	if(pArrayListEmployee != NULL && idPedido > 0)
	{
		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			pE=ll_get(pArrayListEmployee,i);
			if(pE != NULL)
			{
				employee_getId(pE,&idObtenido);
				if(idPedido == idObtenido)
				{
					ret=i;
					break;
				}
			}
		}
	}
	return ret;
}
