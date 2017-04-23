#include "lista.h"
#include <stdlib.h>
void l_crear(s_lista* l){
	l->inicio = l->fin = 0;
}
void l_agregar(s_lista* l, void* e){
	s_nodo* nd = malloc(sizeof(s_nodo));
	nd->data = e;	
	nd->sig = 0;
	if(l->fin){

		l->fin->sig = nd;
		l->fin = nd;
	}else{
		l->fin = l->inicio = nd;
	}
	
}
void l_destruir(s_lista* l){
	
	s_nodo* sig;

	while(l->inicio) {
		sig = l->inicio->sig;
		free(l->inicio);
		l->inicio = sig;
	}
	l->fin = 0;
}
void* l_top(s_lista* l){
	return l->inicio->data;
}
s_nodo* l_top_node(s_lista* l){
	return l->inicio;
}

void* l_pop(s_lista* l){
	void* e =0;
	if(l->inicio){
		e = l->inicio->data;
		s_nodo* sig= l->inicio->sig;
		free(l->inicio);
		l->inicio = sig;
		if(l->inicio == 0)l->fin = 0;
	}
	return e;
}
