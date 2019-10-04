/*
 ============================================================================
 Author      : Sanjurjo Gabriel Alejandro
 Description : Trabajo practico numero 2
 ============================================================================
 */


#ifndef ARRAYEMPLOYEES_H_
#define ARRAYEMPLOYEES_H_
#include <stdio.h>
#include <stdlib.h>

struct {
	int id;
	char name[51];
	char lastName[51];
	float salary;
	int sector;
	int isEmpty;
} typedef Employee;

#define TRUE 1
#define FALSE 0

int generateId(void);
int initEmployees(Employee* list, int len);
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int findEmployeeById(Employee* list, int len,int id);
int removeEmployee(Employee* list, int len, int id);
int sortEmployees(Employee* list, int len, int order);
int printEmployees(Employee* list, int length);
int printAverageEmployees(Employee* list, int length);
int modifyEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
int qtyEmployee(Employee* list, int length);

#endif /* ARRAYEMPLOYEES_H_ */
