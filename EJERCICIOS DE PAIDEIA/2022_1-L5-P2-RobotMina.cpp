#include <iostream>
using namespace std;

#define MAX_MOV 20
#define MAX_INI 8
#define N 100
#define M 100

int mov[MAX_INI][2];
int maximo = 0;

// Genera las posiciones de movimiento posibles
void generarPosiciones() {
	// llena la matriz mov con las posiciones de movimiento posibles para el robot. 
	//Hay un total de 8 movimientos: arriba, abajo, izquierda, derecha, y las diagonales.
    mov[0][0] = 1;
    mov[0][1] = 0;
    mov[1][0] = 0;
    mov[1][1] = -1;
    mov[2][0] = 0;
    mov[2][1] = 1;
    mov[3][0] = -1;
    mov[3][1] = 0;

    mov[4][0] = 1;
    mov[4][1] = 1;
    mov[5][0] = -1;
    mov[5][1] = -1;
    mov[6][0] = 1;
    mov[6][1] = -1;
    mov[7][0] = -1;
    mov[7][1] = 1;
}

// Genera una tabla vac�a. "Inicializaci�n"
void generarTabla(char a[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            a[i][j] = '0';//Inicializaci�n en 0
        }
    }
}

// Carga las posiciones de las minas en la tabla
void cargarMinas(char a[N][M]) {//Datos del enunciado
    a[0][4] = '*';
    a[2][2] = '*';
    a[4][1] = '*';
    a[4][2] = '*';
    a[4][4] = '*';
    a[5][1] = '*';
    a[5][2] = '*';
    a[5][4] = '*';
    a[6][1] = '*';
    a[6][3] = '*';
    a[7][0] = '*';
    a[7][1] = '*';
    a[7][2] = '*';
    a[7][3] = '*';
}

// Imprime la tabla
void imprimirTabla(char a[N][M], int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

// Verifica si una posici�n es v�lida dentro de la tabla
bool esValida(char a[N][M], int x, int y, int n, int m) {
	//Verifica que las coordenadas (x, y) est�n dentro de los l�mites de la tabla 
	//y que la celda correspondiente contenga el car�cter '0'.
    if (x < n && y < m && x >= 0 && y >= 0 && a[x][y] == '0')
        return true;//Podr�a avanzar
    return false;//No podr�a avanzar
}

// Descubre las casillas adyacentes que no contienen minas
void descubrirCasillas(char a[N][M], int n, int m, int x, int y, char solu[N][M]) {
    for (int i = 0; i < MAX_INI; i++) {
        int nueva_x = x + mov[i][0];
        int nueva_y = y + mov[i][1];
        if (esValida(solu, nueva_x, nueva_y, n, m)) {
            if (a[nueva_x][nueva_y] == '*')
			// Actualiza la tabla solu marcando con '*' las casillas adyacentes que contienen minas.
                solu[nueva_x][nueva_y] = '*';
        }
    }
}

// Resuelve el problema del robot
bool resolverRobot(char a[N][M], int n, int m, int x, int y, char solu[N][M], char pasos) {
	//Utiliza BackTracking para explorar todas las posibles rutas desde la posici�n inicial (x, y) hasta la posici�n final de la tabla. 
	//Marca cada posici�n visitada con letras consecutivas ('A', 'B', 'C', ...) en la tabla solu. 
	//Si encuentra una ruta v�lida hasta la posici�n final, la imprime en la consola. 
	//El n�mero m�ximo de pasos permitidos est� definido por la constante MAX_MOV.

    // Verificar si se ha alcanzado el n�mero m�ximo de movimientos permitidos
    if (maximo == MAX_MOV)//Por enunciado son 20 soluciones
        return true;

    // Verificar si se ha llegado a la posici�n final de la tabla: LA META
    if (x == n - 1 && y == m - 1) {
        // Imprimir la soluci�n encontrada en la tabla de soluci�n
        imprimirTabla(solu, n, m);
        cout << endl;
        maximo++;//Aumentamos cuando se encontr� una soluci�n
        return false;
    }

    // Descubrir las casillas alrededor que no contienen minas
    descubrirCasillas(a, n, m, x, y, solu);

    // Explorar las posibles rutas desde la posici�n actual
    for (int i = 0; i < MAX_INI; i++) {
        int nueva_x = x + mov[i][0];
        int nueva_y = y + mov[i][1];
        if (esValida(solu, nueva_x, nueva_y, n, m)) {
            // Marcar la nueva posici�n con el siguiente paso
            solu[nueva_x][nueva_y] = pasos + 1;//Aqu� S� avanzamos
            if (resolverRobot(a, n, m, nueva_x, nueva_y, solu, pasos + 1))
                return true;
            // Si la ruta no es v�lida, se desmarca la posici�n
            solu[nueva_x][nueva_y] = '0';
        }
    }

    return false;
}


int main() {
    char pasos = 'A';//dato del problema
    int n = 9;//dato del problema
    int m = 5;//dato del problema
    int x = 0;//dato del problema, posici�n de inicio
    int y = 0;//dato del problema, posici�n de inicio
    char table[N][M];
    char solu[N][M];

    generarPosiciones();
    generarTabla(table, n, m);//Inicializamos el mapa
    cargarMinas(table);
    imprimirTabla(table, n, m);
    cout << endl;
    generarTabla(solu, n, m);//Inicializamos la tabla de soluci�n
    solu[0][0] = pasos;//Inicializamos el inicio de la soluci�n en (0,0)='A', para que vaya avanzando: B, C, D, etc

    resolverRobot(table, n, m, x, y, solu, pasos);

    return 0;
}

