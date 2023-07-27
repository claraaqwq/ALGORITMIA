#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct NodoPila {
    int valor;
    struct NodoPila *ptrSig; //estructura auto-referenciada
} TNodoPila;

typedef TNodoPila* Tpila;

void crear(Tpila* ptrpila) {
    *ptrpila = NULL;
}

void push(Tpila* Pila, int valor) {
    TNodoPila* ptrNuevo;
    ptrNuevo = new TNodoPila;
    ptrNuevo->valor = valor;
    ptrNuevo->ptrSig = *Pila;
    *Pila = ptrNuevo;
}

bool pila_vacia(Tpila* ptrPila) {
    return *ptrPila == NULL;
}

void top(Tpila* ptrPila) {
    TNodoPila* ptrrec;
    ptrrec = *ptrPila;
    if (pila_vacia(ptrPila))
        cout << "Pila vacia" << endl;
    else
        cout << ptrrec->valor << endl;
}

int pop(Tpila* Pila) {
    TNodoPila* ptrEliminar;
    int valor;
    if (!pila_vacia(Pila)) {
        ptrEliminar = *Pila;
        valor = ptrEliminar->valor;
        *Pila = ptrEliminar->ptrSig;
        free(ptrEliminar);
    }
    return valor;
}

void finalizar(Tpila ptrPila) {
    TNodoPila* ptrEliminar;
    ptrEliminar = ptrPila;
    while (ptrEliminar != NULL) {
        ptrPila = ptrEliminar->ptrSig;
        delete ptrEliminar;
        ptrEliminar = ptrPila;
    }
}

void cambia(Tpila ptrPila, int n) {
    ptrPila->valor = n;
}

void imprimepila(Tpila ptrpila) {
    while (ptrpila != NULL) {
        cout << ptrpila->valor << " ";
        ptrpila = ptrpila->ptrSig;
    }
}

void imprimepila2(Tpila ptrPila) {
    Tpila ptraux;
    if (ptrPila == NULL)
        return;
    ptraux = ptrPila;
    ptrPila = ptrPila->ptrSig;
    imprimepila(ptrPila);
    cout << ptraux->valor << " ";
}

void pasapila (Tpila *Pila1, Tpila *Pila2){
	int derecha, izquierda;//manos del operario a utilizar
	int contador;
	
	while (!pila_vacia(Pila1)){//Sacamos los productos de Pila1
		derecha=pop(Pila1);//ponemos en la mano derecha cada producto
		contador=1;//OJO para revisar
		while (!pila_vacia(Pila1)){
			push(Pila2, derecha);//Ponemos en la Pila 2 desde mano derecha
			contador++;//cada vez que sacamos de Pila 1, aumentamos
			derecha=pop(Pila1);//ponemos en la mano derecha cada producto
		}
		izquierda=derecha;//pasamos el producto de la mano derecha a la izquierda
						  //"guardamos" el producto en la mano izquierda
		while (!pila_vacia(Pila2)&&contador>1){
			derecha=pop(Pila2);//tomamos con la mano derecha desde Pila2
			push(Pila1, derecha);//ponemos el producto en Pila1
			contador--;
		}
		push(Pila2, izquierda);//ponemos en Pila2 desde la mano izquierda		
	}
}
int main() {
    Tpila ptrPila, ptrPila2;
    crear(&ptrPila);
    top(&ptrPila);
    push(&ptrPila, 19);
    push(&ptrPila, 18);
    push(&ptrPila, 17);
    push(&ptrPila, 20);
  
  	cout<<"Pila 1: ";
    imprimepila(ptrPila);
    cout<<endl;
    cout<<"Pila 2: ";
    imprimepila(ptrPila2);
    cout<<endl;
    pasapila(&ptrPila, &ptrPila2);
    
    cout<<"Pila 1: ";
    imprimepila(ptrPila);
    cout<<endl;
    cout<<"Pila 2: ";
    imprimepila(ptrPila2);
  	cout<<endl;
    finalizar(ptrPila);

    return (0);
}
