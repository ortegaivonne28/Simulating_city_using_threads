#include "mapa.h"
#include "cuadra.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
enum ORIENTACION{
	//en este orden
	NORTE,
	OESTE,
	SUR,
	ESTE
	
};
typedef struct manzana{
	s_cuadra* c[4];
	int pl[4];
	
}manzana;
s_mapa* generar_mapa(int rx,int ry, int n_carros, int n_centrales){
	
	manzana man[rx][ry];
	s_mapa* mapa = malloc(sizeof(s_mapa));
	mapa->n_cuadras = 4*rx*ry - 4; //le quito una cuadra en cada esquina
	mapa->cuadras = malloc(sizeof(s_cuadra) * mapa->n_cuadras);
	
	int i,j,k;
	
	for(i=0;i<mapa->n_cuadras;i++){
		mapa->cuadras[i].id = i;
		mapa->cuadras[i].id_central = -1;
		l_crear(& mapa->cuadras[i].cola_carros);
	}
	
	
	int cc=0;
	
	for(j =0;j<ry;j++){
		for(i =0;i<rx;i++){
			for(k=0;k<4;k++){
				
				if(k == 3 && i==0 && j==0){
					man[i][j].c[k] = man[i][j].c[0]; 
				}else if (k == 1 &&i==rx-1 && j==0){
					man[i][j].c[k] = man[i][j].c[0]; 
				}else if (k == 2 &&i==rx-1 && j==ry-1){
					man[i][j].c[k] = man[i][j].c[1]; 
				}else if (k == 3 &&i==0 && j==ry-1){
					man[i][j].c[k] = man[i][j].c[2]; 
				}else{
						
					man[i][j].c[k] = &mapa->cuadras[cc++];
					man[i][j].c[k]->cuadras_adyacentes = malloc(sizeof(s_cuadra*)*(3));
					man[i][j].c[k]->n_cuadras_adyacentes  = 1;
				}
			}
	
			for(k=0;k<4;k++){
				if(man[i][j].c[k] != man[i][j].c[(k + 1)%4]){
					man[i][j].c[k]->cuadras_adyacentes[0]  = man[i][j].c[(k + 1)%4];
				}
			}
			if(i > 0){
				man[i][j].c[SUR]->cuadras_adyacentes[man[i][j].c[SUR]->n_cuadras_adyacentes++] =  man[i-1][j].c[SUR];
				man[i-1][j].c[NORTE]->cuadras_adyacentes[man[i-1][j].c[NORTE]->n_cuadras_adyacentes++] =  man[i][j].c[NORTE];
			}
			if(j > 0){
				man[i][j].c[ESTE]->cuadras_adyacentes[man[i][j].c[ESTE]->n_cuadras_adyacentes++] =  man[i][j-1].c[ESTE];		
				man[i][j-1].c[OESTE]->cuadras_adyacentes[man[i][j-1].c[OESTE]->n_cuadras_adyacentes++] =  man[i][j].c[OESTE];
			}
				

			
		} 
	} 
	
	mapa->centrales = malloc(sizeof(s_central)*n_centrales);
	mapa->n_centrales = 0;
	int nx = sqrt(n_centrales*ry/rx);
	int ny = nx*rx/ry;
	int nal = n_centrales - nx*ny;
	
	for(j =0;j<ny;j++){
		for(i =0;i<nx;i++){
			int x = rx*i/nx;
			int y = ry*j/ny;
			int i_cuadra = rand()%4;
			mapa->centrales[mapa->n_centrales].id_cuadra = man[x][y].c[i_cuadra]->id;
			man[x][y].c[i_cuadra]->id_central = mapa->n_centrales;
			mapa->n_centrales++;
					
		}	
	}	 	
	
	for(i =0;i<nal;i++){
		
		int x = rand()%rx;
		int y = rand()%ry;
		int i_cuadra = rand()%4;
		mapa->centrales[mapa->n_centrales].id_cuadra = man[x][y].c[i_cuadra]->id;
		man[x][y].c[i_cuadra]->id_central = mapa->n_centrales;
		mapa->n_centrales++;		
	}
	
	
	//los carros si que son aleatorios 
	
	mapa->n_carros = n_carros;
	mapa->carros = malloc(sizeof(s_carro)*n_carros); 
	
	for(i =0;i<mapa->n_carros;i++){
		mapa->carros[i].id = i;
		int id_cuadra = rand()%mapa->n_cuadras;
		mapa->carros[i].id_cuadra = id_cuadra;
		l_agregar(& mapa->cuadras[id_cuadra].cola_carros,  & mapa->carros[i]);
	}
	return mapa;
}

void destruir_mapa(s_mapa* map){
	free(map->cuadras);
	free(map->centrales);	
	free(map);
}
int main(int argc,char** argv){
	srand(8);
	
	int a,b,c,d;
	
	sscanf(argv[1],"%d", &a);
	sscanf(argv[2],"%d", &b);
	sscanf(argv[3],"%d", &c);
	sscanf(argv[4],"%d", &d);
	s_mapa* map = generar_mapa(a,b,c,d);
	int i,j;
	for(i=0;i<map->n_cuadras;i++){
		for(j=0;j<map->cuadras[i].n_cuadras_adyacentes;j++){
			printf("%d  --->  %d\n", map->cuadras[i].id, map->cuadras[i].cuadras_adyacentes[j]->id);
		}
	}
	
	for(i=0;i<map->n_centrales;i++){
		
		printf("central %d  --->  cuadra %d\n", i, map->centrales[i].id_cuadra);

	}	
	
	for(i=0;i<map->n_carros;i++){
		
		printf("carro %d  --->  cuadra %d\n", i, map->carros[i].id_cuadra);

	}		
	destruir_mapa(map);
	return 0;
}
