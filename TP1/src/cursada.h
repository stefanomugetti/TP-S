/*
 * cursada.h
 *
 *  Created on: Mar 25, 2021
 *      Author: Stefano
 */

#ifndef CURSADA_H_
#define CURSADA_H_

int utn_getNumero(int* numeroIngresado,char* pTexto,char* pTextoError,int min,int max,int reintentos);
int utn_getFloat(float* numeroIngresado,char* pTexto,char* pTextoError,int min,int max,int reintentos);
int utn_getChar(char* charIngresado,char* pTexto,char* pTextoError,char min,char max,int reintentos);
#endif /* CURSADA_H_ */
