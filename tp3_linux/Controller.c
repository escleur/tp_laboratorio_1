#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"

#include "parser.h"
#include "Controller.h"
#include "utn.h"


/** \brief Carga los datos de los empleados desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		FILE* pFile = fopen(path, "r");
		if(pFile != NULL){
			vaciarLLEmpleados(pArrayListEmployee);
			parser_EmployeeFromText(pFile , pArrayListEmployee);
			printf("archivo leido\n");

		}else{
			printf("No encontro el archivo\n");
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Elimina los empleados de la linkedList.
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int vaciarLLEmpleados(LinkedList* pArrayListEmployee)
{
	int retorno=-1;
	Employee* buffer;
	if(pArrayListEmployee != NULL)
	{
		retorno = 0;
		while(ll_len(pArrayListEmployee)>0)
		{
			buffer = (Employee*)ll_pop(pArrayListEmployee, 0);
			employee_delete(buffer);
		}
	}
	return retorno;
}

/** \brief Carga los datos de los empleados desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		FILE* pFile = fopen(path, "rb");
		if(pFile != NULL){
			vaciarLLEmpleados(pArrayListEmployee);
			parser_EmployeeFromBinary(pFile , pArrayListEmployee);
		}else{
			printf("No encontro el archivo\n");
		}
		fclose(pFile);
	}
	return retorno;
}

/** \brief Alta de empleados
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_addEmployee(LinkedList* pArrayListEmployee)
{
	char bufferNombre[128];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	int step = 1;
	int retorno = -1;
	Employee* this;
	printf("Alta de empleados\n");
	do
	{
		switch(step){
		case 1:
			if (getNombre(bufferNombre, "Ingrese el nombre\n", "Error", 1,
					127, 2) == -1) {
				printf("Error en el nombre\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 2:
			if (getInt(&bufferHorasTrabajadas, "Ingrese las horas trabajadas\n",
					"Error", 0, 100000, 2) == -1) {
				printf("Error al ingresar las horas trabajadas\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 3:
			if (getInt(&bufferSueldo, "Ingrese el sueldo\n", "Error", 0,
					1000000, 2) == -1) {
				printf("Error en el sueldo\n");
				step = 100;
			}
			else
			{
				step++;
			}
			break;
		case 4:
			this = employee_new();
			if(		this!=NULL &&
					employee_setId(this, -1)!=-1 &&
					employee_setNombre(this, bufferNombre)!=-1 &&
					employee_setHorasTrabajadas(this, bufferHorasTrabajadas)!=-1 &&
					employee_setSueldo(this, bufferSueldo)!=-1
					){
				ll_add(pArrayListEmployee, this);
				printf("Alta exitosa\n");
				retorno = 0;

			}else{
				employee_delete(this);
				printf("Error al hacer el alta\n");
			}
			step = 100;
			break;
		}
	}while(step!=100);
	return retorno;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_editEmployee(LinkedList* pArrayListEmployee)
{
	int step = 0;
	int retorno = -1;
	Employee* buffer;
	buffer = employee_new();
	int id;
	char nombre[128];
	int horasTrabajadas;
	int sueldo;
	int index;
	printf("Modificacion de empleados\n");
	getInt(&id,"Ingrese el id para modificar\n","Error\n",0,100000,2);
	index = employee_GetPorId(pArrayListEmployee, buffer, id);
	if (index == -1) {
		printf("Error el id no existe\n");
	}
	else
	{
		employee_getNombre(buffer,nombre);
		employee_getHorasTrabajadas(buffer,&horasTrabajadas);
		employee_getSueldo(buffer,&sueldo);

		printf("Datos a modificar :%d  %s  %d  %d\n",id,nombre,horasTrabajadas,sueldo);
		do{
			printf("1. Modificar nombre\n"
					"2. Modificar horas trabajadas\n"
					"3. Modificar sueldo\n"
					"9. Guardar\n"
					"0. Cancelar\n");
			getInt(&step, "Ingrese la opcion 0 a 9\n", "Error", 0, 9, 2);
			switch(step){
			case 0:
				printf("Cancelado por usuario\n");
				step = 99;
				break;
			case 1:
				if (getNombre(nombre, "Ingrese el nombre\n", "Error", 1,
						127, 2) == -1) {
					printf("Error en el nombre\n");
					step = 99;
				}
				break;
			case 2:
				if (getInt(&horasTrabajadas, "Ingrese la cantidad de horas trabajadas\n",
						"Error", 0, 1000000, 2) == -1) {
					printf("Error en la cantidad de horas trabajadas\n");
					step = 99;
				}
				break;
			case 3:
				if (getInt(&sueldo, "Ingrese el sueldo\n", "Error", 0,
						1000000, 2) == -1) {
					printf("Error en el sueldo\n");
					step = 99;
				}
				break;
			case 9:
				employee_setNombre(buffer,nombre);
				employee_setHorasTrabajadas(buffer,horasTrabajadas);
				employee_setSueldo(buffer,sueldo);
				employee_delete(ll_get(pArrayListEmployee, index));
				ll_set(pArrayListEmployee, index, buffer);
				printf("Modificacion exitosa\n");
				retorno = 0;
				step = 100;
				break;
			case 99:
				employee_delete(buffer);
				step = 100;
			}
		}while(step!=100);
	}
	return retorno;
}

/** \brief Busca un empleado por id.
 *
 * \param pArrayListEmployee LinkedList*
 * \param empleado Employee* retorno el elemento coincidente
 * \param id int
 * \return int (-1) si la lista es nula o no se encuentra el id (>=0)retorna el indice del elemento que coincide el id
 *
 */
