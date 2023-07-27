#ifndef AB_H
#define AB_H

#include <iostream>

using namespace std;

typedef struct {
    int lote; //codigo
    int cantidad;  //peso
}Elemento;

typedef struct nodo
{   Elemento elem;      // dato
    struct nodo *hizq;  // puntero al hijo izquierdo
    struct nodo *hder;  // puntero al hijo derecho
} NodoAB;

typedef NodoAB * AB;

void construir( AB &pA );
NodoAB* crear_nodoab(Elemento ,AB ,AB );
void insertar_ab(AB& ,Elemento ,AB ,AB );
void en_orden(AB );
int altura(AB );

void imprimirelemento(Elemento);
void post_orden(AB );
void pre_orden(AB );
int es_arbol_vacio(AB);

void insertar_ab_izq(AB& ,Elemento );
void insertar_ab_der(AB& ,Elemento );


#endif /* AB_H */
