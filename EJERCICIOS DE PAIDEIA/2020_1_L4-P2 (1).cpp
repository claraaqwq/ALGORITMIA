 #include <iostream>

using namespace std;

typedef struct nodo
{
    struct nodo *hizq;  // puntero al hijo izquierdo
    int lote;      		// dato1
    int cantidad;      	// dato2
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

NodoABB* crearNodo(int lote, int cantidad)
{
    // Todo nodo que se crea siempre es una hoja
    NodoABB* p;
    p = new NodoABB; // Se crea el nuevo nodo en memoria dinámica

    p->hizq = NULL; 		// El puntero al hijo izquierdo se inicializa como nulo
    p->lote = lote;			// Se asigna el elemento1 dado al nodo
    p->cantidad = cantidad; // Se asigna el elemento2 dado al nodo
    p->hder = NULL; 		// El puntero al hijo derecho se inicializa como nulo

    return p; // Se retorna la dirección del nodo creado
}

NodoABB* insertarRecursivo(NodoABB* pR, int lote, int cantidad)
{
    if (pR == NULL) {
        // Creamos un nuevo nodo y lo retornamos como resultado de la inserción
        return crearNodo(lote, cantidad);
    } else if (lote < pR->lote) {
        // Insertamos en el subárbol izquierdo y actualizamos el puntero al hijo izquierdo
        pR->hizq = insertarRecursivo(pR->hizq, lote, cantidad);
    } else {
        // Insertamos en el subárbol derecho y actualizamos el puntero al hijo derecho
        pR->hder = insertarRecursivo(pR->hder, lote, cantidad);
    }
    
    // Retornamos el puntero al nodo raíz después de realizar la inserción
    return pR;
}


void insertar(ABB* pA, int lote, int cantidad)
{
    NodoABB* p, *q, *pq;
    p = crearNodo(lote, cantidad); // Se crea el nuevo nodo con el elemento dado, como una hoja del árbol

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
            if (lote < q->lote)
                q = q->hizq; // El elemento es menor, se desciende por el subárbol izquierdo
            else
                q = q->hder; // El elemento es mayor o igual, se desciende por el subárbol derecho
        }

        if (lote < pq->lote)
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
        cout << "( " << pR->lote << " - " << pR->cantidad << " )  ";  // se visita la raiz
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
        cout << "( " << pR->lote << " - " << pR->cantidad << " )  ";  // se visita la raiz
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
        cout << "( " << pR->lote << " - " << pR->cantidad << " )  ";  // se visita la raiz
    }
}

bool buscar(NodoABB* pR , int lote){
	NodoABB* p;
	p=pR;//asignamos el puntero a la raiz del árbol a un puntero aux.

	while (p!=NULL){//Mientras el puntero no sea nulo
		if (lote==p->lote)//Encontramos el elemento en la raiz
			return true;
		else//Si no encontramos el elemento en la raiz, buscamos en sus hijos
			if (lote<p->lote)//si es menor a la raiz, vamos a la izquierda
				p=p->hizq;
			else
				p=p->hder;//si es mayor, vamos a la derecha
	}
	return false;//No se encontró el elemento.
}

NodoABB* menor (NodoABB* pR){
	if (pR==NULL)
		return NULL;
	else
	{
		if(pR->hizq!=NULL)
			return (menor(pR->hizq));
		else
			return pR;		
	}
}


