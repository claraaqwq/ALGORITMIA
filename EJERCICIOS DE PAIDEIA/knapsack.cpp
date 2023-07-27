#include <iostream>
#define ELEM 4//por enunciado
#define W 5//por enunciado

using namespace std;

int maximo(int a, int b){
	if (a>b)
		return a;
	else
		return b;
}

int llenar_mochila(int pesos[], int valores[], int V[ELEM+1][W+1])
{
	//asignamos las Condiciones de partida
	for(int j=0;j<W+1;j++)
		V[0][j]=0;
	for(int i=0;i<ELEM+1;i++)
		V[i][0]=0;
	
	//Construimos nuestra tabla de resultados V[][]
	for (int j=1;j<W+1;j++)
	{
		for (int i=1;i<ELEM+1;i++)
		{
			//Verifico si puedo incluir el paquete en análisis w(i) y v(i)
			if (j-pesos[i-1]>=0)
			//Se puede incluir el paquete
			{
				V[i][j]= maximo( V[i-1][j] , valores[i-1]+V[i-1][j-pesos[i-1]]);
				//en V[i,j] se pondrá el máximo valor entre:
				//
				//sin considerar ese paquete:  V[i-1,j]
					//la capacidad se mantiene en j
					//considero los paquetes anteriores a i
				
				//considerando ese paquete: 
					//la capacidad se resta en j-pesos[i-1] 
					//Sumo el resultado de V[i-1][j-pesos[i-1] al valor del paquete valores[i-1]
					//V[i-1][j-pesos[i-1]] = los paquetes anteriores con la capacidad reducida
			}else{//no se puede incluir el paquete
				V[i][j]= V[i-1][j];
				//sin considerar ese paquete:  V[i-1,j]
					//la capacidad se mantiene en j
					//considero los paquetes anteriores a i
			}
		}
	}
}

int main()
{
	int pesos[ELEM]={2,1,3,2};
	int valores[ELEM]={12,10,20,15};
	
	int V[ELEM+1][W+1];//Matriz de resultados que se contruirán mediante Prog. Dinámica
	//se añade una fila y una columna más para las condiciones de PARTIDA (que se usa en PD)
	
	llenar_mochila(pesos, valores, V);
	cout<<"Máximo valor (V): "<<V[ELEM][W]<<endl;
	//en V[ELEM][W] se encontrará la solución a nuestro problema
	//Mayor valor con capacidad W=5kg y ELEM=4 paquetes		
	
	for (int i=0;i<ELEM+1;i++){
		for (int j=0; j<W+1; j++)
			cout<<V[i][j]<<" ";
		cout<<endl;
	}
	return 0;
}
