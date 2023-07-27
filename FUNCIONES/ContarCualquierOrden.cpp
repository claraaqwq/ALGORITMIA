int ContarPizzasBuenas(int ini, int fin, int ArrEstadosPizza[M],int cont){
    //realizo condicion de parada
    if(ini>=fin) {
        if(ArrEstadosPizza[ini]==1) return cont+1;
        else return cont; //retorna solo lo que encontró
    }
    //empiezo por el medio
    int med = (ini+fin)/2;
    //¿A donde me voy?
    if(ArrEstadosPizza[ini]==1){ //debo ir al lado izquierdo
        if(ArrEstadosPizza[med]==0){
            return ContarPizzasBuenas(ini,med-1,ArrEstadosPizza,0); //está contando los 1's
        }else{
            //Caso que el medio sea 1
            return ContarPizzasBuenas(ini,med-1,ArrEstadosPizza,cont+1)+ContarPizzasBuenas(med+1,fin,ArrEstadosPizza,0);
        }
            
    }else if(ArrEstadosPizza[fin]==1){ //debo ir al lado derecho
        if(ArrEstadosPizza[med]==0)
            return ContarPizzasBuenas(med+1,fin,ArrEstadosPizza,cont+1);
        else{
           return ContarPizzasBuenas(med+1,fin,ArrEstadosPizza,cont)+ContarPizzasBuenas(ini+1,med-1,ArrEstadosPizza,0); 
        }
    }
}
