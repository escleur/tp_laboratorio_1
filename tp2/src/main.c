/*
 ============================================================================
 Author      : Sanjurjo Gabriel Alejandro
 Description : Trabajo practico numero 2
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include "abmUI.h"
#include "utn.h"
#include "ArrayEmployees.h"

#define QTY_EMPLOYEE 1000
int main(void) {

	Employee aEmployee[QTY_EMPLOYEE];
	initEmployees(aEmployee ,QTY_EMPLOYEE);
	int cantidad;
	int opcionMenu;
	do{
		cantidad = qtyEmployee(aEmployee, QTY_EMPLOYEE);
		if(cantidad == 0){
			printf( "1. Altas\n"
				"5. Salir\n"
				);

		}else{
			printf( "1. Altas\n"
				"2. Modificar\n"
				"3. Baja\n"
				"4. Informar\n"
				"5. Salir\n"
				);
		}

		getInt(&opcionMenu,"Elija una opcion:\n","Error\n",1,5,10);

		switch(opcionMenu){
		case 1:
			alta(aEmployee, QTY_EMPLOYEE);
			break;
		case 2:
			if(cantidad!=0){
				modificacion(aEmployee, QTY_EMPLOYEE);
			}
			break;
		case 3:
			if(cantidad!=0){
				baja(aEmployee, QTY_EMPLOYEE);
			}
			break;
		case 4:
			if(cantidad!=0){
				printf("1. Listado de los empleados ordenado alfabeticamente por Apellido y Sector\n"
						"2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio\n");
				getInt(&opcionMenu,"Elija una opcion:\n","Error\n",1,5,10);
				switch(opcionMenu){
				case 1:
					sortEmployees(aEmployee, QTY_EMPLOYEE, 1);
					printEmployees(aEmployee, QTY_EMPLOYEE);
					break;
				case 2:
					printAverageEmployees(aEmployee, QTY_EMPLOYEE);
					break;
				}
			}
		}
	}while(opcionMenu!=5);
	return EXIT_SUCCESS;
}
