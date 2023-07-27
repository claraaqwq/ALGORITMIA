#include <iostream>
#include <fstream>
#include <cmath>
#define MAXCOL 10
#define MIN_CREDITO 3
#define CANT_CURSOS_DISPO 15
using namespace std;

void cambiarBin(int num, int n, int cromo[],int &cantUnos){
	int i, resto;
	cantUnos=0;
	//inicializamos el cromo en cero
	for(i=0;i<n;i++) cromo[i] = 0;
	i=0;
	while(num>0){
		resto = num%2;
		num   = num/2;
		cromo[i] = resto;
		if(cromo[i]==1) cantUnos++;
		i++;
	}
}

void llenarMatriz(int matrizCursos[][MAXCOL],ifstream &archIn){
	int fil=0,col=0;
	while(true){
		archIn>>matrizCursos[fil][0];
		if(archIn.eof())break;
		for(col=0;col<10;col++){
			archIn>>matrizCursos[fil][col];
		}
		fil++;
	}
	
	for(fil=0;fil<15;fil++){
		for(col=0;col<10;col++){
			cout<<matrizCursos[fil][col]<<" ";
		}
		cout<<endl;
	}
	
}

int sumarCreditosComb(int cromo[],int matrizCursos[15][10],int n){
	int sumaCreditos = 0;
	int i;
	
	for(i=0;i<n;i++){
		if(cromo[i] == 1){//el curso si está disponible
		//necesito obtener el numero de creditos del cursos
			int credCurso = matrizCursos[i][MAXCOL];
			sumaCreditos = sumaCreditos + credCurso;
			
		}
	}
		
	return sumaCreditos;
}

bool verificarCursosRepetidos (int cromo[],int matrizCursos[][MAXCOL]){
	int i;
	int id_ant,id_act;
	bool cursosRepetidos=false;//primero creo q no hay repetidos//
	int cantCursos=0;
	for(i=0;i<CANT_CURSOS_DISPO;i++){
		if(cromo[i] == 1){
			cantCursos++;
			id_act = matrizCursos[i][0];
			if(cantCursos>=2){
				if(id_act==id_ant){
					cursosRepetidos = true;
					break;
				}
			}
			id_ant = id_act;
		}
	}
	return cursosRepetidos;
}

bool verificarCruce(int cromo[],int matrizCursos[][MAXCOL]){
	int matHorarioPar[25][6];
	int matHorarioImpar[25][6];
	
	int i;
	for(i=0;i<CANT_CURSOS_DISPO;i++){
		if(cromo[i]==1){
			
		}
	}
}

int main(){
	
	ifstream archIn("Cursos.txt",ios::in);
	
	int L;
	cout<<"Ingrese el máximo de creditos: "<<endl;
	cin>>L;
	
	int matrizCursos[15][10];
	
	cout<<"Dato: "<<matrizCursos[1][1];
	
	llenarMatriz(matrizCursos,archIn);
	
	//Todas las combinaciones de 15 cursos posibles//
	//combinaciones de 1 curso 2 cursos 3 4 5 y 6 cursos como maximo//
	
	int maximoCursos = L/MIN_CREDITO; //maximo num de cred posibles
	int n=15; //MAX CANT DE CURSOS//
	int cromo[n];
	int i,cantUnos;
	//max posibilidades de cursos
	int opciones = (int)pow(2,n);
	for(i=0;i<opciones;i++){
		
		cambiarBin(i,n,cromo,cantUnos);
		if(cantUnos<=maximoCursos){
			
			int cantCreditosCombinacion = sumarCreditosComb(cromo,matrizCursos,n);
			
			if(12<=cantCreditosCombinacion && cantCreditosCombinacion<=L){
				//verificar que los cursos no se repitan//
				bool cursosRepetidos = verificarCursosRepetidos (cromo,matrizCursos);
				
				if(cursosRepetidos == false){
					
					int matHorarioPar[25][6];
					int matHorarioImpar[25][6];
					
					bool hayCruce = verificarCruce(cromo,matrizCursos);
					
					if(hayCruce==false){
						cout<<"i = "<<i<<"-->  ";
						int j;
						for(j=0;j<n;j++) cout<<cromo[j];
						cout<<" Creditos: "<<cantCreditosCombinacion;
						cout<<endl;	
					}
				}
					
			}
		}
	}
	
	return 0;

}


