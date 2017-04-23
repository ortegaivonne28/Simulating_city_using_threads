#include "carro.h"
#include <stdio.h>
#include <stdlib.h> 
#include <semaphore.h>
#include <pthread.h>
#define long_buffer 2

// Hilos
//void *enviar_cornetazo();

// Semafaros
   sem_t EX_buffer[3];
   

int main()
{
	carro A, B, C;
	
	//crear_carro();
	
		//Inicialización de los semáforos
	for (int i = 0; i < long_buffer; i++)
	{
		sem_init(&cornetasos[i], 0, 0);//número de cornetasos en el buffer
		sem_init(&huecos[i], 0, long_buffer);//número de espacios vacíos
		sem_init(&exclusion_mutua[i], 0, 1);// semaforo binario
	}
	//Creación e inicialización de los hilos	 
	pthread_t hilo_emisor, hilo_receptor;
	
	
	return 0;
}
void enviar_cornetazo( void * car_Emi, void **car_Re)
{
	while(true){
		
		sem_wait(&EX_buffer[]);
			/// SC
			recibir_cornetazo(car_Re, car_Emi.id);
			///
		sem_post(&EX_buffer[i]);
	}
}

void Emisor(void *carro)
{
	void **a;
	void **b;        //a,b puntadores de apuntadores para el resultado
	
	while(1)
	{
		if(rand() % 2 == 1)
		{
			l_get_adyacentes( cola_carros, carro, a, b);// se buscan los adyacentes de carro[i]
			
			sem_wait(&EX_buffer[(**a).id]);
			recibir_cornetazo(**a, (*carro).id);
			sem_post(&EX_buffer[(**a).id]);
			
			sem_wait(&EX_buffer[(**b).id]);
			recibir_cornetazo(**b, (*carro).id);
			sem_post(&EX_buffer[(**b).id]);
		}
	}
}
