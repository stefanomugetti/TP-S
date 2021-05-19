/*
 ============================================================================
 Name        : TPdoss.c
 Author      : Stefano
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "Empleado.h"
#include "utn.h"
#define CANT_EMPLEADOS 1000
int main(void) {
	setbuf(stdout,NULL);
	int opcionMenu;
	Empleado* empleados[CANT_EMPLEADOS];

	emp_initArray(empleados, CANT_EMPLEADOS);

		do{
	if(get_int(&opcionMenu, 3, "|||  MENU   |||\n"
								"1)ALTA DE EMPLEADO\n"
								"2)MODIFICACION DE EMPLEADO\n"
								"3)BAJA DE EMPLEADO\n"
								"4)INFORME\n"
								"5)IMPRIMIR(DEBUG)\n"
								"6)SALIR\n", "Opcion Incorrecta.\n", 1, 6, 2, 0))
	{
			switch(opcionMenu)
			{
				case 1:
					emp_altaEmpleado(empleados, CANT_EMPLEADOS);
					break;
				case 2:
					emp_modificarEmpleado(empleados, CANT_EMPLEADOS);
					break;
				case 3:
					emp_eliminarEmpleado(empleados, CANT_EMPLEADOS);
					break;
				case 4:
					emp_subMenu(empleados, CANT_EMPLEADOS);
					break;
				case 5:
					emp_listarEmpleados(empleados, CANT_EMPLEADOS);
					break;
			}
	}
		}while(opcionMenu != 6);
		printf("Saliendo... Hasta luego!.");
	return EXIT_SUCCESS;
}
