/*
 * empleado.h
 *
 *  Created on: May 11, 2021
 *      Author: Stefano
 */

#ifndef EMPLEADO_H_
#define EMPLEADO_H_

typedef struct{
	char nombre[50];
	char apellido[50];
	int sector;
	float salario;
	int idEmpleado;
}Empleado;

Empleado* emp_new(void); //CONSTRUCTOR --- crea espacio
Empleado* emp_newParam(char* nombre,char* apellido,int idEmpleado,int sector,float salario);//COPIAR Y PEGAR LOS CAMPOS DE LA STRUCT
int emp_delete(Empleado* this); //DECONSTRUCTOR

int emp_setNombre(Empleado* this,char* nombre);//EL SET ES EL UNICO QUE ACCEDE AL CAMPO PARA ESCRIBIRLO--TIENE QUE RECIBIR EL PUNTERO A UN EMPLEADO(CONTEXTO)
char* emp_getNombre(Empleado* this,int* flagError);//EL GET ES EL UNICO QUE ACCESE AL CAMPO PARA LEERLO				PARA ACCEDER AL CAMPO, LLAMAR A ESTAS FUNCIONES (GET-SET)
int isValidNombre(char* nombre);

int emp_setApellido(Empleado* this,char* apellido);
char* emp_getApellido(Empleado* this,int* flagError);
int isValidApellido(char* apellido);

int emp_setIdEmpleado(Empleado* this,int idEmpleado);
int emp_getIdEmpleado(Empleado* this,int* flagError);
int isValidIdEmpleado(int id);

int emp_setSector(Empleado* this,int sector);
int emp_getSector(Empleado* this,int* flagError);
int isValidSector(int sector);

int emp_setSalario(Empleado* this,float salario);
float emp_getSalario(Empleado* this,int* flagError);
int isValidSalario(int salario);





int emp_initArray(Empleado* arrayEmpleados[],int limiteArray);
int emp_buscarIndiceVacio(Empleado* arrayEmpleados[],int limiteArray);
int emp_generarId(void);
int emp_altaEmpleado(Empleado* arrayEmpleados[],int limiteArray);
void emp_altaForzadaEmpleado(Empleado* empleados[],int len);
int emp_modificarEmpleado(Empleado* arrayEmpleados[],int limiteArray);
int emp_eliminarEmpleado(Empleado* arrayEmpleados[],int limiteArray);
Empleado* emp_buscarPorId(Empleado* empleados[],int len, int id);
int emp_buscarPorId2(Empleado* empleados[],int len, int id);
int emp_listarEmpleados(Empleado* arrayEmpleados[],int limiteArray);
int emp_subMenu(Empleado* arrayEmpleados[],int limiteArray);
int emp_listadoOrdenado(Empleado* arrayEmpleados[],int limiteArray);
void emp_informeSobreSalarios(Empleado* arrayEmpleados[], int limiteArray);

//GET Y SET SIEMPRE RECIBEN EL CONTEXTO(ENTIDAD)

#endif /* EMPLEADO_H_ */
