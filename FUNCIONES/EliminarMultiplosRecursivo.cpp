//ELIMINAR MULTIPLOS CON RECURSIVIDAD
void EliminarMultiplos(Lista &lista, int index){
    
    Cola cola;
    construir(cola);
    
    //Nodo de inicio:
    Nodo *nodo = lista.cabeza; //empiezo en la cabeza -> 2
    for(int i=0;i<index;i++) nodo = nodo->sig; //empiezo en el 3-> 2da iteracion
    
    //Caso parada:
    if(nodo==NULL) return;
    
    int dato = nodo->elem; //2;
    nodo = nodo->sig; //ahora estoy en el 3
    
    
    //voy recorriendo los nodos
    while(nodo!=NULL){
        int datoNodo = nodo->elem; //guardo al 3 en un int 
        nodo = nodo->sig;
        //(  3  %  2  == 0  ) --> 1
        // datoNodo = 3
        if(datoNodo % dato == 0){//son multiplos
            encolar(cola,datoNodo); //lo agrego a otra cola y lo elimino de la lista
            eliminar(lista,datoNodo);
            //CLASE 2: 2:21:06
            
        }
    }
    
    //imprime
    cout<<"Numero Procesado: "<<dato<<" ";
    cout<<"Numeros tachados para el "<<dato<<": ";
    mostrar(cola);
    
    EliminarMultiplos(lista,index+1);
}
