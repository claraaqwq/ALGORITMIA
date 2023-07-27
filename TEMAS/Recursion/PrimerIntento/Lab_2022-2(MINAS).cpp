#include <iostream>
#include <fstream>
#define MAX_FIL 10
#define MAX_COL 10
using namespace std;

int menorDe3Num (int num1, int num2, int num3){
	int menor;
	if(num1<=num2 && num1<=num3){
		menor = num1;
	}else if(num2<=num1 && num2<=num3){
		menor = num2;
	}else if(num3<=num1 && num3<=num2){
		menor = num3;
	}
	return menor;
}

void LeerCampoMinado (int n_fil, int m_col, int MatrizCampoMinado[MAX_FIL][MAX_COL], ifstream &archMinas,
					  int MatrizRadar[MAX_FIL][MAX_COL]){
	//Creamos nuestra matriz campo
	for(int f=0;f<MAX_FIL;f++){
		for(int c=0;c<m_col;c++){
			archMinas>>MatrizCampoMinado[f][c];
			MatrizRadar[f][c]=0;
		}
	}
}

int RobotDetectorMinas(int MatrizCampoMinado[MAX_FIL][MAX_COL], int MatrizRadar[MAX_FIL][MAX_COL], int x, int y,int n_fil, int m_col){
	//inicio (0,0)
	//UNICOS MOVIMIENTOS:
	//DERECHA -> ABAJO -> DIAGONAL (D+A)
	//Como siempre debo evaluar el menor de los 3, coloco un valor grande por si alguno no se ejecuta correctamente//
	int cantPasos_Der=9999, cantPasos_Aba=9999, cantPasos_Diag=9999;
	
	//CONDICION DE PARADAS
	if(x==n_fil-1 && y==m_col-1){
		return 0; //no hay movimientos
	}
	
	//Me muevo en diagonal y verifico que no hay minas
	if(x+1<n_fil && y+1<m_col && MatrizCampoMinado[x+1][y+1]==0){
		cantPasos_Diag = 1 + RobotDetectorMinas(MatrizCampoMinado,MatrizRadar,x+1,y+1,n_fil,m_col);
	}else{
		//SI ES QUE HAY UNA MINA EN DIAGONAL
		if(MatrizCampoMinado[x][y+1]==1){
			MatrizRadar[x+1][y+1] = 1; //PINTO EL RADAR SI ENCONTRÉ MINA
		}
	}
	
	//Me muevo hacia abajo y verifico que no hay minas
	if(x+1<n_fil && MatrizCampoMinado[x+1][y]==0){
		cantPasos_Aba = 1 + RobotDetectorMinas(MatrizCampoMinado,MatrizRadar,x+1,y,n_fil,m_col);
	}else{
		//SI ES QUE HAY UNA MINA ABAJO
		if(MatrizCampoMinado[x+1][y]==1){
			MatrizRadar[x+1][y] = 1; //PINTO EL RADAR SI ENCONTRÉ MINA
		}
	}
	
	//Me muevo a la derecha y verifico que no hay minas
	if (y+1<m_col && MatrizCampoMinado[x][y+1]==0){
		//si me muevo a la derecha sumaria un paso y vuelvo a buscar una opcion de paso en esa posicion
		cantPasos_Der = 1 + RobotDetectorMinas(MatrizCampoMinado,MatrizRadar,x,y+1,n_fil,m_col);
	}else{
		//SI ES QUE HAY UNA MINA A LA DERECHA
		if(MatrizCampoMinado[x][y+1]==1){
			MatrizRadar[x][y+1] = 1; //PINTO EL RADAR SI ENCONTRÉ MINA
		}
	}
	
	int cantPasos = menorDe3Num(cantPasos_Der,cantPasos_Aba,cantPasos_Diag);
	
	return cantPasos;
}


int main(){
	
	ifstream archMinas("minas.txt",ios::in);
	
	int n_fil,m_col;
	cout<<"Ingrese las dimensiones del area: "<<endl;
	cout<<"Ingrese n (filas): ";
	cin>>n_fil;
	cout<<"Ingrese m (columnas): ";
	cin>>m_col;
	
	int MatrizCampoMinado[MAX_FIL][MAX_COL];
	int MatrizRadar[MAX_FIL][MAX_COL];
	LeerCampoMinado(n_fil,m_col,MatrizCampoMinado,archMinas,MatrizRadar);
	
	int x,y;
	int minimoDePasos = RobotDetectorMinas(MatrizCampoMinado,MatrizRadar,0,0,n_fil,m_col);
	
	cout<<"El robot llega al punto final en: "<< minimoDePasos<< " pasos."<<endl;
	
	cout<<" ********RADAR*********"<<endl;
	for(int f=0;f<n_fil;f++){
		for(int c=0;c<m_col;c++){
			if(MatrizRadar[f][c]==0) cout<<"  ";
			else cout<<"* ";
		}
		cout<<endl;
	}
	cout<<" **********************"<<endl;
	
	return 0;
}
