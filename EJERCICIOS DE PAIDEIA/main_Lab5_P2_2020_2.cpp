#include <iostream>
#define N 4

using namespace std;

int evaluarGanancia(int menores[N],int cantGrupos,int p){
	int tabla[cantGrupos+1][p+1];
	/*Inicializamos la primera fila*/
	for (int j=0; j<=p; j++){
		tabla[0][j] = 0;
	}
	/*Inicializamos la primera columna*/
	for (int i=0; i<=cantGrupos; i++){
		tabla[i][0] = 0;
	}
	for (int j=1; j<=p; j++){
		for (int i=1; i<=cantGrupos; i++){
			if (tabla[i-1][j]==1){
				tabla[i][j] = 1;
			}
			else {
				if (menores[i-1]>j){
					tabla[i][j] = 0;
				}
				else {
					if (menores[i-1]==j){
						tabla[i][j] = 1;
					}
					else {
						int diferencia = j - menores[i-1];
						tabla[i][j] = tabla[i-1][diferencia];
					}
				}
			}
		}
	}
	/*Imprimir la tabla de PD*/
	for (int i=0; i<=cantGrupos; i++){
		for (int j=0; j<=p; j++){
			cout << tabla[i][j] << " ";
		}
		cout << endl;
	}
	
	/*Imprimimos los resultados*/
	
	/*Buscamos el resultado final que esta ubicado empezando desde la ultima columna, ultima fila*/
	int ganancia, encontre=0;
	for (int j=p; j>=0; j--){
		for (int i=cantGrupos; i>=0; i--){
			if (tabla[i][j]==1){
				ganancia=j;
				encontre=1;
				break;
			}
		}
		if (encontre){
			break;
		}
	}
	
	cout << "La combinacion de productos es: ";
	int aux=ganancia;
	while (aux>0){
		for (int i=0; i<=cantGrupos; i++){
			if (tabla[i][aux]==1){
				cout << menores[i-1] << " ";
				aux = aux - menores[i-1];
				break;
			}
		}
	}
	cout << endl;
	return ganancia;
}

int main(){
	/*La parte de identificar los menores de cada grupo es todo tuyo*/
	int menores[N] = {2,3,3,5};
	int cantGrupos = 4;
	int presupuesto = 20;
	int precioPaneton = 8;
	int p = presupuesto -precioPaneton;
	cout << "Se necesita S/. " << 8 + evaluarGanancia(menores,cantGrupos,p) << " para la canasta"; 
	return 0;
}
