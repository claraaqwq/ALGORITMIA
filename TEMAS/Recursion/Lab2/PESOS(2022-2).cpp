#include <iostream>
#define MAX_DIAS 30

using namespace std;

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
	//primero agrego los primero a 1 arreglo 0->medio
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
	mergesort(A,inicial, medio);//logn --> ordeno izquierda
	mergesort(A,medio+1, final);//logn --> ordeno derecha
	
	//JUNTA LOS 2 ARREGLOS, EN UNO SOLO
	merge(A, inicial, medio, final);
	
}

void BusquedaRangoMaximo(int ArrPesosMesSinOrd[],int inicio,int menorPeso,
	int &rango_inicio,int &rango_fin,int &mayorCantDias){
	
	while(true){
		if(ArrPesosMesSinOrd[inicio++]==menorPeso){
			//CAMBIO EL INICIO
			inicio--;
			break;
		}
		//si llega al maximo de dias se detiene
		if(inicio==MAX_DIAS) return;
	}
		
	//i ahora es el inicio
	int cant = 1;
	int i = inicio+1; //Comienza en el indice 15
	while(true){
		if(ArrPesosMesSinOrd[inicio++]!=menorPeso) break;
		if(inicio==MAX_DIAS) return;
	}
	int f=inicio-1;
	//Condicion de parada: para cuando son iguales
	
	if((f-i+1)>mayorCantDias){
		rango_inicio = i;
		rango_fin = f;
		mayorCantDias = (f-1+1);
	}
	
	BusquedaRangoMaximo(ArrPesosMesSinOrd,inicio,menorPeso,rango_inicio,rango_fin,mayorCantDias);
	
	
}


int main(){
	
	//defino arreglo para el peso
	int ArrPesosMesSinOrd[MAX_DIAS] = 
	{98,95,92,89,91,92,89,89,92,93,94,92,91,90,88,
	 88,88,89,90,91,88,88,90,90,92,89,90,88,90,91};
	cout<<"Ingrese los pesos de los 30 dias : "<<endl;
	for(int i=0;i<MAX_DIAS;i++){
		cout<<ArrPesosMesSinOrd[i]<<" ";
	}
	
	mergesort(ArrPesosMesSinOrd,0,MAX_DIAS);
	int ArrPesosMes[MAX_DIAS] = {0};
	
	cout<<endl;
	for(int i=0;i<MAX_DIAS;i++){
		ArrPesosMes[i] = ArrPesosMesSinOrd[i];
	}
	
	//PRUEBO
	for(int i=0;i<MAX_DIAS;i++){
		cout<<ArrPesosMes[i]<<" ";
	}
	cout<<endl;
	
	int menorPeso = ArrPesosMes[0];
	cout<<"Menor Peso: "<<menorPeso;
	
	int rango_inicio, rango_fila=0, mayorCantDias=0,rango_fin;
	int inicio=0;
	BusquedaRangoMaximo(ArrPesosMesSinOrd,inicio,menorPeso,rango_inicio,rango_fin,mayorCantDias);
	
	cout<<endl;
	cout<<"El rango de dias en que lo obtuvo fue :" << rango_inicio+1<< " al "<<rango_fin+1<<"."<<endl;
	
}

/*
int EncontrarMenorPeso (int pesoPac[MAX_DIAS],int inicio, int final){
	
	//condicion de parada
	if(inicio == fin){
		return pesoPac[inicio];
	}
	//saco un medio
	int med = (inicio+fin)/2;
	int cantDerecha,cantIzquierda;
	
	//Evaluará del inicio al medio
	cantDerecha = EncontrarMenorPeso(pesoPac,inicio,medio);
	//Evaluará del medio al final
	cantIzquierda = EncontrarMenorPeso(pesoPac,medio+1,fin)M
	int menor;
	if(cantDerecha > cantIzquierda){
		menor = cantIzquierda;
	}else{
		menor = cantDerecha;
	}
	return menor;
	
}*/

