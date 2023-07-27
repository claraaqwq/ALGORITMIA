#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodo{
	Elemento elem;
	struct nodo *sig;
}NodoP;

typedef struct {
	NodoP *cima;
	int longitud;
}Pila;

void construir( Pila &pP )
{
    // se crea la pila vacia
    pP.cima = NULL;
    pP.longitud = 0;
}

bool esPilaVacia( Pila P )
{
    return P.cima == NULL;
    // return P.longitud == 0;
}

NodoP* crearNodo( Elemento e, NodoP *s )
{
    NodoP *p;
    p = new NodoP; // se crea un nodo y su direccion se almacena en p
    p->elem = e;
    p->sig = s;
    return p;  // devuelve la direccion del nodo creado
}

void apilar( Pila &pP, Elemento e )
{
    NodoP *p;
    p = crearNodo( e, pP.cima );
    pP.cima = p;
    pP.longitud++;
}

void mostrar( Pila P )
{
    NodoP *p;
    int i;
    if ( esPilaVacia(P) )
        cout << "Pila vacia" << endl << endl;
    else
    {
        p = P.cima;
        for(i=0; i<P.longitud; i++)
        {
            cout << p->elem <<endl;
            p = p->sig;
        }
        
    }
    cout << endl;
}

// solo se usara esta funcion si la pila tiene datos
Elemento desapilar( Pila &pP )
{
    NodoP *p;
    Elemento e;
    p = pP.cima;
    e = p->elem;
    pP.cima = p->sig;
    pP.longitud--;
    delete p;
    return e;
}

void destruir( Pila *pP )
{
    int i;
    NodoP *p, *q;
    if ( !esPilaVacia(*pP) )
    {
        p = pP->cima;
        for(i=1; i<=pP->longitud; i++)
        {
            q = p->sig;
            delete p;
            p = q;
        }
        pP->cima = NULL;
        pP->longitud = 0;
    }
}

int top(Pila ptrPila)
{   NodoP *ptrrec;
    
    ptrrec = ptrPila.cima;
    if(esPilaVacia(ptrPila))
        return 0;
    else
        return ptrrec->elem;

}

void ordenarPila(Pila &pila1, int n){
	int min,valor,i;
	Pila pila2;
	construir(pila2);
	if(n==0) return ; //condicion de salida
	min = desapilar(pila1);
	i=n-1; //Tengo que validar que pasa si solo tengo 1 elemento
	while(i>0){
		valor = desapilar(pila1);
		if(min>valor){
			apilar(pila2,min);
			min = valor;
		}else{
			apilar(pila2,valor);
		}
		i--;
	}
	apilar(pila1,min);
	while(!esPilaVacia(pila2)){
		valor = desapilar(pila2);
		apilar(pila1,valor);
	}
	ordenarPila(pila1,n-1);
	
}

int main(){
	Pila P1;
	
	construir(P1);
	
	apilar(P1,15);
	apilar(P1,20);
	apilar(P1,5);
	apilar(P1,56);
	apilar(P1,4);
	mostrar(P1);
	
	ordenarPila(P1,P1.longitud);
	mostrar(P1);
	
}
