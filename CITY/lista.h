#ifndef _LISTA_H_
#define _LISTA_H_

typedef struct s_nodo{
	struct s_nodo *sig;
	void* data;
}s_nodo;
typedef struct s_lista{
	s_nodo* inicio, *fin;
	
}s_lista;

void l_crear(s_lista* l);
void l_agregar(s_lista* l, void* e);
void l_destruir(s_lista* l);
void* l_top(s_lista* l);
s_nodo* l_top_node(s_lista* l);
void* l_pop(s_lista* l);
#endif // _LISTA_H_
