//INSERTAR ORDENADO EN LISTA ENLAZADA
void insertarOrdenado( Lista &pL, Elemento e )
{
    Nodo *p, *pU,*nodoAnt;
    p = crearNodo( e, NULL);
    if ( esListaVacia(pL) ){
        pL.cabeza = p;
        pL.cola = p;
    }
    else
    {
        pU = pL.cabeza;
        nodoAnt = NULL;     
        while(pU!=NULL){
            if(pU->elem.hora < e.hora){
                nodoAnt = pU;
                pU = pU->sig;
            }else{
                if(nodoAnt!=NULL){
                    nodoAnt->sig = p;
                    pL.cabeza = p;
                }else{
                    p->sig = pU;
                    pL.cabeza = p;
                }
                break;
            }
        }
        
        if(pU==NULL){
            nodoAnt->sig = p;
            pL.cola = p;
        }
    }
    pL.longitud++;
}
