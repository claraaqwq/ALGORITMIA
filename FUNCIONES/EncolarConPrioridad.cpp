//ENCOLAR CON PRIORIDAD -> 2020.2
//EJEMPLO : V 1, V 2, V 3, C 1, C 2, C 3, N 1, N 2, N 3
//NO USO NODO CON NEW, LO ENCOLO EN OTRA COLSA
void encolarConPrioridad( Cola &pC, ElemPro e )
{
    NodoC *p, *pU;
    p = crearNodo( e, NULL);
    if ( esColaVacia(pC) )
    {
        pC.frente = p;
    }
    else
    {
        NodoC *aux = pC.frente;
        NodoC *ant = NULL;
        while(aux!=NULL){
            if(aux->elem.tipoLote<p->elem.tipoLote){
                ant = aux;
                aux = aux->sig;
                if(aux==NULL){
                    ant->sig = p;
                    pC.cola = p;
                }/*else{
                    ant = aux;
                }*/
                
            }else{
                //CASO QUE TENGA MAYOR PRIORIDAD O SEAN IGUALES
                if(aux->elem.tipoLote > p->elem.tipoLote){
                    if(ant==NULL){
                        p->sig = pC.frente; //El que estaba en la cabeza pasa a ser dps del p
                        //Actualizo la cabeza de la cola
                        pC.frente = p;
                    }else{
                        p->sig = ant->sig;
                        ant->sig = p;
                    }
                    break;
                }else if (aux->elem.tipoLote == p->elem.tipoLote){
                    //SI LAS LETRAS SON IGUALES, COMPARO CODIGOS
                    if(aux->elem.codigo > p->elem.codigo){
                        p->sig = aux; //estoy agregando al p antes del aux
                        if (ant==NULL){ //ME ENCUENTRO EN LA CABEZA
                            pC.frente = p; //Actualizo el nodo en la cabeza de la cola
                        }else{
                            ant->sig = p; //el anterior ahora apunta al que agregué
                        }
                        break;
                        
                    }else if(aux->elem.codigo < p->elem.codigo){
                        if(aux->sig == NULL){
                            aux->sig = p;
                            pC.cola = p;
                            break;
                        }
                        if(p->elem.codigo < aux->sig->elem.codigo || aux->sig->elem.tipoLote!=p->elem.tipoLote){
                            p->sig = aux->sig;
                            aux->sig = p;
                            break;
                        }else{
                            aux = aux->sig;
                        }
                    }
                }
                
                
            }
        }
    }
    //pC.cola = p;
    pC.longitud++;
}

