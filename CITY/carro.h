#ifndef _CARRO_H_
#define _CARRO_H_
//#include "mapa.h"
#include "lista.h"

//CONSTANTES
#define TRUE 1
#define FALSE 0
#define DERECHA 1
#define IZQUIERDA 2
#define RECTO 3

//Estructura buffer
typedef struct{
	int id_emisor, cant_cornetas;	
		
}E_buffer;

typedef struct s_carro{
	int mov_semaforo, amonestaciones_emisor, amonestaciones_receptor,d_movimiento;
	int id_cuadra;//cuadra donde esta
	int id;//indice del carro en el mapa
	//falta lista camino
	E_buffer buffer[2]; // buffer
} s_carro;

int hilo_carro(void*); 

void crear_carro(s_carro *car,int id,int cuadra, int canal);

void recibir_cornetazo(s_carro **car_Re,int id_emisor);

void movimiento(s_carro *car, void *m);

//Funcion que consulta la cantidad de cornetas en el buffer. 
int consultar_buffer_cornetas(s_carro car,int a);

//Funcion que consulta el id del emisor en el buffer
int consultar_buffer_id_emisor(s_carro car,int a);

#endif 
