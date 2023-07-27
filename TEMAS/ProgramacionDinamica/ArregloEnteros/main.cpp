
/* 
 * File:   main.cpp
 * Author: clara
 *
 * Created on 20 de junio de 2023, 11:05 AM
 */


#include <iostream>
#include <iomanip>

//PROBLEMA DE LAS CANASTAS

//PROGRAMACION DINÁMICA
using namespace std;

int buscaIguales(int arr[], int n){
    int sum=0;
    /*Guardo la suma completa del arreglo*/
    for(int i=0;i<n;i++){
        sum = sum + arr[i];
    }
    /*Creo la matriz
     *cantidad de filas es la suma del arreglo + 1, porque inicia en cero*/
    int dp[n+1][sum+1];
    /*por filas*/
    for(int i=0;i<=n;i++) dp[i][0]=1;
    /*por columnas => al iniciar la primera fila solo tendrá un 1 en su primera pos, despues full 0's
     *por ello se inicializa en i=1, porque no tomará el cero*/
    for(int i=1;i<=sum;i++) dp[0][i]=0;
    /*filas = i*/
    for(int i=1;i<=n;i++){
        /*columnas = j*/
        for(int j=1;j<=sum;j++){
            dp[i][j] = dp[i-1][j]; /*para la fila anterior*/
            /*caso el valor del arreglo-1(pq empezaba en cero) es <j puedo restar :)*/
            /*Cuando en anterior era cero, tenia que evaluar la resta,
             *para saber si en esa pos podia valer 1*/
            if(arr[i-1]<=j && dp[i][j]==0){
                /*(filaAnt)(resta de la columna - arreglo)*/
                dp[i][j]=dp[i-1][j-arr[i-1]];
            }
        }
    }
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=sum;j++){
            cout<<dp[i][j]<<" ";
        }
        cout<<endl;
    }//solo para ver lo que se está haciendo
    
    int dif=99999;
    /*Empiezo a revisar desde la mitad de la matriz y empiezo a retroceder*/
    for(int j=sum/2;j>=0;j--){
        if(dp[n][j]==1){
            dif=sum-2*j;
            if(dif==0)return 1;
            return 0;
        }
    }
    
    
}

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

int main(int argc, char** argv) {
    
    /*SE ORDENA EL ARREGLO ANTES -> BUBBLESHORT*/
    int arr[]={11,5,1,5};
    int i, n=4;

    mergesort(arr, 0,n-1);
    cout<<"ARREGLO:"<<endl;
    
    for (i=0; i<n;i++){
        cout<< arr[i] <<" ";
    }
    cout<<endl;
    cout<<"Matriz: "<<endl;
    cout<<"Son iguales?: "<< buscaIguales(arr,n);
    
    return 0;
}

