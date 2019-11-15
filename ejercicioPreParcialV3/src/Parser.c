#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Empleado.h"

int parser_parseEmpleados(char* fileName, LinkedList* listaEmpleados)
{
	char id[4096];
	char nombre[4096];
	char horasTrabajadas[4096];
	char sueldo[4096];
	Empleado* buffer;
	int leidos;
	if(fileName != NULL && listaEmpleados != NULL)
	{
		FILE* pFile = fopen(fileName, "r");

		if(pFile != NULL){

			leidos = fscanf(pFile, "%s",nombre);

			while(!feof(pFile))
			{
				leidos = fscanf(pFile, "%[^,],%[^,],%[^\n]\n",id,nombre,horasTrabajadas);
				if(leidos == 4){
					buffer = employee_newParametros(id,nombre,horasTrabajadas,0);
					if(buffer != NULL)
					{
						ll_add(listaEmpleados, buffer);
					}
				}
			}
		}
		fclose(pFile);
	}
    return 1;
}

