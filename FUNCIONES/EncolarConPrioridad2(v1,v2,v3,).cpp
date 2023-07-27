//COLA CON PRIORIDAD -- 2022.1
//EJEMPLO : V 1, V 2, V 3, C 1, C 2, C 3, N 1, N 2, N 3

void encolarConPrioridad( Cola &pC, ElemBanco e , NodoC * &UltimoVip, NodoC * &UltimoCli)
{
    NodoC *p, *pU;
    p = crearNodo( e, NULL);
    if ( esColaVacia(pC) )
    {
        pC.frente = p;
        if(e.tipoCliente=='V') 
            UltimoVip = p;
        else if(e.tipoCliente =='C') 
            UltimoCli = p;
        pC.final = p; // el unico // ultimo No cliente
    }
    else
    {
        //cuando la cola no esta vacia, debemos comprar el elemento con los demas que estane en la cola
        if(e.tipoCliente=='N'){ //Si no es cliente, solo lo encolo (lo mando al final de la cola)
            encolar(pC, e);//al final -> pC.final
        }else if(e.tipoCliente=='V'){
            if(UltimoVip==NULL){
                p->sig = pC.frente;
                pC.frente = p;               
            }else{
                p->sig = UltimoVip->sig;
                UltimoVip->sig = p;                
            }
            UltimoVip = p;
        }else if(e.tipoCliente=='C'){
             if(UltimoCli==NULL){
                 p->sig = UltimoVip->sig;
                 UltimoVip->sig = p;                 
                 if(p->sig==NULL) pC.final = p;
             }else{
                 p->sig = UltimoCli->sig;
                 UltimoCli->sig = p;
             }             
             UltimoCli = p;
        }
    }
   
    
    pC.longitud++;//QUEDA
}
