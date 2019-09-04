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

#ifndef CALCULADORA_H_
#define CALCULADORA_H_

#define EXIT_ERROR -1
#define MENU_OPERANDO_1 1
#define MENU_OPERANDO_2 2
#define MENU_OPERACION  3
#define MENU_RESULTADO  4
#define MENU_SALIR      5

#define MENU_SUMA 			'a'
#define MENU_RESTA			'b'
#define MENU_DIVISION		'c'
#define MENU_MULTIPLICACION	'd'
#define MENU_FACTORIAL		'e'

int getChar( char *pResultado,
			 char *pMensaje,
			 char *pMensajeError,
			 char minimo,
			 char maximo,
			 int reintentos);

int getInt(	int *pRresultado,
			char *pMensaje,
			char *pMensajeError,
			int minimo,
			int maximo,
			int reintentos);

int getFloat(float *pResultado,
			 char *pMensaje,
			 char *pMensajeError,
			 float minimo,
			 float maximo,
			 int reintentos);

int calculadora(void);

void imprimirMenuMain(float opA,
					  float opB);

void imprimirMenuOperaciones(void);

void mostrarResultado(float operandoA,
					  float operandoB,
					  char operacion);

#endif /* CALCULADORA_H_ */
