/*
 ============================================================================
 Author      : Sanjurjo Gabriel Alejandro
 Description : Trabajo practico numero 2
 ============================================================================
 */
#include "ArrayEmployees.h"
#include <stdio_ext.h>
#include <string.h>

/** \brief  This function returns a auto increased id
 * \return int > 0
 */
int generateId(void)
{
	static int id = 0;
	id++;
	return id;
}


/** \brief  To indicate that all position in the array are empty,
 *          this function put the flag (isEmpty) in TRUE in all
 *          position of the array
 * \param list Employee* Pointer to array of employees
 * \param len int Array length
 * \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
 *
 */
int initEmployees(Employee* list, int len)
{
	int retorno = -1;
	int i;
	if(len>0 && list!=NULL){
		retorno = 0;
		for(i=0;i<len;i++){
			list[i].isEmpty=TRUE;
		}
	}
	return retorno;
}

/** \brief add in a existing list of employees the values received as parameters
 *     in the first empty position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
 *
 */
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	int i;
	if(len>0 && list!=NULL){
		for(i=0;i<len;i++){
			if(list[i].isEmpty == TRUE){
				break;
			}
		}
		if(i>=0 && i<len){
			retorno = 0;
			list[i].id = id;
			strncpy(list[i].name, name, 51);
			strncpy(list[i].lastName, lastName, 51);
			list[i].salary = salary;
			list[i].sector = sector;
			list[i].isEmpty = FALSE;
		}
	}
return retorno;
}

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/
int findEmployeeById(Employee* list, int len,int id)
{
	int retorno = -1;
	int i;
	if(list!=NULL && len>0){
		for(i=0;i<len;i++){
			if(list[i].isEmpty == FALSE && list[i].id==id){
				retorno = i;
			}
		}
	}
	return retorno;
}

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/
int removeEmployee(Employee* list, int len, int id)
{
	int retorno = -1;
	int index;
	if(len>0 && list!=NULL){
		index=findEmployeeById(list, len, id);
		if(index>=0){
			retorno = 0;
			list[index].isEmpty = TRUE;
		}
	}
	return retorno;
}

/** \brief modify in a existing list of employees the values received as parameters
 *     in the id position
 * \param list employee*
 * \param len int
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or without correct id] - (0) if Ok
 *
 */
int modifyEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
	int retorno = -1;
	int index;
	if(len>0 && list!=NULL){
		index = findEmployeeById(list, len, id);
		if(index!=-1){
			retorno = 0;
			list[index].id = id;
			strncpy(list[index].name, name, 51);
			strncpy(list[index].lastName, lastName, 51);
			list[index].salary = salary;
			list[index].sector = sector;
			list[index].isEmpty = FALSE;
		}
	}
return retorno;
}

/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortEmployees(Employee* list, int len, int order)
{
	int retorno = -1;
	int i;
	int j;
	int flagOrdeno;
	Employee swap;

	if(list!=NULL && len>0 && (order == 1 || order == 0))
	{
		retorno = 0;
		for(i=1; i<len; i++){
			j=i;
			flagOrdeno = 1;
			while(flagOrdeno != 0 && j!=0){
				flagOrdeno = 0;

				if((order && ((list[j-1].isEmpty == TRUE && list[j].isEmpty == FALSE) ||
							(strncmp(list[j-1].lastName, list[j].lastName,51)>0) ||
							(strncmp(list[j-1].lastName, list[j].lastName,51)==0 && list[j-1].sector > list[j].sector)))
						||
				   (!order && ((list[j-1].isEmpty == TRUE && list[j].isEmpty == FALSE) ||
							(strncmp(list[j-1].lastName, list[j].lastName,51)<0) ||
							(strncmp(list[j-1].lastName, list[j].lastName,51)==0 && list[j-1].sector < list[j].sector)))

				){
					swap = list[j-1];
					list[j-1] = list[j];
					list[j] = swap;
					flagOrdeno = 1;
				}
				j--;
			}
		}
	}
	return retorno;
}

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printEmployees(Employee* list, int length)
{
	int retorno = -1;
	int i;
	if(list!=NULL && length>0){
		retorno = 0;
		for(i=0;i<length;i++){
			if(list[i].isEmpty == FALSE)
			{
				printf("%d  -  %s  -  %s  -  %f  -  %d\n"
						,list[i].id,list[i].name,list[i].lastName,list[i].salary,list[i].sector);
			}
		}
	}
	return retorno;
}

/** \brief print total and average of employees salary
*
* \param list Employee*
* \param length int
* \return int
*
*/
int printAverageEmployees(Employee* list, int length)
{
	int retorno = -1;
	int i;
	float total=0;
	int contador=0;
	int contadorMayoresPromedio=0;
	float promedio=0;
	if(list!=NULL && length>0){
		retorno = 0;
		for(i=0;i<length;i++){
			if(list[i].isEmpty == FALSE){
				contador++;
				total += list[i].salary;
			}
		}
		promedio = total / contador;
		for(i=0;i<length;i++){
			if(list[i].isEmpty == FALSE && list[i].salary>promedio){
				contadorMayoresPromedio++;
			}
		}
		printf("Con un total de %d empleados, con un monto total de $%f y un promedio de $%f,"
				" hay un total de %d trabajadores que superan el promedio.\n"
				,contador,total,promedio,contadorMayoresPromedio);

	}
	return retorno;
}

/** \brief calculate the number of employees
*
* \param list Employee*
* \param length int
* \return int
*
*/
int qtyEmployee(Employee* list, int length){
	int retorno = -1;
	int i;
	int contador = 0;
	if(list != NULL && length > 0){
		for(i=0;i<length;i++){
			if(list[i].isEmpty == FALSE){
				contador++;
			}
		}
		retorno = contador;
	}
	return retorno;
}
