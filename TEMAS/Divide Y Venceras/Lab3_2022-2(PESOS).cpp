#include <iostream>
#define MAXDIAS 30
#include <fstream>
using namespace std;
//USO DIVIDE Y VENCERAS

void merge(int A[], int inicial, int medio, int final){
	int longitud1, longitud2, i, p, q;
	
	//Al lado izq tengo x elementos
	longitud1=(medio+1)-inicial;//primera mitad del arreglo
	//Al lado der tengo x elementos
	longitud2=final-medio;//segunda mitad del arreglo
	
	//Les agrego espacio para colocar un mayor al ultimo
	int P[longitud1+1];
	int Q[longitud2+1];
	
	//agrego los valores mayores de ambos arreglos
	//En la ultima posicion
	P[longitud1]=999999;
	Q[longitud2]=999999;
	
	//copiamos los valores desde A hacia los arreglos auxiliares P y Q
	//Agrego los elementos al arreglo1 || inicio-> medio
	for (i=inicial;i<=medio;i++)
		P[i-inicial]=A[i];
	//Agrego los elementos al arreglo 2 || medio->final
	for (i=medio+1;i<=final;i++)
		Q[i-(medio+1)]=A[i];
	
	p=q=0;
	//Agrega todo al arreglo original
	//Comienza ordenacion//
	for (i=inicial;i<=final;i++)
		if (P[p]<Q[q])
		//ejemplo p[0] -> cuando vuelva al for cambiará a p[1]
			A[i]=P[p++];
		else
			A[i]=Q[q++];
}

void mergesort(int A[], int inicial, int final){
	if (inicial==final)
		return;
	//PARA ORDENAR
	int medio=(inicial+final)/2; //consigue indice del medio
	mergesort(A,inicial,medio);//logn --> ordeno izquierda
	mergesort(A,medio+1,final);//logn --> ordeno derecha
	
	//JUNTA LOS 2 ARREGLOS, EN UNO SOLO
	merge(A, inicial, medio, final);
	
}

//Como quiero que me devuelva los rangos, los pasaré como referencia
void BuscarRangoMaximo(int ArrPesosSinOrdenar[],int indiceIn,int menorPeso,int &rango_inicio,int &rango_fin,int &cantVeces){
	//CASO BASE:
	while(true){//el indiceIn recorre siempre en todo el arreglo
		if(ArrPesosSinOrdenar[indiceIn++]==menorPeso){
			indiceIn--; //corrijo el inicio, porque al momento que encuentra el menorPeso, realiza el indiceIn++, por ello le bajamos 1
			break;
		}
		//cuando no sea == el inicio se quedará en la ultima posicion que iteró, y ese será mi nuevo inicio
		
		if(indiceIn == MAXDIAS) return; //termina el arreglo, asi que sale de la funcion
	}
	
	//cout<<"Inicio: "<<indiceIn<<endl;
	
	int cant=1; //cuando se posicione en el menor peso empezará a contar
	/*indiceIn es la posicion en la que encuentra al dato diferente al MENORPESO*/
	int i = indiceIn+1; //Le aumento 1 más, porque yo ya sé que el indice cumple, por lo tanto me falta evaluar el siguiente
	//es posicion donde lo encuentro por primera vez//
	
	while(true){
		//PARA EVALUAR CUANDO ESTÉ RECORRIENDO
		if(ArrPesosSinOrdenar[indiceIn++] != menorPeso) break;
		if(indiceIn == MAXDIAS) return; //termina el arreglo, asi que sale de la funcion
	}
	
	/* Se le resta uno pq el inicio con el q termina es el nmr != menorPeso, por lo tanto, si queremos el indice de la 
	   ultima posicion de mi MENORPESO, tengo que restarle 1 al inicio que tengo*/
	   
	
	//inicio con el dia q acaba el primer recorrido = 18
	int f = indiceIn-1; // 18 - 1 = 17 <- como posicion
	if((f-i+1)>cantVeces){ //17-15+1 = 3 > 0
		rango_inicio = i; // 15
		rango_fin = f; // 17
		cantVeces = (f-i+1); //3
	}
	
	//RECURSION
	BuscarRangoMaximo(ArrPesosSinOrdenar,indiceIn,menorPeso,rango_inicio,rango_fin,cantVeces);
	
}

int main(){
	
	ifstream arch("pesos.txt",ios::in);
	int ArrPesosSinOrdenar[MAXDIAS];
	int ArrPesos[MAXDIAS];
	
	cout<<"Ingrese los pesos de cada dia: "<<endl;
	for(int i=0;i<MAXDIAS;i++){
		arch>>ArrPesos[i];
		ArrPesosSinOrdenar[i] = ArrPesos[i]; //Creo copia del arreglo
	}
	
	//DESORDENADOS
	cout<<"PESOS DESORDENADOS: "<<endl;
	for(int i=0;i<MAXDIAS;i++){
		cout<<ArrPesos[i]<<" ";
	}cout<<endl;
	
	//Me piden menor peso, entonces tengo que ordenar el arreglo y asi sacar el indice i=0
	//Complejidad => n*log(n) --> for * recursion
	for(int i=0;i<MAXDIAS;i++){
		//Le mandamos la matriz como arreglo --> por filas
		mergesort(ArrPesos,0,MAXDIAS-1); // n*log(n)
	}
	//YA ORDENADOS
	cout<<"PESOS ORDENADOS: "<<endl;
	for(int i=0;i<MAXDIAS;i++){
		cout<<ArrPesos[i]<<" ";
	}
	cout<<endl;
	int menorPeso = ArrPesos[0];
	cout<<"El menor peso fue : "<<menorPeso<<endl;
	
	/* Si para la otra necesita el rango que dias tengo que usar el arreglo sin modificar */
	/* (Arr, indiceIn, menorP, rangoIn, rangoFin, cantVeces) */
	int indiceIn=0, cantVeces=0;
	int rango_inicio, rango_fin;
	BuscarRangoMaximo(ArrPesosSinOrdenar,indiceIn,menorPeso,rango_inicio,rango_fin,cantVeces);
	cout<<"El rango fue: "<<rango_inicio<<" - "<< rango_fin;
	
	return 0;
}
