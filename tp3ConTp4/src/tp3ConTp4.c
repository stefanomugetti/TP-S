#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"
#include "utn.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).    X
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).  X
     3. Alta de empleado      X
     4. Modificar datos de empleado        X
     5. Baja de empleado      X
     6. Listar empleados      X
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).    X
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).   X
    10. Salir X
*****************************************************/



int main()
{
	setbuf(stdout,NULL);
    int option;

    LinkedList* listaEmpleados = ll_newLinkedList();

    do{
    	if(get_int(&option, 3,"\tMENU\n"
    						  "1)Cargar los datos de los empleados desde el archivo dataTexto.csv (modo texto)\n"
    						  "2)Cargar los datos de los empleados desde el archivo dataBin.csv (modo binario)\n"
    						  "3)Alta de empleado\n"
    						  "4)Modificar datos de empleado\n"
    						  "5)Baja de empleado\n"
    						  "6)Listar empleados\n"
    						  "7)Ordenar empleados\n"
    						  "8)Guardar los datos de los empleados en el archivo dataTexto.csv (modo texto)\n"
    						  "9)Guardar los datos de los empleados en el archivo dataBin.csv (modo binario)\n"
    						  "10)Salir\n", "Opcion invalida.\n", 1, 10, 2, 0))
    	{

			switch(option)
			{
				case 1:
					controller_loadFromText("C:\\Users\\Stefano\\eclipse-workspace\\tp3_windows\\data.csv",listaEmpleados);
					break;
				case 2:
					controller_loadFromBinary("C:\\Users\\Stefano\\eclipse-workspace\\tp3_windows\\databin.csv", listaEmpleados);
					break;
				case 3:
					controller_addEmployee(listaEmpleados);
					break;
				case 4:
					controller_editEmployee(listaEmpleados);
					break;
				case 5:
					controller_removeEmployee(listaEmpleados);
					break;
				case 6:
					controller_ListEmployee(listaEmpleados);
					break;
				case 7:
					controller_sortEmployee(listaEmpleados);
					break;
				case 8:
					controller_saveAsText("C:\\Users\\Stefano\\eclipse-workspace\\tp3_windows\\data.csv",listaEmpleados);
					break;
				case 9:
					controller_saveAsBinary("C:\\Users\\Stefano\\eclipse-workspace\\tp3_windows\\databin.csv", listaEmpleados);
					break;
			}
    	}
    }while(option != 10);
    return 0;
}

