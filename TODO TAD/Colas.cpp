#include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodo
{
    Elemento elem;  // el dato que almacena el nodo
    struct nodo *sig;  // sig es la direcciÃ³n del siguiente nodo
} NodoC;

typedef struct cola
{
    NodoC *frente;
	NodoC *final; // cabeza almacena la direccion del primer nodo de la lista
    int longitud; // cantidad de nodos de la lista
} Cola;

void construir( Cola &pC )
{
    // se crea la cola vacia
    pC.frente= NULL;
    pC.final = NULL;
    pC.longitud = 0;
}

bool esColaVacia( Cola C )
{
    return C.frente == NULL;
    // return C.final == NULL;
    // return C.longitud == 0;
}

int obtenerLongitud( Cola C )
{
    return C.longitud;
}

NodoC* crearNodo( Elemento e, NodoC *s )
{
    NodoC *p;
    p = new NodoC; // se crea un nodo y su direccion se almacena en p
    p->elem = e;
    p->sig = s;
    return p;  // retorna la direcciÃ³n del nodo creado
}

void encolar( Cola &pC, Elemento e )
{
    NodoC *p, *pU;
    p = crearNodo( e, NULL);
    if ( esColaVacia(pC) )
    {
        pC.frente = p;
        pC.final = p;
    }
    else
    {
        pU = pC.final;
        pU->sig = p;
    }
    pC.final = p;
    pC.longitud++;
}

void mostrar( Cola C )
{
    NodoC *p;
    if ( esColaVacia(C) )
        cout << "La cola esta vacia" << endl;
    else
    {
        p = C.frente;
        while ( p!= NULL )
        {
            cout << p->elem << " ";
            p = p->sig;
        }
        cout << endl;
    }
}

// esta funcion solo sera invocada previa verificacion de que la cola no esta vacia
Elemento desencolar( Cola &pC )
{
    Elemento x;
    NodoC *p;
    p = pC.frente;
    if ( p->sig == NULL ) // hay un solo nodo en la Cola
        pC.final = NULL;
    pC.frente = p->sig;
    x = p->elem;
    pC.longitud--;
    delete p;
    return x;
}

void destruir( Cola &pC )
{
    int i;
    NodoC *p, *q;
    if ( !esColaVacia(pC) )
    {
        p = pC.frente;
        for(i=1; i<=pC.longitud; i++)
        {
            q = p->sig;
            delete p;
            p = q;
        }
        pC.frente = NULL;
        pC.final = NULL;
        pC.longitud = 0;
    }
}

void ordenarec(Cola &cola, int n){//puntero a la Cola y cantidad de elemento de la Cola
	int i, min;
	int aux;//para comparar con menor y encontrar el menor de la Cola.
	if(esColaVacia(cola)){
		return ;
	}
	min = desencolar(cola);
	i=1;//como ya tomamos un elemento, inicializamos en 1
	while(i<n){
		aux = desencolar(cola);
		if(aux<min){//tenemos un nuevo menor de la Cola
			encolar(cola,min);//encolo el elemento que estuvo en "menor" porque ya no es el menor
			min = aux;
		}else{
			encolar(cola,aux);//encolo el elemento que está en auxiliar. El elemento menor sigue estando en "menor"
			
		}
		i++;
	}
	//HASTA AQUI ya hemos encontrado el menor elemento de toda la Cola (en este mundo)
	//entonces:
	ordenarec(cola,n-1);//hacemos la llamada recursiva para los demás elementos
	encolar(cola,min);//al retornar de la llamada recursiva, encolamos el menor
	//con eso logramos encolar de manera ordenada.
	
}

int main(int argc, char** argv) {
    Cola Ccola;
    
    construir(Ccola);
    encolar(Ccola,10);
    encolar(Ccola,2);
    encolar(Ccola,15);
    encolar(Ccola,1);
    encolar(Ccola,20);
    mostrar(Ccola);
    
    ordenarec(Ccola,Ccola.longitud);
    mostrar(Ccola);

    return 0;
}
