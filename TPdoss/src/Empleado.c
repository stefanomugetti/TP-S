/*
 * empleado.c
 *
 *  Created on: May 11, 2021
 *      Author: Stefano
 */
#include "Empleado.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"


Empleado* emp_new(void)
{
	return (Empleado*) malloc(sizeof(Empleado));
}

Empleado* emp_newParam(char* nombre,char* apellido,int idEmpleado,int sector,float salario)
{
	Empleado* auxEmpleado= emp_new();
	if(auxEmpleado != NULL)
	{
		if (emp_setNombre(auxEmpleado,nombre) ||
			emp_setApellido(auxEmpleado,apellido) ||
			emp_setIdEmpleado(auxEmpleado,idEmpleado) ||
			emp_setSector(auxEmpleado,sector) ||
			emp_setSalario(auxEmpleado,salario))
		{
			emp_delete(auxEmpleado);
			auxEmpleado = NULL;
		}
	}
	return auxEmpleado;
}

int emp_delete(Empleado* this)
{
	int retorno=-1;
	if(this != NULL)
	{
		free(this);
		retorno=0;
	}
	return retorno;
}

int emp_setNombre(Empleado* this,char* nombre)//EL SET ES EL UNICO QUE ACCEDE AL CAMPO PARA ESCRIBIRLO--TIENE QUE RECIBIR EL PUNTERO A UN EMPLEADO(CONTEXTO)
{
	int retorno=-1;
	if(this != NULL && nombre != NULL && isValidNombre(nombre))
	{
		strcpy(this->nombre,nombre);
		retorno=0;
	}
	return retorno;
}
char* emp_getNombre(Empleado* this,int* flagError)//EL GET ES EL UNICO QUE ACCESE AL CAMPO PARA LEERLO				PARA ACCEDER AL CAMPO, LLAMAR A ESTAS FUNCIONES (GET-SET)
{
	*flagError=-1;
	char* aux=NULL;
		if(this != NULL && flagError != NULL)
		{
			aux=this->nombre;
			*flagError=0;
		}
		return aux;
}
int isValidNombre(char* nombre)
{

	return 1;
}

int emp_setApellido(Empleado* this,char* apellido)
{
	int retorno=-1;
	if(this != NULL && apellido != NULL && isValidApellido(apellido))
	{
		strcpy(this->apellido,apellido);
		retorno=0;
	}
	return retorno;
}

char* emp_getApellido(Empleado* this,int* flagError)
{
	*flagError=-1;
	char* aux=NULL;
		if(this != NULL && flagError != NULL)
		{
			aux=this->apellido;
			*flagError=0;
		}
		return aux;
}
int isValidApellido(char* apellido)
{
	return 1;
}

int emp_setIdEmpleado(Empleado* this,int idEmpleado)
{
	int retorno=-1;
	if(this != NULL && isValidIdEmpleado(idEmpleado))
	{
		this->idEmpleado=idEmpleado;
		retorno=0;
	}
	return retorno;
}
int emp_getIdEmpleado(Empleado* this,int* flagError)
{
	*flagError=-1;
	int auxId=-1;
		if(this != NULL && flagError != NULL)
		{
			auxId=this->idEmpleado;
			*flagError=0;
		}
		return auxId;
}
int isValidIdEmpleado(int idEmpleado)
{
	return 1;
}

int emp_setSector(Empleado* this,int sector)
{
	int retorno=-1;
	if(this != NULL && isValidSector(sector))
	{
		this->sector=sector;
		retorno=0;
	}
	return retorno;
}
int emp_getSector(Empleado* this,int* flagError)
{
	*flagError=-1;
	int auxSector;
		if(this != NULL && flagError != NULL)
		{
			auxSector=this->sector;
			*flagError=0;
		}
		return auxSector;
}
int isValidSector(int sector)
{
	return 1;
}

