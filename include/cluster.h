
#ifndef CLUSTER_H
#define CLUSTER_H


typedef struct
{
	int Dim;		/* Dimensione del vettore */
	double Mean;	/* Media degli elementi del vettore */
	double Sigma;	/* Varianza della media */
	double *Vec;	/* Vettore degli elementi del campione */
} cluster;


#ifndef JACKKNIFE_C
extern void clusterJK(cluster *C);
extern void cluster_init(cluster *C, int dim);
#endif

#endif
