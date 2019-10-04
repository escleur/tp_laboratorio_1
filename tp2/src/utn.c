/*
 ============================================================================
 Author      : Sanjurjo Gabriel Alejandro
 Description : Trabajo practico numero 2
 ============================================================================
 */


#include <stdio.h>
#include <stdio_ext.h>
#include <stdlib.h>
#include <string.h>
#include "utn.h"

//Linux
#define PURGAR __fpurge(stdin);
//Windows
//#define PURGAR fflush(stdin);

/** \brief Reads a integer from standard input
 * \param pResultado int*
 * \param pMensaje char*
 * \param pMensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or minimo>=maximo or reintentos<0] - (0) if Ok
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
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}


/** \brief Reads a float from standard input
 * \param pResultado float*
 * \param pMensaje char*
 * \param pMensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or minimo>=maximo or reintentos<0] - (0) if Ok
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
			printf("%s",pMensaje);
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
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}


/** \brief Reads a string from standard input
 * \param pResultado char*
 * \param pMensaje char*
 * \param pMensajeError char*
 * \param minimo int
 * \param maximo int
 * \param reintentos int
 * \return int Return (-1) if Error [Invalid length or NULL pointer or minimo>=maximo or reintentos<0] - (0) if Ok
 *
 */
int getString (char *pResultado,
		      char *pMensaje,
			  char *pMensajeError,
			  int minimo,
			  int maximo,
			  int reintentos)
{
	int retorno = EXIT_ERROR;
	char buffer[500];
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
			fgets(buffer,sizeof(buffer),stdin);
			buffer[strlen(buffer)-1] = '\0';
			if(strlen(buffer)>=minimo && strlen(buffer) <= maximo)
			{
				strncpy(pResultado,buffer,maximo+1);
				retorno = 0;
				break;
			}
			printf("%s",pMensajeError);
			reintentos--;
		}while(reintentos >= 0);
	}
	return retorno;
}