int employee_GetPorId(LinkedList* pArrayListEmployee, Employee *empleado, int id)
{
	int retorno = -1;
	int i;
	Employee* buffer;
	int idBuffer;
	if(pArrayListEmployee != NULL){
		for(i=0;i<ll_len(pArrayListEmployee);i++){
			buffer = ll_get(pArrayListEmployee, i);
			employee_getId(buffer, &idBuffer);
			if(id == idBuffer){
				retorno = i;
				*empleado = *buffer;
				break;
			}
		}
	}
	return retorno;
}



/** \brief Baja de empleado
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_removeEmployee(LinkedList* pArrayListEmployee)
{
	int id;
	int retorno = -1;
	char conf;
	int index;
	Employee* buffer;
	buffer = employee_new();

	printf("Baja\n");
	getInt(&id,"Ingrese el id para dar de baja\n","Error\n",0,100000,2);
	getChar(&conf,"Ingrese s para confirmar la baja\n","Error\n",'a', 'z', 2);
	if(conf=='s'){
		index = employee_GetPorId(pArrayListEmployee, buffer, id);
		employee_delete(buffer);
		if(index != -1){
			buffer = ll_pop(pArrayListEmployee, index);
			printf("Baja exitosa\n");
			retorno = 0;
		}else{
			printf("Error al dar baja, verifique que el id existe\n");
		}
	}
	employee_delete(buffer);
	return retorno;
}

/** \brief Listar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int i;
	Employee* buffer;
	int bufferId;
	char bufferNombre[128];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	if(pArrayListEmployee != NULL)
	{
		printf("id      Nombre      Horas trabajadas     Sueldo\n");

		for(i=0;i<ll_len(pArrayListEmployee);i++)
		{
			buffer = (Employee*)ll_get(pArrayListEmployee,i);
			employee_getId(buffer, &bufferId);
			employee_getNombre(buffer, bufferNombre);
			employee_getHorasTrabajadas(buffer, &bufferHorasTrabajadas);
			employee_getSueldo(buffer, &bufferSueldo);

			printf("%d  --  %s  --  %d  --  %d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
		}
	}
    return 1;
}

/** \brief Ordenar empleados
 *
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_sortEmployee(LinkedList* pArrayListEmployee)
{
	ll_sort(pArrayListEmployee, compararPorNombre, 1);
    return 1;
}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	int bufferId;
	char bufferNombre[128];
	int bufferHorasTrabajadas;
	int bufferSueldo;
	Employee *buffer;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		FILE* pFile = fopen(path, "w");
		fprintf(pFile,"id,nombre,horasTrabajadas,sueldo\n");
		if(pFile != NULL){
			for(i=0;i<ll_len(pArrayListEmployee);i++){
				buffer = (Employee*)ll_get(pArrayListEmployee, i);
				employee_getId(buffer, &bufferId);
				employee_getNombre(buffer, bufferNombre);
				employee_getHorasTrabajadas(buffer, &bufferHorasTrabajadas);
				employee_getSueldo(buffer, &bufferSueldo);


				fprintf(pFile,"%d,%s,%d,%d\n",bufferId,bufferNombre,bufferHorasTrabajadas,bufferSueldo);
			}
			printf("archivo escrito en formato texto\n");

		}else{
			printf("No encontro el archivo\n");
		}
		fclose(pFile);
	}
	return retorno;

}

/** \brief Guarda los datos de los empleados en el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListEmployee LinkedList*
 * \return int
 *
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int retorno = -1;
	int i;
	Employee *buffer;
	if(path != NULL && pArrayListEmployee != NULL)
	{
		retorno = 0;
		FILE* pFile = fopen(path, "wb");
		if(pFile != NULL){
			for(i=0;i<ll_len(pArrayListEmployee);i++){
				buffer = (Employee*)ll_get(pArrayListEmployee, i);
				fwrite(buffer,sizeof(Employee),1,pFile);
			}
			printf("archivo escrito en binario\n");

		}else{
			printf("No encontro el archivo\n");
		}
		fclose(pFile);
	}
	return retorno;

}

