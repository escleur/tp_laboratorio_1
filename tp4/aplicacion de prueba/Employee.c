#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Employee.h"
#include "utn.h"
#include "LinkedList.h"

static int isValidNombre(char* nombre);
static int isValidHorasTrabajadas(int horasTrabajadas);
static int isValidSueldo(int sueldo);



/** \brief Crea un nuevo empleado
 *
 * \return Employee*
 *
 */
Employee* employee_new()
{
	return (Employee*)malloc(sizeof(Employee));
}

/** \brief Crea un nuevo empleado con los parametros recibidos
 *
 * \param idStr char*
 * \param nombreStr char*
 * \param horasTrabajadasStr char*
 * \param sueldoStr char*
 * \return Employee*
 *
 */
Employee* employee_newParametros(char* idStr,char* nombreStr,char* horasTrabajadasStr, char* sueldoStr)
{
	Employee* retorno = NULL;
	Employee* this;
	this = employee_new();
	if(		this!=NULL &&
			employee_setId(this, atoi(idStr))!=-1 &&
			employee_setNombre(this, nombreStr)!=-1 &&
			employee_setHorasTrabajadas(this, atoi(horasTrabajadasStr))!=-1 &&
			employee_setSueldo(this, atoi(sueldoStr))!=-1
			){
		retorno = this;
	}else{
		employee_delete(this);
	}
	return retorno;
}

/** \brief Elimina un empleado
 *
 * \param this Employee*
 *
 */
void employee_delete(Employee* this)
{
	free(this);
}

/** \brief asigna el id, lleva cuenta del id maximo y si se ingresa un numero negativo devuelve maximo+1
 *
 * \param this Employee*
 * \param id int
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int employee_setId(Employee* this, int id)
{
	int retorno = -1;
	static int maximoId = -1;
	if(this != NULL)
	{
		retorno = 0;
		if(id < 0)
		{
			maximoId++;
			this->id = maximoId;
		}
		else
		{
			if(id > maximoId)
			{
				maximoId = id;
			}
			this->id = id;
		}
	}
	return retorno;
}


/** \brief devuelve el id de un empleado en parametro id
 *
 * \param this Employee*
 * \param id int*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int employee_getId(Employee* this,int* id)
{
	int retorno = -1;
	if(this!=NULL && id!=NULL)
	{
		retorno = 0;
		*id = this->id;
	}
	return retorno;
}

/** \brief asigna el nombre de un empleado
 *
 * \param this Employee*
 * \param nombre char*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int employee_setNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && isValidNombre(nombre)){
		retorno = 0;
		strncpy(this->nombre, nombre,128);
	}
	return retorno;
}

/** \brief devuelve el nombre de un empleado en parametro nombre
 *
 * \param this Employee*
 * \param nombre char*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int employee_getNombre(Employee* this,char* nombre)
{
	int retorno = -1;
	if(this!=NULL && nombre!=NULL)
	{
		retorno = 0;
		strncpy(nombre, this->nombre,128);
	}
	return retorno;
}

/** \brief verifica si es un nombre valido
 *
 * \param nombre char*
 * \return retorna 0 si no es nombre valido y 1 si lo es
 *
 */
static int isValidNombre(char* nombre)
{
	int retorno = 0;
	if(chequear(nombre, 1, 0, " ") && strlen(nombre)<127)
	{
		retorno = 1;
	}
	return retorno;
}

/** \brief asigna las horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int employee_setHorasTrabajadas(Employee* this,int horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && isValidHorasTrabajadas(horasTrabajadas)){
		this->horasTrabajadas = horasTrabajadas;
		retorno = 0;
	}
	return retorno;
}

/** \brief devuelve las horas trabajadas de un empleado
 *
 * \param this Employee*
 * \param horasTrabajadas int*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int employee_getHorasTrabajadas(Employee* this,int* horasTrabajadas)
{
	int retorno = -1;
	if(this!=NULL && horasTrabajadas!=NULL)
	{
		retorno = 0;
		*horasTrabajadas = this->horasTrabajadas;
	}
	return retorno;
}

/** \brief verifica si horas trabajadas es valido
 *
 * \param horasTrabajadas int
 * \return retorna 0 si no es valido y 1 si lo es
 *
 */
static int isValidHorasTrabajadas(int horasTrabajadas)
{
	int retorno = 0;
	if(horasTrabajadas >= 0){
		retorno = 1;
	}
	return retorno;
}

/** \brief asigna el sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int employee_setSueldo(Employee* this,int sueldo)
{
	int retorno = -1;
	if(this!=NULL && isValidSueldo(sueldo)){
		this->sueldo = sueldo;
		retorno = 0;
	}
	return retorno;
}

/** \brief devuelve el sueldo de un empleado
 *
 * \param this Employee*
 * \param sueldo int*
 * \return retorna -1 si this es null o 0 en caso de exito
 *
 */
int employee_getSueldo(Employee* this,int* sueldo)
{
	int retorno = -1;
	if(this!=NULL && sueldo!=NULL)
	{
		retorno = 0;
		*sueldo = this->sueldo;
	}
	return retorno;
}

/** \brief verifica si sueldo es valido
 *
 * \param sueldo int
 * \return retorna 0 si no es valido y 1 si lo es
 *
 */
static int isValidSueldo(int sueldo)
{
	int retorno = 0;
	if(sueldo >= 0){
		retorno = 1;
	}
	return retorno;
}

/** \brief compara dos empleados por nombre
 *
 * \param e1 void*
 * \param e2 void*
 * \return retorna 0 si son iguales 1 si el primero es mayor y -1 si el segundo es mayor
 *
 */
int compararPorNombre(void* e1, void* e2){
	int retorno;
	Employee* empleado1 = (Employee*)e1;
	Employee* empleado2 = (Employee*)e2;

	char nombre1[128];
	char nombre2[128];

	employee_getNombre(empleado1, nombre1);
	employee_getNombre(empleado2, nombre2);
	if(strncmp(nombre1,nombre2,128)>0){
		retorno = 1;
	}else if(strncmp(nombre1,nombre2,128)<0){
		retorno = -1;
	}else{
		retorno = 0;
	}
	return retorno;
}