int emp_setSalario(Empleado* this,float salario)
{
	int retorno=-1;
	if(this != NULL && isValidSalario(salario))
	{
		this->salario=salario;
		retorno=0;
	}
	return retorno;
}
float emp_getSalario(Empleado* this,int* flagError)
{
	*flagError=-1;
	float auxSalario;
		if(this != NULL && flagError != NULL)
		{
			auxSalario=this->salario;
			*flagError=0;
		}
		return auxSalario;
}
int isValidSalario(int salario)
{
	return 1;
}
//**************************************************************************
int emp_initArray(Empleado* arrayEmpleados[],int limiteArray) //RECIBO ARRAY DE EMPLEADOS--- O Empleado** arrayEmpleados
{
	int retorno=-1;
	int i;
	if(arrayEmpleados != NULL && limiteArray > 0)
	{
		retorno=0;
		for(i=0;i<limiteArray;i++)
		{
			arrayEmpleados[i]=NULL;//0
		}
	}
	return retorno;
}
int emp_buscarIndiceVacio(Empleado* arrayEmpleados[],int limiteArray)
{
	int retorno=-2;
	int i;
	if(arrayEmpleados != NULL && limiteArray > 0)
	{
		retorno=-1;
		for(i=0;i<limiteArray;i++)
		{
			if(arrayEmpleados[i]==NULL)//0
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int emp_generarId(void)
{
	static int contador=0;
	contador++;
	return contador;
}

int emp_altaEmpleado(Empleado* arrayEmpleados[],int limiteArray)
{
	int retorno=-1;
	char nombre[15];
	char apellido[15];
	float salario;
	int sector;
	int idGenerado;
	int indiceLibre=emp_buscarIndiceVacio(arrayEmpleados,limiteArray);//BUSCO EL INDICE LIBRE
	if(indiceLibre >= 0)
	{
		if(get_name(nombre,15,"Ingrese nombre:\n","Nombre incorrecto.\n",2)==1)
		{
			if(get_name(apellido,15,"Ingrese apellido:\n","Apellido Incorrecto.\n",2) &&
				get_int(&sector, 3, "Ingrese numero del sector:\n", "Sector inexistente.\n", 1, 10, 2, 0) &&
				get_float(&salario, 7, "Ingrese salario:\n", "El salario es incorrecto.\n", 1, 100000, 2, 0))
			{
					idGenerado=emp_generarId();//GENERO EL ID UNICO
					arrayEmpleados[indiceLibre]=emp_newParam(nombre, apellido,idGenerado,sector,salario);//CONSTRUYO EL ESPACIO DE MEMORIA Y LO CARGO AL ARRAY
					if(arrayEmpleados[indiceLibre] != NULL)
					{
						printf("Alta realizada correctamente -> ID:%d\n",idGenerado);
						retorno=0;
					}
			}
		}
	}
	else
	{
		printf("No hay mas lugar.\n");
	}
return retorno;
}
//-------------------------------
void emp_altaForzadaEmpleado(Empleado* empleados[],int len)
{
	Empleado* pEmp;
	int idEmpleado;
	int i;
	for(i=0; i<10; i++)
	{
		idEmpleado = emp_generarId();
		pEmp = emp_newParam("Jose-","Perez-",idEmpleado,7,1500.35);
		empleados[i] = pEmp;
	}
}
//-------------------------------
int emp_listarEmpleados(Empleado* arrayEmpleados[],int limiteArray)
{
	int retorno=-2;
	int i;
	int flagError;
	if(arrayEmpleados != NULL && limiteArray > 0)
	{
		retorno=-1;
		for(i=0;i<limiteArray;i++)
		{
			if(arrayEmpleados[i]!=NULL)//0
			{
				printf("ID:%d---Nombre:%s---Apellido:%s----Sector:%d---Salario:%.2f\n",emp_getIdEmpleado(arrayEmpleados[i], &flagError)
																	,emp_getNombre(arrayEmpleados[i],&flagError),
																	emp_getApellido(arrayEmpleados[i],&flagError),
																	emp_getSector(arrayEmpleados[i],&flagError),
																	emp_getSalario(arrayEmpleados[i],&flagError)); // empleados[i]->nombre
			}
		}
	}
	return retorno;
}

Empleado* emp_buscarPorId(Empleado* empleados[],int len, int id)
{
	Empleado* ret=NULL;
	int i;
	int flagError;
	int idItem;
	for(i=0; i<len; i++)
	{
		if(empleados[i]!=NULL)
		{
			idItem = emp_getIdEmpleado(empleados[i],&flagError);
			if(flagError==0)
			{
				if(idItem==id)
				{
					// Lo encontre!
					ret = empleados[i];
					break;
				}
			}
		}
	}
	return ret;
}
int emp_buscarPorId2(Empleado* empleados[],int len, int id)
{
	int ret=-1;
	int i;
	int flagError;
	int idItem;
	for(i=0; i<len; i++)
	{
		if(empleados[i] != NULL)
		{
			idItem = emp_getIdEmpleado(empleados[i],&flagError);
			if(flagError==0)
			{
				if(idItem==id)
				{
					ret = i;
					break;
				}
			}
		}
	}
	return ret;
}

int emp_modificarEmpleado(Empleado* arrayEmpleados[],int limiteArray)
{
	int retorno=-1;
	int auxId;
	int indiceEncontrado;
	char auxNombre[15];
	char auxApellido[15];
	int auxSector;
	float auxSalario;
	if(arrayEmpleados != NULL && limiteArray > 0)
	{
		if(get_int(&auxId, 4, "Ingrese un ID:\n", "Error\n", 1, 1000, 2, 0))
		{
			indiceEncontrado=emp_buscarPorId2(arrayEmpleados, limiteArray, auxId);
			if(indiceEncontrado >= 0)
			{
				if( get_name(auxNombre, 15, "Ingrese el nuevo nombre:\n", "Error.\n", 2) &&
					get_name(auxApellido, 15, "Ingrese el nuevo apellido:\n", "Error.\n", 2) &&
					get_int(&auxSector, 3, "Ingrese numero del sector:\n", "Sector inexistente", 1, 10, 2, 0) &&
					get_float(&auxSalario, 7, "Ingrese salario:\n", "El salario es incorrecto.\n", 1, 100000, 2, 0))
				{
					if(emp_setNombre(arrayEmpleados[indiceEncontrado],auxNombre)==0 &&
					   emp_setApellido(arrayEmpleados[indiceEncontrado],auxApellido)==0 &&
					   emp_setSector(arrayEmpleados[indiceEncontrado],auxSector)==0 &&
					   emp_setSalario(arrayEmpleados[indiceEncontrado],auxSalario)==0)
					{
						printf("Modificacion realizada con exito.\n");
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
int emp_eliminarEmpleado(Empleado* arrayEmpleados[],int limiteArray)
{
	int retorno=-1;
	int auxId;
	int indiceEncontrado;
	if(arrayEmpleados != NULL && limiteArray > 0)
	{
		if(get_int(&auxId, 4, "Ingrese un ID:\n", "Error\n", 1, 1000, 2, 0))
		{
			indiceEncontrado=emp_buscarPorId2(arrayEmpleados, limiteArray, auxId);
			if(indiceEncontrado >= 0)
			{
				emp_delete(arrayEmpleados[indiceEncontrado]);
				arrayEmpleados[indiceEncontrado]=NULL;
				printf("Baja realizada correctamente.\n");
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

int emp_subMenu(Empleado* arrayEmpleados[],int limiteArray)
{
	int retorno=-1;
	int opcionSubmenu;
	if(arrayEmpleados != NULL && limiteArray > 0)
	{
		do{

		if(get_int(&opcionSubmenu, 3, "||| SUBMENU |||\n"
									"1)Listado de los empleados ordenados alfabéticamente por Apellido y Sector.\n"
									"2)Total y promedio de los salarios, y cuántos empleados superan el salario promedio.\n"
									"3)Regresar al menu principal.\n","Opcion Incorrecta.\n",1,3,2,0))
		{
			switch(opcionSubmenu)
			{
				case 1:
					emp_listadoOrdenado(arrayEmpleados,limiteArray);
					break;
				case 2:
					emp_informeSobreSalarios(arrayEmpleados,limiteArray);
					break;
			}
		}
		}while(opcionSubmenu != 3);
	}
	return retorno;
}

void emp_informeSobreSalarios(Empleado* arrayEmpleados[], int limiteArray)
{
	int i;
	int contadorSueldos = 0;
	float acumuladorSueldos = 0;
	float promedioSueldos;
	float auxSalario;
	int contadorSueldosMayoresAlPromedio = 0;
	int flagError;
	for(i=0;i<limiteArray;i++)
	{
		auxSalario=emp_getSalario(arrayEmpleados[i],&flagError);
		if(arrayEmpleados[i] != NULL)
		{
			acumuladorSueldos = acumuladorSueldos + auxSalario;
			contadorSueldos++;
		}
	}
	promedioSueldos = acumuladorSueldos/contadorSueldos;
	for(i=0;i<limiteArray;i++)
	{
		auxSalario=emp_getSalario(arrayEmpleados[i],&flagError);

		if(arrayEmpleados[i] != NULL && auxSalario > promedioSueldos)
		{
			contadorSueldosMayoresAlPromedio++;
		}
	}
	if(contadorSueldos > 0)
	{
		printf("\nEl total de sueldos es: $ %.2f \n",acumuladorSueldos);
		printf("\nEl sueldo promedio: $ %.2f \n",promedioSueldos);
		printf("\nLa cantidad de sueldos mayores al promedio es: %d\n",contadorSueldosMayoresAlPromedio);
	}
}
int emp_listadoOrdenado(Empleado* arrayEmpleados[], int limiteArray)
{
	int retorno = -1;
	Empleado* listadoOrdenado[limiteArray];
	int i;
	int j;
	int flagError;
	int flagNoEstaOrdenado = -1;
	if(arrayEmpleados != NULL && limiteArray > 0)
	{
		retorno = 0;
		for(i=0;i<limiteArray;i++)
		{
			listadoOrdenado[i] = arrayEmpleados[i];
		}
		Empleado* buffer;
		while(flagNoEstaOrdenado==-1)
		{
			flagNoEstaOrdenado = 1;
			for(j=1;j<limiteArray;j++)
			{
				if(listadoOrdenado[j] != NULL && listadoOrdenado[j-1] != NULL)
				{
					if(strcmp(emp_getApellido(listadoOrdenado[j],&flagError),emp_getApellido(listadoOrdenado[j-1],&flagError)) < 0)
					{

						buffer = listadoOrdenado[j];
						listadoOrdenado[j] = listadoOrdenado[j-1];
						listadoOrdenado[j-1] = buffer;
						flagNoEstaOrdenado = 0;
					}
					if(strcmp(emp_getApellido(listadoOrdenado[j],&flagError),emp_getApellido(listadoOrdenado[j-1],&flagError)) == 0 &&
							emp_getSector(listadoOrdenado[j],&flagError) < emp_getSector(listadoOrdenado[j-1],&flagError))
					{
						buffer = listadoOrdenado[j];
						listadoOrdenado[j] = listadoOrdenado[j-1];
						listadoOrdenado[j-1] = buffer;
						flagNoEstaOrdenado = 0;
					}
				}
			}
		}
		if(flagNoEstaOrdenado == 0)
		{
			emp_listarEmpleados(listadoOrdenado, limiteArray);
		}
		else
		{
			printf("No se pudo ordenar.\n");
		}
	}
	return retorno;
}
