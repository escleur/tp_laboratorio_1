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
#include <stdlib.h>
#include "funcionesMath.h"
#include "calculadora.h"

/**
 * \brief suma dos numeros
 * \param op1 Es el primer operando de la calculadora
 * \param op2 Es el segundo operando de la calculadora
 * \return El numero resultado de la suma
 *
 */
float sumar(float op1, float op2)
{
	return op1 + op2;
}

/**
 * \brief resta dos numeros
 * \param op1 Es el primer operando de la calculadora
 * \param op2 Es el segundo operando de la calculadora
 * \return El numero resultado de la resta
 *
 */
float restar(float op1, float op2)
{
	return op1 - op2;
}

/**
 * \brief divide dos numeros
 * \param pResultado Devuelve el resultado de la division
 * \param op1 Es el primer operando de la calculadora
 * \param op2 Es el segundo operando de la calculadora
 * \return Devuelve 0 en caso de exito y -1 si se intento dividir por cero
 *
 */
int dividir(float *pResultado, float op1, float op2){
	float res;
	if(op2 == 0)
	{
		return EXIT_ERROR;
	}
	res = op1 / op2;
	*pResultado = res;
	return EXIT_SUCCESS;
}

/**
 * \brief multiplica dos numeros
 * \param op1 Es el primer operando de la calculadora
 * \param op2 Es el segundo operando de la calculadora
 * \return El numero resultado de la multiplicacion
 *
 */
float multiplicar(float op1, float op2){
	return op1 * op2;
}

/**
 * \brief hace el factorial de un numero
 * \param op1 Es el primer operando de la calculadora
 * \return El numero resultado del factorial
 *
 */
float factorial(float op1){
	if(op1 <= 1){
		return 1;
	}else{
		return op1 * factorial(op1 - 1);
	}
}
