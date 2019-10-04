/*
 ============================================================================
 Author      : Sanjurjo Gabriel Alejandro
 Description : Trabajo practico numero 2
 ============================================================================
 */
#include "utn.h"
#include "abmUI.h"
#include "ArrayEmployees.h"




/** \brief user interface add employee
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or len<=0] - (0) if Ok
 *
 */
int alta(Employee *list, int len)
{
	Employee bEmployee;
	int step = 1;
	int retorno = -1;
	if(list!=NULL && len>0)
	{
		do
		{
			switch(step)
			{
			case -1:
				printf("Alta abortada por mal ingreso de datos\n");
				step = 8;
				break;
			case 1:
				if(getString(bEmployee.name,"Ingrese el nombre\n", "Error\n", 1, 50,5)==-1){
					step = -1;
				}else{
					step++;
				}
				break;
			case 2:
				if(getString(bEmployee.lastName,"Ingrese el apellido\n", "Error\n", 1, 50,5)==-1){
					step = -1;
				}else{
					step++;
				}
				break;
			case 3:
				if(getFloat(&bEmployee.salary,"Ingrese el salario\n", "Error\n", 0, 1000000,5)==-1){
					step = -1;
				}else{
					step++;
				}
				break;
			case 4:
				if(getInt(&bEmployee.sector,"Ingrese el sector\n", "Error\n", 0, 1000000,5)==-1){
					step = -1;
				}else{
					step++;
				}
				break;
			case 5:
				bEmployee.id = generateId();
				if(addEmployee(list, len, bEmployee.id, bEmployee.name, bEmployee.lastName, bEmployee.salary, bEmployee.sector)==-1)
				{
					printf("Error al dar de alta\n");
				}else{
					printf("Alta exitosa\n");
					retorno = 0;
				}
				step=8;
			}
		}while(step!=8);
	}
	return retorno;
}

/** \brief user interface remove employee
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or len<=0] - (0) if Ok
 *
 */
int baja(Employee *list, int len)
{
	int id;
	int retorno = -1;
	if(list!=NULL && len>0)
	{
		if(getInt(&id, "Ingrese el id a dar de baja.\n", "Error\n", 0, 1000000,5)!=-1){
			if(removeEmployee(list, len, id)==-1){
				printf("La baja no se pudo llevar a cabo.\n");
			}else{
				printf("Baja exitosa\n");
			}
		}else{
			printf("Operacion abortada por ingreso erroneo.\n");
		}
	}
	return retorno;
}

/** \brief user interface modify employee
 * \param list employee*
 * \param len int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or len<=0] - (0) if Ok
 *
 */
int modificacion(Employee *list, int len)
{
	Employee bEmployee;
	int step = 1;
	int id;
	int retorno = -1;
	int index;
	if(list!=NULL && len>0)
	{
		if(getInt(&id, "Ingrese el id a modificar.\n", "Error\n", 0, 1000000,5)!=-1){

			index = findEmployeeById(list, len, id);
			if(index != -1){
				bEmployee = list[index];
				do
				{

					printf("1. Modificar nombre\n"
							"2. Modificar apellido\n"
							"3. Modificar salario\n"
							"4. Modificar sector\n"
							"5. Guardar modificaciones\n"
							"6. Cancelar modificaciones\n");
					getInt(&step, "Ingrese el id a modificar.\n", "Error\n", 1, 6,5);

					switch(step)
					{
					case 1:
						printf("Nombre anterior: %s\n",bEmployee.name);
						if(getString(bEmployee.name,"Ingrese el nombre\n", "Error\n", 1, 50,5)==-1){
							step = -1;
						}break;
					case 2:
						printf("Apellido anterior: %s\n",bEmployee.lastName);
						if(getString(bEmployee.lastName,"Ingrese el apellido\n", "Error\n", 1, 50,5)==-1){
							step = -1;
						}
						break;
					case 3:
						printf("Salario anterior: %f\n",bEmployee.salary);
						if(getFloat(&bEmployee.salary,"Ingrese el salario\n", "Error\n", 0, 1000000,5)==-1){
							step = -1;
						}
						break;
					case 4:
						printf("Sector anterior: %d\n",bEmployee.sector);
						if(getInt(&bEmployee.sector,"Ingrese el sector\n", "Error\n", 0, 1000000,5)==-1){
							step = -1;
						}
						break;
					case 5:
						printf("Salary: %f",bEmployee.salary);
						if(modifyEmployee(list, len, bEmployee.id, bEmployee.name, bEmployee.lastName, bEmployee.salary, bEmployee.sector)==-1)
						{
							printf("Error en la modificacion\n");
						}else{
							printf("Modificacion exitosa\n");
							retorno = 0;
						}
						step=6;
					}
					if(step == -1){
						printf("Modificacion abortada por mal ingreso de datos\n");
						step = 6;
					}

				}while(step!=6);
			}
		}else{
			printf("Ingreso erroneo del id\n");
		}
	}
	return retorno;
}

