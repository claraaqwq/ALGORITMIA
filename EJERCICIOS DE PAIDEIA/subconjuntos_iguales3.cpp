#include <iostream>
#define ELEM 4//por enunciado

using namespace std;

int busca_subconjuntos_iguales(int arreglo[],int n)
{
	int i,j, temp;
	int suma=0;
	
	//Ordenamos el arreglo de forma creciente, 
	//para poder hallar el punto en que partimos el arreglo en 2 subarreglos
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			if (arreglo[i]>arreglo[j]){
				temp=arreglo[i];
				arreglo[i]=arreglo[j];
				arreglo[j]=temp;
			}		
			
	//Calculamos la suma de los elementos 
	//para poder establecer la cantidad de columnas de nuestra matriz de resultados
	for (i=0;i<n;i++)
		suma=suma+arreglo[i];
	
	//Matriz donde vamos a construir las soluciones utilizando PD
	int pd[n+1][suma+1];
	
	//Construir las soluciones con PD
	//Inicializar la columna 0 y la fila 0
	for (i=1;i<suma+1;i++) 	pd[0][i]=0;
	for (i=0;i<n+1;i++) 	pd[i][0]=1;
	
	for (i=1;i<n+1;i++){
		for(j=1;j<suma+1;j++){
			
			pd[i][j]=pd[i-1][j];//asumimos inicialmente que no podríamos incluir el elemento
			if (j-arreglo[i-1]>=0)//si es que podríamos incluir el elemento, entonces
				if (pd[i][j]==0)//si es que la posición no ha sido analizada previamente
					pd[i][j]=pd[i-1][j-arreglo[i-1]];//reducimos la suma (presupuesto, capacidad, costo, etc) del valor del elemento
			cout<< pd[i][j]<<" ";
		}
		cout<<endl;
	}
	//Hasta aquí tenemos completa nuestra tabla de resultados pd[][]

	//Donde está nuestro corte? EL corte ahora es entre 3 subconjuntos de sumas iguales
	int diferencia=1000;//quiero que sea 0, o en variaciones del problema, la mínima diferencia
	int flag=0;
	for (j=suma/3;j>=0;j--)
	{
		if (pd[n][j]==1)//En la posición donde la suma (que es j) considerando todos los elementos (n),
						//allí se encuentraría el corte para los 3 subconjuntos.
		{
			//suma de los elementos del subconjunto A, j
			//suma de los elementos del subconjunto B, suma-2j
			//diferencia= suma-2j - j 
			diferencia=suma-3*j;//debería ser 0 para que cumpla con lo exigido por el problema
			if (diferencia==0){//si la diferencia de las sumas es 0, entonces encontré la solución
				flag=1;
				break;
			}
			else
				return 0;
		}
	}
	for (j=(suma/3)*2;j>=suma/3;j--)
	{
		if (pd[n][j]==1)//En la posición donde la suma (que es j) considerando todos los elementos (n),
						//allí se encuentraría el corte para los 2 subconjuntos.
		{
			//suma de los elementos del subconjunto A, j
			//suma de los elementos del subconjunto B, suma-2j
			//diferencia= suma-2j - j 
			diferencia=suma-3*j/2;//debería ser 0 para que cumpla con lo exigido por el problema
			if (diferencia==0 && flag)//si la diferencia de las sumas es 0 Y cumple con el primer corte, entonces encontré la solución
				return 1;
			else
				return 0;
		}
	}
	return 0;
}

int main()
{
	//int arreglo[]={1,6,11,5};
	int arreglo[]={6,4,3,2,3};
	int n=5;
	
	cout<<"Resultado: "<<busca_subconjuntos_iguales(arreglo,n)<<endl;

	return 0;
}