NodoABB* borranodo(NodoABB* pR, int lote) {
    // Vamos a utilizar recursividad para encontrar el nodo con el valor a eliminar

    if (pR == NULL)
        return pR; // El nodo actual es nulo, no hay nodos para borrar. (Caso base)

    if (lote < pR->lote)
        pR->hizq = borranodo(pR->hizq, lote); // Buscamos el nodo a eliminar en el subárbol izquierdo
    else if (lote > pR->lote)
        pR->hder = borranodo(pR->hder, lote); // Buscamos el nodo a eliminar en el subárbol derecho
    else {
        // Encontramos el nodo a eliminar
        if (pR->hizq == NULL) {
            // El nodo tiene al menos un hijo en el subárbol derecho
            NodoABB* temp = pR->hder; // Nos quedamos con el hijo derecho
            delete pR; // Eliminamos la raíz
            return temp; // Devolvemos el hijo derecho como nueva raíz
        }
        else if (pR->hder == NULL) {
            // El nodo tiene al menos un hijo en el subárbol izquierdo
            NodoABB* temp = pR->hizq; // Nos quedamos con el hijo izquierdo
            delete pR; // Eliminamos la raíz
            return temp; // Devolvemos el hijo izquierdo como nueva raíz
        }
        else {
            // El nodo tiene ambos hijos
            // Entonces vamos a hallar el menor elemento de ese subárbol derecho
            NodoABB* temp = menor(pR->hder); // Buscamos el nodo con el valor mínimo
            pR->lote = temp->lote; // Reemplazamos el valor del nodo actual con el valor mínimo
            pR->hder = borranodo(pR->hder, temp->lote); // Eliminamos el nodo mínimo del subárbol derecho
        }
    }
}


void despachar(NodoABB* pR, int cantidad) {
 	int falta, lote; // Variable para almacenar la cantidad restante y el lote del nodo actual
    NodoABB* pAux; // Puntero auxiliar para realizar operaciones en el árbol


    if (cantidad == 0)
        return; // Si la cantidad es cero, no hay nada más que despachar.

    pAux = pR; // Inicializamos el puntero auxiliar con la raíz del árbol.
    pAux = menor(pAux); // Buscamos el nodo con el valor mínimo en el árbol.

    if (pAux->cantidad <= cantidad) {
        // Si la cantidad en el nodo es menor o igual a la cantidad que queremos despachar.
        falta = cantidad - pAux->cantidad; // Calculamos la diferencia entre la cantidad que queremos despachar y la cantidad en el nodo.
        lote = pAux->lote; // Guardamos el valor del lote del nodo.
        pR = borranodo(pR, lote); // Eliminamos el nodo con el lote del despacho del árbol.
        despachar(pR, falta); // Llamamos recursivamente a la función para despachar la cantidad restante.
    }
    else {
        pAux->cantidad = pAux->cantidad - cantidad; // Restamos la cantidad que queremos despachar a la cantidad en el nodo.
    }
}

//NUEVO//

// Función para buscar un nodo en un árbol binario de búsqueda (ABB) por su lote
NodoABB* buscarNodo(NodoABB* pR, int lote) {
    // Si la raíz es nula o el lote del nodo es igual al lote buscado, se ha encontrado el nodo
    if (pR == NULL || pR->lote == lote) {
        return pR;
    }
    
    // Si el lote buscado es menor que el lote del nodo raíz, se busca en el subárbol izquierdo
    if (lote < pR->lote) {
        return buscarNodo(pR->hizq, lote);
    } else { // Si no, se busca en el subárbol derecho
        return buscarNodo(pR->hder, lote);
    }
}

// Función para fusionar dos árboles binarios de búsqueda (ABB)
void fusionar(NodoABB* pR1, NodoABB* pR2) {
    int lote, cantidad;
    NodoABB* pAux;
    pAux = pR2;
    // Si el nodo auxiliar es válido (no es nulo), se realiza la fusión
    if (pAux) {
        // Se fusiona el subárbol izquierdo del nodo auxiliar con el árbol pR1
        fusionar(pR1, pAux->hizq);
        // Se fusiona el subárbol derecho del nodo auxiliar con el árbol pR1
        fusionar(pR1, pAux->hder);
        // Se obtiene el lote y la cantidad del nodo auxiliar
        lote = pAux->lote;
        cantidad = pAux->cantidad;
        // Se elimina el nodo auxiliar
        delete pAux;
        // Se busca si ya existe un nodo con el mismo lote en el árbol pR1
        NodoABB* nodoExistente = buscarNodo(pR1, lote);
        // Si se encuentra un nodo existente con el mismo lote, se suma la cantidad
        if (nodoExistente) {
            nodoExistente->cantidad += cantidad;
        } else { // Si no se encuentra un nodo existente con el mismo lote, se inserta un nuevo nodo en el árbol pR1
            pR1 = insertarRecursivo(pR1, lote, cantidad); // Se asume que existe una función llamada "insertarRecursivo"
        }
        // Se asigna nulo al árbol pR2, ya que se ha fusionado con pR1
        pR2 = NULL;
    }
}


