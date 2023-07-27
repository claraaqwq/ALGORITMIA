#include "abb.h"

void construir( ABB &pA )
{
    pA = NULL;  // todo arbol empieza vacio
}

NodoABB* crearNodo( Elemento e )
{
    // todo nodo que sea crea es siempre una hoja
    NodoABB *p;
    p = new NodoABB;  // se crea el nodo en memoria
    p->hizq = NULL;
    p->elem = e;
    p->hder = NULL;
    return p; // se retorna la direccion del nodo creado
}

void insertar( ABB &pA, Elemento e )
{
    NodoABB *p, *q, *pq;
    p = crearNodo( e );     // se crea el nodo como hoja
    if ( pA == NULL ) // arbol vacio
        pA = p;  // el nodo insertado se convierte en la raiz del árbol
    else  // el árbol no está vacío
    {
        // hay que encontrar la ubicación que le corresponde al nuevo nodo
        q = pA;
        pq = NULL;
        while ( q != NULL )
        {
            pq = q;
            if ( e.pos_letra < q->elem.pos_letra )
                q = q->hizq;
            else
                q = q->hder;
        }
        if ( e.pos_letra < pq->elem.pos_letra )
            pq->hizq = p;
        else
            pq->hder = p;
    }
}

// devuelve la dirección del nodo raiz del árbol
NodoABB* obtenerRaiz( ABB A )
{
    return A;
}

// muestra el contenido del árbol en orden
void mostrarEnOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        mostrarEnOrden( pAI);  // se recorre en orden el subarbol izquierdo
        cout <<pR->elem.letra<< " ";
        mostrarEnOrden( pAD);  // se recorre en orden el subarbol derecho
    }
}

//8. Funcion para mostrar en preOrden: significa que primero muestra la raiz y dps recorre nodos izquierdos y luego derecha
void mostrarEnPreOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        cout <<pR->elem.letra<< " ";
        mostrarEnPreOrden( pAI);  // se recorre en preorden el subarbol izquierdo
        mostrarEnPreOrden( pAD);  // se recorre en preorden el subarbol derecho
    }
}


//9. Funcion para mostrar en PostOrden: significa que primero recorre nodos de la izq hasta arriba, y dps los de la derecha
//finalmente imprime la raiz. Imprime hacia arriba
//Recorrido para eliminar nodos
void mostrarEnPostOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        mostrarEnPostOrden( pAI);  // se recorre en postorden el subarbol izquierdo
        mostrarEnPostOrden( pAD);  // se recorre en postorden el subarbol derecho
        cout <<pR->elem.letra<< " ";
    }
}


int es_arbol_vacio(ABB tad){
    return tad==NULL;
}

void mostrarArbol (NodoABB *nodoArbol, int contador){
	if(nodoArbol == NULL){
		return;
	}
	else{//imprimo la parte derecha del arbol
		mostrarArbol(nodoArbol->hder,contador+1);
		for(int i=0;i<contador;i++){
			cout<<"      ";
		}
		cout <<nodoArbol->elem.pos_letra<<"-"<< nodoArbol->elem.letra<< " ";
		mostrarArbol(nodoArbol->hizq,contador+1);
	}
}

// retorna true si el elemento e se encuentra en el árbol
// retorne false en caso contrario
bool buscar( NodoABB *pR, Elemento e )
{
    NodoABB *p;
    p = pR;
    while ( p != NULL )
    {
        if ( e.pos_letra == p->elem.pos_letra)  // si lo encuentra retorna true
            return true;
        else
            if ( e.pos_letra < p->elem.pos_letra )
                p = p->hizq;   // continua la búsqueda en el subárbol izquierdo
            else
                p = p->hder;   // continua la búsqueda en el subárbol derecho
    }
    return false;  // si no lo encuentra retorna false
}

// retorna el valor del elemento menor del árbol
// el menor siempre se encuentra en el extremo izquierdo del árbol
Elemento menor( NodoABB *pR )
{
    NodoABB *p;
    p = pR;
    while ( p->hizq != NULL )
        p = p->hizq;
    return p->elem;
}

// retorna el valor del elemento mayor del árbol
// el mayor siempre se encuentra en el extremo derecho del árbol
Elemento mayor( NodoABB *pR )
{
    NodoABB *p;
    p = pR;
    while ( p->hder != NULL )
        p = p->hder;
    return p->elem;
}


//Funcion para hallar el numero mayor entre 2
int maximo(int a, int b)
{
    if (a > b)
        return a;
    else
        return b;
}

int _hallarAltura(NodoABB *pActual)
{
    int alturaIzq, alturaDer;
    if (pActual == NULL)
        return 0;
    else
    {
        alturaIzq = 1 + _hallarAltura(pActual->hizq);
        alturaDer = 1 + _hallarAltura(pActual->hder);
        return maximo(alturaIzq, alturaDer);
    }
}

void hallarAlturaArbol(NodoABB *arbol)
{
    if (es_arbol_vacio(arbol))
        cout << "No se puede hallar la altura de un arbol vacio" << endl;
    else
    {
        cout << "La altura del arbol es: " << _hallarAltura(arbol) << endl;
    }
}

int contarNodos( NodoABB *pR )
{
    NodoABB *pAI, *pAD;
    int nodosAI, nodosAD;
    if ( pR == NULL )  // caso base: arbol vacio: no tiene nodos
        return 0;
    else
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        nodosAI = contarNodos( pAI); // cuenta los nodos del subárbol izquierdo
        nodosAD = contarNodos( pAD); // cuenta los nodos del subárbol derecho
        return nodosAI + nodosAD + 1;  // le suma 1 ( el nodo raiz )
    }
}

// retorna la suma de los datos contenidos en el árbol
int sumarNodos( NodoABB *pR )
{
    NodoABB *pAI, *pAD;
    int sumaAI, sumaAD;
    if ( pR == NULL )  // caso base: arbol vacio
        return 0;
    else
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        sumaAI = sumarNodos( pAI); // suma los datos del subárbol izquierdo
        sumaAD = sumarNodos( pAD); // suma los datos del subárbol derecho
        return sumaAI + sumaAD + pR->elem.pos_letra;  // le suma el dato contenido en la raiz
    }
}

