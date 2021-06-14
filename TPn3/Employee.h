#ifndef EMPLOYEE_H_INCLUDED
#define EMPLOYEE_H_INCLUDED
#include "LinkedList.h"
typedef struct
{
    int id;
    char nombre[128];
    int sueldo;
    int horasTrabajadas;

}Employee;

Employee* employee_new(void);
Employee* employee_newParamTxt(char* idStr,char* nombreStr,char* horasTrabajadasStr,char* sueldoStr);//setters validan datos razonables
void employee_delete();

Employee* employee_newParametros(int id,char* nombreStr,int horasTrabajadas,int sueldo); //Func aux

int employee_setId(Employee* this,int id);
int employee_getId(Employee* this,int* id);

int employee_setNombre(Employee* this,char* nombre);
int employee_getNombre(Employee* this,char* nombre);
int isValidNombre(char* nombre);

int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas);
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas);

int employee_setSueldo(Employee* this,int sueldo);
int employee_getSueldo(Employee* this,int* sueldo);

int employee_setHorasTrabajadasTxt(Employee* this,char* horasTrabajadasTxt);
int isValidHorasTrabajadasTxt(char* horasTrabajadasTxt);

int employee_setSueldoTxt(Employee* this,char* sueldoTxt);
int isValidSueldoTxt(char* sueldoTxt);

int employee_setIdEmpleadoTxt(Employee* this,char* idEmpleadoTxt);
int isValidIdEmpleadoTxt(char* idEmpleadoTxt);

int employee_generarId(void);
void employee_marcarIdMax(int idMax);

int employee_pedirDatos(char* nombre, int* horasTrabajadas, int* sueldo);

int employee_ordenarPorSueldo(void* item1,void* item2);

//***EXTRAS***
int employee_buscarIndicePorId(LinkedList* pArrayListEmployee,int idPedido);
Employee* employee_buscarEmpPorId(LinkedList* pArrayListEmployee,int idPedido);
#endif // employee_H_INCLUDED
