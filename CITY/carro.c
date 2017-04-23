#include "mapa.h"
#include "lista.h"
#include "semaphore.h"
#include "carro.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Funciones y Procedimientos
void crear_carro(s_carro *car,int id,int cuadra, int canal)
{
	(*car).id=id;
	(*car).id_cuadra=cuadra;
	(*car).mov_semaforo=0;
	(*car).d_movimiento=FALSE;
	(*car).amonestaciones_emisor=0;
	(*car).amonestaciones_receptor=0;
}


void recibir_cornetazo(s_carro **car_Re,int id_emisor)
{
	
	if((**car_Re).buffer[0].cant_cornetas==0)
	{
		(**car_Re).buffer[0].id_emisor=id_emisor;
		(**car_Re).buffer[0].cant_cornetas++;
	}else
	{
		if((**car_Re).buffer[0].id_emisor==id_emisor)
		{
		(**car_Re).buffer[0].cant_cornetas++;
		}
		else
		{
		(**car_Re).buffer[1].id_emisor=id_emisor;
		(**car_Re).buffer[1].cant_cornetas++;
		}
	}
}


void movimiento(s_carro *car, void *m)
{
	s_mapa* mapa = (s_mapa*)m;
	s_cuadra* cuadra_nueva;
	s_lista* lista_nueva;
	srand(time(NULL));
	s_carro* car_aux;
	int id=car->id_cuadra;
	car_aux=(s_carro*)l_top( & mapa->cuadras[id]->cola_carros );
	
	if( car_aux==car) 
	{
		car->mov_semaforo = rand()%((mapa->cuadras[id]->n_cuadras_adyacentes)+1); //random que dependa de mapa->cuadra[id]->n_cuadras_adyacentes
		cuadra_nueva=mapa->cuadras[car->id_cuadra]->cuadras_adyacentes[car->mov_semaforo];
		lista_nueva=&cuadra_nueva->cola_carros;
		l_agregar(lista_nueva,car);
		l_pop(&mapa->cuadras[car->id_cuadra]->cola_carros);
		car->id_cuadra=cuadra_nueva->id;
			
	}
}



void decidir_movimiento(s_carro* car, void *m)
{ 
	s_mapa *mapa = (s_mapa *)m;
	srand(time(NULL));
	if((((s_carro*)(l_top( &(*mapa).cuadras[car->id_cuadra]->cola_carros)))->id == car->id))// && (/*semaforo= verde*/)
	{
		if((rand()%2)==TRUE)
			movimiento(car,mapa);
		else 
		{
			if(/*cornetazo==TRUE*/TRUE)
			{
				movimiento(car, mapa);
			}
			else
			{
				//printf("No quiero pues");
			}
		}
		
	}
}


//Funcion que consulta la cantidad de cornetas en el buffer. 
int consultar_buffer_cornetas(s_carro car,int a)
{
	return(car.buffer[a].cant_cornetas);
}
//Funcion que consulta el id del emisor en el buffer
int consultar_buffer_id_emisor(s_carro car,int a)
{
	return(car.buffer[a].id_emisor);
}

