
 #include <iostream>

using namespace std;

typedef int Elemento;

typedef struct nodo
{
    struct nodo *hizq;  // puntero al hijo izquierdo
    Elemento elem;      // dato
    struct nodo *hder;  // puntero al hijo derecho
} NodoABB;

typedef struct
{
    NodoABB *raiz;   // puntero a la raiz del árbol
} ABB;


void construir( ABB *pA )
{
    pA->raiz = NULL;  // todo arbol empieza vacio
}

NodoABB* crearNodo(Elemento e)
{
    // Todo nodo que se crea siempre es una hoja
    NodoABB* p;
    p = new NodoABB; // Se crea el nuevo nodo en memoria dinámica

    p->hizq = NULL; // El puntero al hijo izquierdo se inicializa como nulo
    p->elem = e; // Se asigna el elemento dado al nodo
    p->hder = NULL; // El puntero al hijo derecho se inicializa como nulo

    return p; // Se retorna la dirección del nodo creado
}


void insertar(ABB* pA, Elemento e)
{
    NodoABB* p, *q, *pq;
    p = crearNodo(e); // Se crea el nuevo nodo con el elemento dado, como una hoja del árbol

    if (pA->raiz == NULL) // Si el árbol está vacío
        pA->raiz = p; // El nodo insertado se convierte en la raíz del árbol
    else // Si el árbol no está vacío
    {
        // Hay que encontrar la ubicación que le corresponde al nuevo nodo
        q = pA->raiz; // Se comienza la búsqueda desde la raíz
        pq = NULL;

        while (q != NULL) // Mientras no se llegue a un nodo nulo
        {
            pq = q; // Se guarda el nodo actual como padre
            if (e < q->elem)
                q = q->hizq; // El elemento es menor, se desciende por el subárbol izquierdo
            else
                q = q->hder; // El elemento es mayor o igual, se desciende por el subárbol derecho
        }

        if (e < pq->elem)
            pq->hizq = p; // El elemento es menor que el nodo padre, se agrega como hijo izquierdo
        else
            pq->hder = p; // El elemento es mayor o igual que el nodo padre, se agrega como hijo derecho
    }
}


// devuelve la dirección del nodo raiz del árbol
NodoABB* obtenerRaiz( ABB A )
{
    return A.raiz;
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
        cout << pR->elem << " ";  // se visita la raiz
        mostrarEnOrden( pAD);  // se recorre en orden el subarbol derecho
    }
}

// muestra el contenido del árbol en preorden
void mostrarEnPreOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        cout << pR->elem << " ";  // se visita la raiz
        mostrarEnPreOrden( pAI);  // se recorre en preorden el subarbol izquierdo
        mostrarEnPreOrden( pAD);  // se recorre en preorden el subarbol derecho
    }
}

// muestra el contenido del árbol en postorden
void mostrarEnPostOrden( NodoABB *pR )  // pR: puntero a la raiz del árbol
{
    NodoABB *pAI, *pAD;
    if ( pR != NULL )
    {
        pAI = pR->hizq;
        pAD = pR->hder;
        mostrarEnPostOrden( pAI);  // se recorre en postorden el subarbol izquierdo
        mostrarEnPostOrden( pAD);  // se recorre en postorden el subarbol derecho
        cout << pR->elem << " ";   // se visita la raiz
    }
}

bool buscar(NodoABB* pR , Elemento e){
	NodoABB* p;
	p=pR;//asignamos el puntero a la raiz del árbol a un puntero aux.

	while (p!=NULL){//Mientras el puntero no sea nulo
		if (e==p->elem)//Encontramos el elemento en la raiz
			return true;
		else//Si no encontramos el elemento en la raiz, buscamos en sus hijos
			if (e<p->elem)//si es menor a la raiz, vamos a la izquierda
				p=p->hizq;
			else
				p=p->hder;//si es mayor, vamos a la derecha
	}
	return false;//No se encontró el elemento.
}

Elemento menor (NodoABB* pR){
	NodoABB* p;
	p=pR; //asignamos el puntero a la raiz del arbol a un puntero aux.
	
	while (p->hizq!=NULL)//Mientras haya un hijo izquierdo
		p=p->hizq;//Avanzamos hacia el siguiente hijo izquierdo
	return p->elem;
}

Elemento mayor (NodoABB* pR){
	NodoABB* p;
	p=pR; //asignamos el puntero a la raiz del arbol a un puntero aux.
	
	while (p->hder!=NULL)//Mientras haya un hijo derecho
		p=p->hder;//Avanzamos hacia el siguiente hijo derecho
	return p->elem;
}

