void LeerPedidos(Lista &lunes,Lista &martes,Lista &miercoles,Lista &jueves,Lista &viernes){
    ifstream archPedidos ("datosP1.txt",ios::in);
    
    LeerPedidoDia(lunes,archPedidos,1);
    //mostrar(lunes);
    LeerPedidoDia(martes,archPedidos,2);
    //mostrar(martes);
    LeerPedidoDia(miercoles,archPedidos,3);
    //mostrar(miercoles);
    LeerPedidoDia(jueves,archPedidos,4);
    //mostrar(jueves);
    LeerPedidoDia(viernes,archPedidos,5);
    //mostrar(viernes);
}

void LeerPedidoDia (Lista &dia,ifstream &archPedidos, int d){
    int hora, sucursal;
    char c;
    while(true){
        archPedidos>>hora>>c>>sucursal;
        //1. Crear Nodo
        Pedido pedido;
        pedido.hora = hora;
        pedido.sucursal = sucursal;
        pedido.dia = d;
        //agrego pedido a la lista, mientras voy ordenando
        insertarOrdenado(dia,pedido);
        
        if(archPedidos.get()=='\n')break; //cuando vea un salto de linea acaba de leer el pedidoXdia
        
    }
    //ordenar esa lista de pedidos mientras voy agregando
    
}
/**/
void FusionarListas(Lista &lunes,Lista &martes,Lista &miercoles,Lista &jueves,Lista &viernes){
    Fusionar2Listas(lunes,martes);
    Fusionar2Listas(lunes,miercoles);
    Fusionar2Listas(lunes,jueves);
    Fusionar2Listas(lunes,viernes);
    mostrar(lunes);
    
}

void Fusionar2Listas(Lista &Principal, Lista &Secundaria){
    
    Nodo *nodoSec = Secundaria.cabeza;
    
    Nodo *nodoPrin = Principal.cabeza;
    Nodo *nodoAnt = NULL;
    
    while(nodoSec!=NULL){
        if(nodoPrin!=NULL){
            if(nodoSec->elem.hora < nodoPrin->elem.hora){

                Nodo *copiaSec = crearNodo(nodoSec->elem, NULL);


                //añadir al principal
                nodoAnt->sig = copiaSec;
                copiaSec->sig = nodoPrin;
                nodoAnt = copiaSec;
                nodoSec = nodoSec->sig;
                Principal.longitud++;
            }else{
                nodoAnt = nodoPrin;
                nodoPrin = nodoPrin->sig;
            }
        }else{
            //el elemento que queires añadir ira al final
            insertarFinal(Principal, nodoSec->elem);
             nodoSec = nodoSec->sig;
        }
    }
}
