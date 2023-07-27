#include <iostream>
#define N 5

using namespace std;

typedef struct {
	int digito;
	int valor;
}Elemento;

typedef struct nodo{
	Elemento elem;
	struct nodo *hizq;
	struct nodo *hder;
}NodoAB;

typedef NodoAB *AB;

void construir(AB &pA)
{
    pA = NULL;  // todo arbol empieza vacio
}

NodoAB *crearNodoAB(Elemento dato,AB hijoIzq, AB hijoDer){
	NodoAB *nuevo = new NodoAB;
	nuevo->elem.digito = dato.digito;
	nuevo->elem.valor = dato.valor;
	nuevo->hder = hijoDer;
	nuevo->hizq = hijoIzq;
	return nuevo;
}

void insertaElementos(AB &ptrArbol,int paquetes[N],int indice,int size){
	Elemento elemento;
	if (indice==size){
		return;
	}
	elemento.digito = 0;
	elemento.valor = paquetes[indice];
	/*Vamos a colocar el elemento 0 a la izquierda*/
	NodoAB *nodoIzq = crearNodoAB(elemento,NULL,NULL);
	ptrArbol->hizq = nodoIzq;
	/*Vamos a colocar el elemento 1 a la derecha*/
	elemento.digito = 1;
	elemento.valor = paquetes[indice];
	NodoAB *nodoDer = crearNodoAB(elemento,NULL,NULL);
	ptrArbol->hder = nodoDer;
	/*Aqui hacemos la recursion para crear los siguientes niveles*/
	insertaElementos(ptrArbol->hizq,paquetes,indice+1,size);
	insertaElementos(ptrArbol->hder,paquetes,indice+1,size);
}

void crearArbolBinario(AB &ptrArbol,int paquetes[N],int size){
	Elemento elemento;
	elemento.digito = 0;
	elemento.valor = 0;
	/*Con esto hemos insertado la raiz*/
	NodoAB *nuevoNodo = crearNodoAB(elemento,NULL,NULL);
	ptrArbol = nuevoNodo;
	
	/*Vamos a insertar todos los elementos del arreglo en el archivo binario*/
	insertaElementos(ptrArbol,paquetes,0,size);
}

// muestra el contenido del árbol en preorden
void mostrarEnPreOrden( NodoAB *pR )  // pR: puntero a la raiz del árbol
{
    NodoAB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        cout << pR->elem.valor << " ";  // se visita la raiz
        mostrarEnPreOrden(pAI);  // se recorre en preorden el subarbol izquierdo
        mostrarEnPreOrden(pAD);  // se recorre en preorden el subarbol derecho
    }
}

/*Propuesto por Jhairt Vega, pero ojo, calcula el doble de combinaciones jijiji*/
void hallarCombinaciones(AB &ab, int peso_maximo, int &cant, int sum){
    if(ab != NULL){
        sum += ab->elem.digito*ab->elem.valor;
        hallarCombinaciones(ab->hizq, peso_maximo, cant, sum);
        hallarCombinaciones(ab->hder,peso_maximo, cant, sum);
    }else{
        if(sum == peso_maximo){
            cant++;
        }
    }
}

int main(){
	AB ptrArbol;
	int paquetes[N] = {10,50,20,30,40};
	int size = 5, peso=70, cant=0, sum=0;
	
	
	/*Parte a*/
	construir(ptrArbol);
	crearArbolBinario(ptrArbol,paquetes,size);
	/*mostrarEnPreOrden(ptrArbol);*/
	hallarCombinaciones(ptrArbol,peso,cant,sum);
	cout << "El numero de combinaciones es: " << cant/2 << endl;
}
