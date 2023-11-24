/**
	@file funciones.h
	@brief Aqui estan los prototipos de las funciones
	@author Angel
*/
#ifndef FUNCIONES_H
#define FUNCIONES_H

int ** reservaMemoria(int nfil, int ncol);
void liberaMemoria(int *** m, int nfil);
void calculosVarios(int ** m, int nfil, int ncol,int * suma, int * ndiv);

#endif