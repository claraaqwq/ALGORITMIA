
#include "ab.h"

void construir( AB &pA )
{
    pA = NULL;  // todo arbol empieza vacio
}

NodoAB* crear_nodoab(Elemento dato,AB arbol_izq,AB arbol_der){
    NodoAB* nuevo = new NodoAB;
    
    nuevo->elem.cantidad=dato.cantidad;
    nuevo->elem.lote=dato.lote;
    nuevo->hizq = arbol_izq;
    nuevo->hder = arbol_der;
    return nuevo;
}

void insertar_ab(AB &tad,Elemento dato,AB arbol_izq,AB arbol_der){
   NodoAB* nuevo = crear_nodoab(dato,arbol_izq,arbol_der);
   tad=nuevo; 
}
void insertar_ab_izq(AB& tad,Elemento dato){O
   NodoAB* nuevo = crear_nodoab(dato,NULL,NULL);
   tad->hizq = nuevo; 
}
void insertar_ab_der(AB& tad,Elemento dato){
   NodoAB* nuevo = crear_nodoab(dato,NULL,NULL);
   tad->hder=nuevo; 
}

// devuelve la dirección del nodo raiz del árbol
NodoAB* obtenerRaiz( AB A )
{
    return A;
}

void imprimirelemento(Elemento dato){
    cout <<dato.lote<<"-"<<dato.cantidad<<"  ";    
}

void en_orden(AB tad){
    if(!es_arbol_vacio(tad)){
        en_orden(tad->hizq);
        imprimirelemento(tad->elem);
        en_orden(tad->hder);
    }   
}

void pre_orden(AB tad){
    if(!es_arbol_vacio(tad)){
        imprimirelemento(tad->elem);
        pre_orden(tad->hizq);
        pre_orden(tad->hder);
    }    
}

int es_arbol_vacio(AB tad){
    return tad==NULL;
}
