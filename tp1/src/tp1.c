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
#include "calculadora.h"

int main(void) {
	if(calculadora()==EXIT_ERROR){
		printf("Se produjo un error con los datos ingresados");

	}
	return EXIT_SUCCESS;
}
