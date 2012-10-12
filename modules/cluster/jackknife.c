
/*******************************************************************************
 * 
 * 		File "jackknife.c"
 * 
 * File contenente le definizioni delle routines necessarie per la manipolazione
 * di cluster jackknife.
 * 
 * Le routines sono:
 * _ cluster_init -> inizializzazione di un cluster jackknife;
 * 
 * _ clusterJK -> assegnamento di media e varianza della media nel cluster
 * 		jackknife passato ad argomento.
 * 
 ******************************************************************************/

#define JACKKNIFE_C

#include <stdio.h>
#include <stdlib.h>
#include "cluster.h"


/* Assegnamento di media e varianza della media */
void clusterJK(cluster *C)
{
	int i;
	int dim = C->Dim;
	
	C->Mean = 0;
	for(i=0; i<dim; i++)
		C->Mean += (C->Vec[i])/((double)dim);
	
	for(i=0; i<dim; i++)
		C->Vec[i] = C->Mean + (C->Mean - C->Vec[i])/((double)(dim - 1));
	
	C->Sigma = 0;
	for(i=0; i<dim; i++)
		C->Sigma += ((double)(dim - 1))/((double)dim)*(C->Vec[i] - C->Mean)*(C->Vec[i] - C->Mean);
}


/* Inizializzazione di un cluster jackknife */
void cluster_init(cluster *C, int dim)
{
	C->Dim	= dim;
	C->Mean	= 0;
	C->Sigma= 0;
	C->Vec	= malloc(dim*sizeof(double));
}
