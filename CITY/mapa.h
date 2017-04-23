#ifndef _MAPA_H_
#define _MAPA_H_
#include "cuadra.h"
#include "central.h"	
#include "carro.h"
typedef struct s_mapa{
	
	s_cuadra** cuadras;
	s_carro* carros;
	void* avenidas;
	s_central* centrales;
	int n_cuadras;
	int n_carros;
	int n_centrales;
	int n_avenidas;
} s_mapa;
 
s_mapa* generar_mapa(int rx,int ry, int n_carros, int n_centrales);
void correr_simulacion(float tiempo, float espera);


void destruir_mapa(s_mapa* map);
#endif //_MAPA_H_
