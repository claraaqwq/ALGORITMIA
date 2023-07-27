
Elem eliminar_menor(ABB &A){
	Elem e;
	if(A.raiz == NULL){
		e.fecha = 0;
		e.stock = 0;
		return e;
	}else{
		Nodo *AUX = A.raiz;
		if(AUX->izq == NULL){
			if(AUX->der != NULL){
				A.raiz = AUX->der;
			}else{
				A.raiz = NULL;
			}
			e = AUX->E;
			delete AUX;
		}else{
			Nodo *ant = NULL,*pos_der = NULL,*pos=AUX,*raiz_der = AUX->der = AUX->der, *raiz_izq = AUX->izq;
			//Encontrar el nodo más pequeño en el subArbolDerecho
			while(raiz_izq!=NULL){
				ant = pos;
				pos = raiz_izq;
				raiz_izq = raiz_izq->izq;
			}
			//Realizar los enlaces necesarios para eliminar el nodo Encontrado
			if(ant!=NULL){
				ant->izq = pos->der;
			}else{
				AUX->izq = pos->der;
			}
			e = pos->E;
			delete pos;
		}
	}
	return e;
}
