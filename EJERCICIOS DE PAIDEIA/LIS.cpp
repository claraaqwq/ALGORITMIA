#include <iostream>
#define MAX 8
using namespace std;

int LIS[MAX];//Longitud de la subsecuencia creciente

int resuelveLIS(int X[])
{
	int i, j;
	int maxLIS=1; //asumo que mi máximo será al menor tomar 1 elemento de la secuencia.
	
	for (i=0;i<MAX;i++)
	{
		LIS[i]=1;//El elemento X[i] se considera dentro de la subsecuencia.
		for (j=0; j<i; j++)
		{
			if (X[i]>X[j] && LIS[j]+1> LIS[i]) //X[i]>X[j], verifico si puedo añadir
											   //OJO: por validar:
											   //LIS[j]+1> LIS[i], verifico si me conviene añadir
			{
				LIS[i]= LIS[j] + 1; //LIS[j] tiene la longitud de la subsecuencia creciente hasta la posición j
			}
		}
		if (LIS[i]>maxLIS)
			maxLIS=LIS[i]; //he hallado un nuevo maximo longitud de la subsecuencia creciente.
	}	
	return maxLIS;
}

int main()
{
	//int n=8; reemplazado por la variable global MAX
	int X[MAX]={-7,10,9,2,3,8,8,1};
	
	int lis= resuelveLIS(X);
	cout << "LIS: : "<< lis << endl;
	
	for (int z=0;z<MAX;z++)
		cout << LIS[z]<< " ";

	
	return 0;
}
