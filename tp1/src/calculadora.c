/*************************************************************************
 * Programa: Trabajo practico numero 1 Calculadora.
 *
 * Objetivo: Ingresar dos valores en el menu y una operacion
 * 			 y poder visualizar los resultados.
 *
 * Version: 0.1 del 4 de septiembre de 2019
 * Autor: Gabriel Alejandro Sanjurjo
 *
 *************************************************************************/

#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "calculadora.h"
#include "funcionesMath.h"

//Linux
#define PURGAR __fpurge(stdin);
//Windows
//#define PURGAR fflush(stdin);

/**
 * \brief Solicita un caracter al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo El minimo valor aceptado por la funcion como valido
 * \param maximo El maximo valor aceptado por la funcion como valido
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getChar(  char *pResultado,
			  char *pMensaje,
			  char *pMensajeError,
			  char minimo,
			  char maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s",pMensaje);
			PURGAR
			if(scanf("%c",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un entero al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo El minimo valor aceptado por la funcion como valido
 * \param maximo El maximo valor aceptado por la funcion como valido
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getInt(	int *pResultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos)
{
	int retorno = EXIT_ERROR;
	int buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			PURGAR
			if(scanf("%d",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief Solicita un flotante al usuario y devuelve el resultado
 * 		  informando si la operacion fue exitosa
 * \param pResultado Es el resultado a devolver
 * \param pMensaje Es el mensaje a ser mostrado
 * \param pMensajeError Es el mensaje a ser mostrado cuando se ingreso un valor erroneo
 * \param minimo El minimo valor aceptado por la funcion como valido
 * \param maximo El maximo valor aceptado por la funcion como valido
 * \param reintentos Es la cantidad de reintentos en caso de fallar
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int getFloat(float *pResultado,
			 char *pMensaje,
			 char *pMensajeError,
			 float minimo,
			 float maximo,
			 int reintentos)
{
	int retorno = EXIT_ERROR;
	float buffer;
	if(	pResultado != NULL &&
		pMensaje	!= NULL &&
		pMensajeError != NULL &&
		minimo < maximo &&
		reintentos >= 0)
	{
		do
		{
			printf("%s", pMensaje);
			PURGAR
			if(scanf("%f",&buffer)==1)
			{
				if(buffer >= minimo && buffer <= maximo)
				{
					retorno = EXIT_SUCCESS;
					*pResultado = buffer;
					break;
				}
			}
			printf("%s", pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

/**
 * \brief muestra y opera el menu principal y el de operaciones de la calculadora
 * \return -1 en caso de error y 0 si la operacion fue exitosa
 *
 */
int calculadora(void)
{
	int retorno = EXIT_ERROR;
	float operandoA = 0;
	float operandoB = 0;
	char operacion = MENU_SUMA;  //Operacion cargada por defecto en suma
	int opcionMenuInt;           //Variable para seleccionar la opcion del menu

	do
	{
		imprimirMenuMain(operandoA, operandoB);
		if(getInt(&opcionMenuInt, "Elija su opción\n", "Error\n", 1, 5, 10) == EXIT_ERROR)
		{
			return retorno;
		}
		switch(opcionMenuInt)
		{
			case MENU_OPERANDO_1:
				if(getFloat(&operandoA, "Ingrese el operando A\n", "Error\n", -3.4E+38, +3.4E+38, 10) == EXIT_ERROR)
				{
					return retorno;
				}
				break;
			case MENU_OPERANDO_2:
				if(getFloat(&operandoB, "Ingrese el operando B\n", "Error\n", -3.4E+38, +3.4E+38, 10) == EXIT_ERROR)
				{
					return retorno;
				}
				break;
			case MENU_OPERACION:
				imprimirMenuOperaciones();

				if(getChar(&operacion, "Ingrese el operador B\n", "Error\n", 'a', 'e', 10) == EXIT_ERROR)
				{
					return retorno;
				}
				break;
			case MENU_RESULTADO:
				mostrarResultado(operandoA, operandoB, operacion);
				break;
		}
	}while(opcionMenuInt != MENU_SALIR);

	retorno = EXIT_SUCCESS;
	return retorno;
}

/**
 * \brief Imprime el menu principal
 * \param opA Es el primer operando de la calculadora
 * \param opB Es el segundo operando de la calculadora
 * \return void
 *
 */
void imprimirMenuMain(float opA, float opB)
{
	printf(	"1. Ingresar 1er operando (A=%f)\n"
			"2. Ingresar 2do operando (B=%f)\n"
			"3. Calcular todas las operaciones \n"
			"4. Informar resultados \n"
			"5. Salir\n", opA, opB);
}

/**
 * \brief Imprime el menu de operaciones
 * \return void
 *
 */
void imprimirMenuOperaciones(void)
{
	printf(	"a. Calcular la suma (A+B)\n"
			"b. Calcular la resta (A-B)\n"
			"c. Calcular la division(A/B)\n"
			"d. Calcular la multiplicacion (A*B)\n"
			"e. Calcular el factorial (A!)\n");
}

/**
 * \brief procesa los operandos y muestra la operacion resultante
 * \param operandoA Es el primer operando de la calculadora
 * \param operandoB Es el segundo operando de la calculadora
 * \param operacion Es la operacion a realizar
 * \return void
 *
 */
void mostrarResultado(float operandoA, float operandoB, char operacion)
{
	float resultado;
	switch(operacion){
		case MENU_SUMA:
			resultado = sumar(operandoA, operandoB);
			printf("El resultado de A+B es: %f\n", resultado);
			break;
		case MENU_RESTA:
			resultado = restar(operandoA, operandoB);
			printf("El resultado de A-B es: %f\n", resultado);
			break;
		case MENU_DIVISION:
			if(dividir(&resultado, operandoA, operandoB)== EXIT_ERROR)
			{
				printf("No es posible dividir por cero\n");
			}else
			{
				printf("El resultado de A/B es: %f\n", resultado);
			}

			break;
		case MENU_MULTIPLICACION:
			printf("El resultado de A*B es: %f\n", multiplicar(operandoA, operandoB));
			break;
		case MENU_FACTORIAL:
			printf("El factorial de A es: %f y ", factorial(operandoA));
			printf("El factorial de B es: %f\n", factorial(operandoB));
			break;
	}
}

