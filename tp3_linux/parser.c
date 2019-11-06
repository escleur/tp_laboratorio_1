#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
	char id[4096];
	char nombre[4096];
	char horasTrabajadas[4096];
	char sueldo[4096];
	Employee* buffer;
	int leidos;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		leidos = fscanf(pFile, "%s",nombre);

		while(!feof(pFile))
		{
			leidos = fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas,sueldo);
			if(leidos == 4){
				buffer = employee_newParametros(id,nombre,horasTrabajadas,sueldo);
				if(buffer != NULL)
				{
					ll_add(pArrayListEmployee, buffer);
				}
			}
		}
	}
    return 1;
}

/** \brief Parsea los datos los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	Employee *buffer;
	if(pFile != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		if(pFile != NULL){
			while(!feof(pFile))
			{
				buffer = employee_new();
				if(buffer != NULL)
				{
					if(fread(buffer,sizeof(Employee),1,pFile)==1)
					{
						ll_add(pArrayListEmployee, buffer);
					}
				}

			}
			printf("archivo leido en binario\n");

		}else{
			printf("No encontro el archivo\n");
		}

	}
	return retorno;
}
