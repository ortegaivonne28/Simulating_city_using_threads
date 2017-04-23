#ifndef _CUADRA_H_
#define _CUADRA_H_
#include "lista.h"

typedef struct s_cuadra{
	
	struct s_cuadra** cuadras_adyacentes;
	int n_cuadras_adyacentes;
	int id;
	int id_central;//-1: no hay central en esta calle
	s_lista cola_carros;
} s_cuadra;
 

#endif //_CUADRA_H_
