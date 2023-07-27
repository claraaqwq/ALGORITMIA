#include <iostream>

using namespace std;

void merge(int A[], int inicial, int medio, int final){
	int longitud1, longitud2, i, p, q;
	
	longitud1=(medio+1)-inicial;//primera mitad del arreglo
	longitud2=final-medio;//segunda mitad del arreglo
	
	int P[longitud1+1];
	int Q[longitud2+1];
	
	//agrego los valores mayores de ambos arreglos
	P[longitud1]=999999;
	Q[longitud2]=999999;
	
	//copiamos los valores desde A hacia los arreglos auxiliares P y Q
	for (i=inicial;i<=medio;i++)
		P[i-inicial]=A[i];
	for (i=medio+1;i<=final;i++)
		Q[i-(medio+1)]=A[i];
	
	p=q=0;
	for (i=inicial;i<=final;i++)
		if (P[p]<Q[q])
			A[i]=P[p++];
		else
			A[i]=Q[q++];
}

void mergesort(int A[], int inicial, int final){
	if (inicial==final)
		return;
		
	int medio=(inicial+final)/2;
	mergesort(A,inicial, medio);//logn
	mergesort(A,medio+1, final);//logn
	
	merge(A, inicial, medio, final);
	
}

int clasifica(int ini,int fin, int arr[], int cont, double pi, int total){
	double porc;
	
	//empiezo por el medio
	int med = (ini+fin)/2;
	
	//realizo condicion de parada
	if(ini==fin) {
			if(arr[ini]==0) cont+=1;
			porc = (double)(cont)/total;
			if(porc>=pi) return 1;
			return 0;
	}
	//si es cero me voy del inicio al medio
	if(arr[med]==1){
		//int cuenta = fin-med+1+cont;

		//el fin se toma como med-1, porque en ese momento está posicionado en el cero y quiero los unos
		return clasifica(ini,med-1,arr,fin-med+1+cont,pi,total); //está contando los 1's
	}else{
		//caso que cuente los ceros
		//en ese momento está posicionado en un 1
		return clasifica(med+1,fin,arr,cont,pi,total);
	}
	
	
	
	/*EJEMPLO:
		 0 1 2 3 4 5 6
		(1,1,1,0,0,0,0)
		
		--Inicias en 0 -> 1
		--> cuenta(4,6,arr,0)
		--> cuenta(5,6,arr,3)
		--Se posiciona en el primer 0
		--> cuenta(0,2,arr,6-5+0)
		--> cuenta(2,3,arr,2-
	
	*/
}

int main(){
	
	int n=8, m=6;
	double pi = 0.7;
	int lote[][n] = {{0,0,0,1,1,0,-1,-1},
					 {1,0,1,1,1,0,1,0},
					 {0,1,1,1,1,1,1,1},
					 {1,1,1,1,1,0,1,-1},
					 {1,0,0,0,0,1,-1,-1},
					 {1,1,0,1,0,1,1,-1}
					};
	
	//FUNCION QUE ORDENA
	//guarda cuantos datos fueron validos, sin contar en las filas los -1's
	int largo[] = {6,8,8,7,6,7};
	for(int i=0;i<m;i++){
		//Le mandamos la matriz como arreglo --> por filas
		mergesort(lote[i],0,largo[i]-1); // n*log(n)
	}
	
	for(int i=0;i<m;i++){
		for(int j=0;j<largo[i];j++){
			cout<<lote[i][j]<<" ";
		}
		cout<<endl;
	}
	
	for(int i=0;i<m;i++){
		if(clasifica(0,largo[i]-1,lote[i],0,pi,m)==1){
			cout<<"Aprobado "<<endl;
		}else{
			cout<<"Rechazado "<<endl;
		}
	}
	
	return 0;
}
