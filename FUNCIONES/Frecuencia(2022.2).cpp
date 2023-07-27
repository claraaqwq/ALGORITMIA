//FRECUENCIAS -> GRAFICO -> 2022.2

   int calcularFrecMaxima(int frecuencias[N], int size, int &duracion, double &area){
	int frecMax, frec, indiceFrecMax, duracionActual;
	double areaActual, areaMax=0;
	Pila ptrPila; //construyo la pila
	construir(ptrPila); //Lleno los datos
        
        int i = 0;        //  i es 11
	while (i<size){
            //La i me indica que frecuencia voy a tomar
                //    false                    ||             6           <=       4
		if (esPilaVacia(ptrPila) || frecuencias[top(ptrPila)]<=frecuencias[i]){
			apilar(ptrPila,i); //guardo al indice
			i++; //i es 1->2
		}
		else {//hubo una caida en la frecuencia
                    //Desapila el ultimo elemento insertado
			indiceFrecMax = desapilar(ptrPila);// 8 -> 1
			frec = frecuencias[indiceFrecMax];// 2 -> 2
			if (esPilaVacia(ptrPila)){
				areaActual = frec*i;
				duracionActual = i;
			}
			else { //Para calcular el area actual
				areaActual = frec*(i-indiceFrecMax);// 2*2 = 4
				duracionActual = i-indiceFrecMax;// 1
			}
                        // 0 < 2
			if (areaMax<areaActual){
                            //sirven para hacer la logica
				areaMax = areaActual;//20 -> 2
				frecMax = frec;//4 -> 2
                                
				duracion = duracionActual;//5 -> 1
				area = areaMax;//actualizo la variable del area en la funcion
			}
		}
	}
	//------------------------------------------------------------------------------------------
                   
                   
    while (!esPilaVacia(ptrPila)){
        indiceFrecMax = desapilar(ptrPila);//0
        frec = frecuencias[indiceFrecMax];//1
        if (esPilaVacia(ptrPila)){
                areaActual = frec*i;
                duracionActual = i;
        }
        else {
                areaActual = frec*(i-indiceFrecMax);// 1*9= 9
                duracionActual = i-indiceFrecMax;//9
        }
        if (areaMax<areaActual){
                areaMax = areaActual;
                frecMax = frec;
                duracion = duracionActual;
                area = areaMax;
        }
    }	
    return frecMax;
}