NodoABB* borranodo(NodoABB* pR, Elemento e){
	//Vamos a utilizar recursividad para encontrar el nodo con el valor a eliminar
	
	if (pR==NULL) //CASO BASE
		return NULL; //el nodo actual es nulo, no hay nodos para borrar.
	
	if (e< pR->elem)
		pR->hizq=borranodo(pR->hizq, e);//buscamos el nodo a elminar en el subarbol izquierdo
	else if (e> pR->elem)
		pR->hder=borranodo(pR->hder, e);//buscamos el nodo a elminar en el subarbol derecho
		else{//Encontramos el nodo a eliminar
			if (pR->hizq==NULL){
				//El nodo tiene al menos un hijo en el subarbol derecho
				NodoABB* temp = pR->hder;//nos quedamos con el hijo derecho
				delete pR;//eliminamos la raiz
				return temp;//devolvemos el hijo derecho como nueva raiz
			}
			else if (pR->hder==NULL){
				//El nodo tiene al menos un hijo en el subarbol izquierdo
				NodoABB* temp = pR->hizq;//nos quedamos con el hijo izquierdo
				delete pR;//eliminamos la raiz
				return temp;//devolvemos el hijo izquierdo como nueva raiz
				
			}else{//El nodo tiene a los 2 hijos
				//Entonces vamos a hallar al menor elemento de ese subarbol
				Elemento menor_subarbol=menor(pR->hder);
				pR->elem=menor_subarbol;
				pR->hder=borranodo(pR->hder, menor_subarbol);
			}
		}		
}

int contarnodos(NodoABB* pR){
	NodoABB* p;
	NodoABB *pAI, *pAD;
	p=pR;
	
	int nodosAI, nodosAD;
	
	if (pR==NULL)
		return 0;
	else {
		pAI=pR->hizq;//puntero al subarbol izquierdo
		pAD=pR->hder;//puntero al subarbol derecho
		nodosAI=contarnodos(pAI);//contamos los nodos del subarbol izquierdo
		nodosAD=contarnodos(pAD);//contamos los nodos del subarbol derecho
		return nodosAI+nodosAD + 1; //contamos el nodo mas la cantidad de nodos de sus subarboles izquierdo y derecho
	}
}

int sumanodos(NodoABB* pR){
	NodoABB* p;
	NodoABB *pAI, *pAD;
	p=pR;
	
	int sumaAI, sumaAD;
	
	if (pR==NULL)
		return 0;
	else {
		pAI=pR->hizq;//puntero al subarbol izquierdo
		pAD=pR->hder;//puntero al subarbol derecho
		sumaAI=sumanodos(pAI);//sumamos los nodos del subarbol izquierdo
		sumaAD=sumanodos(pAD);//sumamos los nodos del subarbol derecho
		return sumaAI+sumaAD + pR->elem; //sumamos el nodo mas la suma de los nodos de sus subarboles izquierdo y derecho
	}
}


//////////////////// BALANCEO DE ABB ////////////////////
// Calcula la altura de un nodo
int calcularAltura(NodoABB* nodo) {
    if (nodo == NULL)
        return 0;
    else {
        int alturaIzq = calcularAltura(nodo->hizq);  // Calcula la altura del subárbol izquierdo
        int alturaDer = calcularAltura(nodo->hder);  // Calcula la altura del subárbol derecho
        return max(alturaIzq, alturaDer) + 1;  // Retorna la altura máxima entre los subárboles izquierdo y derecho, más 1 (altura del nodo actual)
    }
}

// Realiza una rotación simple hacia la derecha
NodoABB* rotacionDerecha(NodoABB* nodo) {
    NodoABB* nodoIzq = nodo->hizq;  // Guarda el hijo izquierdo del nodo
    nodo->hizq = nodoIzq->hder;  // El hijo derecho del hijo izquierdo del nodo se convierte en el hijo izquierdo del nodo
    nodoIzq->hder = nodo;  // El nodo se convierte en el hijo derecho del hijo izquierdo del nodo
    return nodoIzq;  // Retorna el nuevo nodo raíz después de la rotación
}

// Realiza una rotación simple hacia la izquierda
NodoABB* rotacionIzquierda(NodoABB* nodo) {
    NodoABB* nodoDer = nodo->hder;  // Guarda el hijo derecho del nodo
    nodo->hder = nodoDer->hizq;  // El hijo izquierdo del hijo derecho del nodo se convierte en el hijo derecho del nodo
    nodoDer->hizq = nodo;  // El nodo se convierte en el hijo izquierdo del hijo derecho del nodo
    return nodoDer;  // Retorna el nuevo nodo raíz después de la rotación
}

