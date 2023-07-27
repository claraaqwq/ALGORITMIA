void fusionar(Lista  &L1, Lista &L2){
    if(L1.cola->elem < L2.cabeza->elem ){ //L1 contiene solo elementos menores a L2
            L1.cola->sig = L2.cabeza;
            L1.cola = L2.cola;
    }
    else 
        if(L2.cola->elem < L1.cabeza->elem){ //L2 contiene solo elementos menores a L1
            L2.cola->sig = L1.cabeza;
            L1.cabeza = L2.cabeza;
        }
        else{ //Hay que fusionar
            Nodo *F_ini, *F_fin;
            F_ini = NULL; 
            F_fin = NULL; 

            //Su forma de recorrer es en zigzag, dependiendo de quien es el mayor
            //solo va cambiando el nuevo lugar del fin y recorre en puntero normal al sig
            while(!esListaVacia(L1) && !esListaVacia(L2)){
                if(L1.cabeza->elem <= L2.cabeza->elem){ //Pasa L1
                        if(F_ini==NULL){
                                F_ini = L1.cabeza;
                                F_fin = L1.cabeza;
                        }else{
                                F_fin->sig = L1.cabeza;
                                F_fin = L1.cabeza;
                        }
                        L1.cabeza = L1.cabeza->sig;
                }
                else 
                    if(L1.cabeza->elem > L2.cabeza->elem){
                        if(F_ini==NULL){
                            F_ini = L2.cabeza;
                        F_fin = L2.cabeza;
                        }
                        else{
                            F_fin->sig = L2.cabeza;
                            F_fin = L2.cabeza;
                        }
                        L2.cabeza = L2.cabeza->sig;
                }
            }
            
            //CASO QUE UNA LISTA TENGA MÁS ELEMENTOS QUE OTRA
            //Puede ser que alguna lista aun tenga elementos, repasamos ambas
            while(!esListaVacia(L1)){
                if(F_ini==NULL){
                    F_ini = L1.cabeza;
                    F_fin = L1.cabeza;
                }
                else{
                    F_fin->sig = L1.cabeza;
                    F_fin = L1.cabeza;
                }
                L1.cabeza = L1.cabeza->sig;
            }

            while(!esListaVacia(L2)){
                if(F_ini==NULL){
                    F_ini = L2.cabeza;
                    F_fin = L2.cabeza;
                }
                else{
                    F_fin->sig = L2.cabeza;
                    F_fin = L2.cabeza;
                }
                L2.cabeza = L2.cabeza->sig;
            }
            
            L1.cabeza = F_ini;
            L1.cola = F_fin;
        }
}
