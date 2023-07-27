#include <iostream>
#include <iomanip>
using namespace std;

//ESTRUCTURAS
typedef int Elemento;

typedef struct nodo{
	Elemento element;
	nodo *siguiente;
	
}Nodo;

typedef struct{
	Nodo *cabeza;
	int cantNodos;
}Lista;

void construirListaVacia (Lista *pL){
    pL->cabeza == NULL;
    pL->cantNodos = 0;
}
//valido la lista vacia
bool esListaVacia (Lista L){
    return L.cabeza == NULL;
}
//creas un nodo
Nodo *crearNodo (Elemento e, Nodo *siguiente){
    //Creas tu nodo
    Nodo *nodo = new Nodo;
    nodo->element = e;
    nodo->siguiente = siguiente;
    return nodo;
}
//funcion para retornar cantNodos
int cantNodos (Lista L){
    return L.cantNodos;
}

void mostrarLista (Lista L){
    //saco un nodo a evaluar
    Nodo *nodo;
    if(esListaVacia(L)){
        cout<<"Es lista vacia, no tiene datos."<<endl;
    }else{
        //al primer nodo le doy la direccion de la cabeza
        nodo = L.cabeza;
        //recorro todos los nodos
        for(int i=0;i<L.cantNodos;i++){
            cout<<nodo->element<<" ";
            nodo = nodo->siguiente;
        }
        cout<<endl;
    }
}

void insertarAlComienzo (Elemento e, Lista *pL){
    //Saco un Nodo a evaluar
    Nodo *nodo;
    //Como es el primer nodo, a la hora de crear más van a ir apuntando a la cabeza
    nodo = crearNodo(e,pL->cabeza);
    pL->cabeza = nodo;
    pL->cantNodos++;
}

void invertirLista (Lista *pL){
	//Creo nodos que me permitiran posicionarme en la lista
	Nodo *nodoAnt, *nodoAct, *nodoIn=pL->cabeza;
	int n;
	n = pL->cantNodos;
	//COMPLEJIDAD = n^2 {2 for's}
	//recorro la lista
	for(int i=1;i<n;i++){
		//Comienzo en la cabeza de la lista
		nodoAct = pL->cabeza;
		nodoAnt = NULL; //no apunta a ningun nodo el anterior
		for(int j=i;j<n;j++){
			nodoAnt = nodoAct;
			nodoAct = nodoAct->siguiente;
		}
		if(i==1) nodoIn = nodoAct;
		nodoAct->siguiente = nodoAnt;
	}
	if(n>1) nodoAnt->siguiente = NULL; 
	pL->cabeza = nodoIn;
}

Nodo *recorre(Nodo *nodo){
	Nodo *nodoIn;
	//Caso que no tiene nodos
	if(nodo==NULL) return NULL;
	//Caso que tenga 1 nodo = CASO BASE
	if(nodo->siguiente == NULL) return nodo;
	//nuevo in hará lo q recorre el siguiente
	//PROCEDIMIENTO: 
	//recorrerá hasta el ultimo nodo y de ahi empezá a retroceder hasta el primero
	//mi primer nodo tomado(last), será mi cabeza cuando lo invierta
	//busca el inicio
	nodoIn = recorre(nodo->siguiente);
	//CASO SEA: 20 -> 8  || 8 -> 20
	//da la vuelta a los nodos
	nodo->siguiente->siguiente = nodo;
	nodo->siguiente = NULL;
	//Retorna el ultimo nodo que se tomó
	return nodoIn;
}

//AHORA MISMA FUNCION INVERTIR + RECURSION
void invierteRecursivo( Lista *pL){
	//Saco un nodo a evaluar
	Nodo *nodoAct;
	
	nodoAct = recorre(pL->cabeza);
	pL->cabeza = nodoAct;
}

int main(int argc, char** argv) {

    //Saco una lista a evaluar
    Lista L1,L2;
    cout<<"LISTA NUMERO 1:"<<endl;
    construirListaVacia(&L1);
    insertarAlComienzo(14,&L1);
    insertarAlComienzo(15,&L1);
    insertarAlComienzo(1,&L1);
    mostrarLista(L1);
    
    invertirLista(&L1);
    mostrarLista(L1);
    
}