// Realiza una rotación doble hacia la derecha
NodoABB* rotacionDobleDerecha(NodoABB* nodo) {
    nodo->hizq = rotacionIzquierda(nodo->hizq);  // Realiza una rotación simple hacia la izquierda en el hijo izquierdo del nodo
    return rotacionDerecha(nodo);  // Realiza una rotación simple hacia la derecha en el nodo
}

// Realiza una rotación doble hacia la izquierda
NodoABB* rotacionDobleIzquierda(NodoABB* nodo) {
    nodo->hder = rotacionDerecha(nodo->hder);  // Realiza una rotación simple hacia la derecha en el hijo derecho del nodo
    return rotacionIzquierda(nodo);  // Realiza una rotación simple hacia la izquierda en el nodo
}


// Balancea un nodo y sus subárboles
NodoABB* balancearNodo(NodoABB* nodo) {
    int alturaIzq = calcularAltura(nodo->hizq);  // Calcula la altura del subárbol izquierdo
    int alturaDer = calcularAltura(nodo->hder);  // Calcula la altura del subárbol derecho
    int diferencia = alturaIzq - alturaDer;  // Calcula la diferencia de altura entre los subárboles

    if (diferencia > 1) {
        // El subárbol izquierdo es más alto
        if (calcularAltura(nodo->hizq->hizq) >= calcularAltura(nodo->hizq->hder))
            nodo = rotacionDerecha(nodo);  // Realiza una rotación simple hacia la derecha
        else
            nodo = rotacionDobleDerecha(nodo);  // Realiza una rotación doble hacia la derecha
    } else if (diferencia < -1) {
        // El subárbol derecho es más alto
        if (calcularAltura(nodo->hder->hder) >= calcularAltura(nodo->hder->hizq))
            nodo = rotacionIzquierda(nodo);  // Realiza una rotación simple hacia la izquierda
        else
            nodo = rotacionDobleIzquierda(nodo);  // Realiza una rotación doble hacia la izquierda
    }

    return nodo;  // Retorna el nodo balanceado
}

// Balancea todo el árbol llamando a balancearNodo recursivamente en cada nodo
NodoABB* balancearArbol(NodoABB* raiz) {
    if (raiz == NULL)
        return NULL;

    raiz->hizq = balancearArbol(raiz->hizq);  // Balancea el subárbol izquierdo
    raiz->hder = balancearArbol(raiz->hder);  // Balancea el subárbol derecho

    raiz = balancearNodo(raiz);  // Balancea el nodo actual

    return raiz;  // Retorna la raíz del árbol balanceado
}

//////////////////// BALANCEO DE ABB ////////////////////

void imprimirArbol(NodoABB* pR, int nivel = 0) {
    // Verificar si el nodo es nulo, en ese caso no hay nada que imprimir y se retorna
    if (pR == NULL)
        return;

    // Imprimir el subárbol derecho, incrementando el nivel en 1
    imprimirArbol(pR->hder, nivel + 1);

    // Imprimir espacios en blanco para indentar el nodo actual según su nivel
    for (int i = 0; i < nivel; i++)
        cout << "    ";
    
    // Imprimir el elemento del nodo actual
    cout << pR->elem << endl;

    // Imprimir el subárbol izquierdo, incrementando el nivel en 1
    imprimirArbol(pR->hizq, nivel + 1);
}




//////////
// MAIN //
//////////
int main()
{
    ABB A1;
    NodoABB *pRA1;
    
    construir(&A1);
    
    insertar(&A1, 3);
    insertar(&A1, 10);
    insertar(&A1, 15);
    insertar(&A1, 5);
    insertar(&A1, 7);
    insertar(&A1, 13);
    insertar(&A1, 20);
    insertar(&A1, 16);
    insertar(&A1, 11);
    insertar(&A1, 17);
    insertar(&A1, 9);
    insertar(&A1, 22);
    insertar(&A1, 25);
    insertar(&A1, 27);
    insertar(&A1, 30);
    insertar(&A1, 12);
    insertar(&A1, 14);
    insertar(&A1, 18);
    insertar(&A1, 19);
    insertar(&A1, 100);
    insertar(&A1, 90);
    insertar(&A1, 80);
    
    
    
    
    pRA1 = obtenerRaiz(A1);
    
    cout << "Árbol original:" << endl;
    mostrarEnOrden(pRA1);
    cout << endl;
    imprimirArbol(pRA1);
    
    cout << endl << "Balanceando el árbol..." << endl;
    pRA1 = balancearArbol(pRA1);  // Balancea el árbol A1
    
    //pRA1 = obtenerRaiz(A1);
    
    cout << "Árbol balanceado:" << endl;
    mostrarEnOrden(pRA1);
    cout << endl;
    imprimirArbol(pRA1);
    
    return 0;
}