//FIN NUEVO//


//////////
// MAIN //
//////////
int main()
{
    ABB A1,A2;
    NodoABB *pRA1, *pRA2;
    int lote, cantidad, menorA1, mayorA1;
    int nodosA1, sumaA1;
   
    construir( &A1 );
    cout << "Arbol vacio" << endl;
   
    insertar( &A1, 10, 20);
    insertar( &A1, 8, 20);
    insertar( &A1, 5, 10);
    insertar( &A1, 15, 10);
    insertar( &A1, 3, 10);

   
    pRA1 = obtenerRaiz(A1);
   
    cout << endl << "Recorrido en orden" << endl;
    cout << "se visita primero subárbol izquierdo en en-orden, el nodo raíz y el subárbol derecho en en-orden." << endl;
   
    mostrarEnOrden( pRA1 );
    
    
    
    
        construir( &A2 );
    cout << "Arbol vacio" << endl;
   
    insertar( &A2, 9, 20);
    insertar( &A2, 8, 5);
    insertar( &A2, 4, 10);
    insertar( &A2, 11, 10);

   
    pRA2 = obtenerRaiz(A2);
   
    cout << endl << "Recorrido en orden" << endl;
    cout << "se visita primero subárbol izquierdo en en-orden, el nodo raíz y el subárbol derecho en en-orden." << endl;
   
    mostrarEnOrden( pRA2 );
    
    
   
    /*cout << endl << endl << "Recorrido en pre orden" << endl;
    cout << "se visita primero el nodo raíz y después los subárboles izquierdo en pre-orden y derecho en pre-orden." << endl;
    mostrarEnPreOrden( pRA1 );
   
    cout << endl << endl << "Recorrido en post orden" << endl;
    cout << "se visita primero subárbol izquierdo en post-orden, el subárbol derecho en post-orden y el nodo raíz" << endl;
    mostrarEnPostOrden( pRA1 );
    
    */
    despachar(pRA1, 10);
    
    
    cout << endl << "DESPACHO - Recorrido en orden" << endl;
    cout << "se visita primero subárbol izquierdo en en-orden, el nodo raíz y el subárbol derecho en en-orden." << endl;
   
    mostrarEnOrden( pRA1 );
    
    fusionar (pRA1, pRA2);
    cout << endl << "FUSIONAR - Recorrido en orden" << endl;
   	mostrarEnOrden( pRA1 );
    /*
    cout << endl << endl <<"Ingrese el lote a buscar en el arbol: "<<endl;
    cin >> lote;
	if (buscar(pRA1 ,lote))
		cout << "Se encontro en el arbol "<<endl;
	else
		cout << "NO se encontro en el arbol "<<endl;
	
	menorA1 = menor (pRA1);
	cout << endl  <<"El menor elemento es: " << menorA1 <<endl;

	mayorA1 = mayor (pRA1);
	cout << endl  <<"El menor elemento es: " << mayorA1 <<endl;
	
	
	//VAMOS A BORRAR NODOS!!!!!
	pRA1=borranodo(pRA1, lote);
	cout << endl << endl << "Recorrido en pre orden" << endl;
    cout << "se visita primero el nodo raíz y después los subárboles izquierdo en pre-orden y derecho en pre-orden." << endl;
    mostrarEnPreOrden( pRA1 );
    
    nodosA1=contarnodos(pRA1);
	cout << endl << endl << "Numero de nodos: " << nodosA1 << endl;

    sumaA1=sumanodos(pRA1);
    cout << endl << endl << "Suma de los nodos: " << sumaA1 << endl;
	*/
    return 0;
}




