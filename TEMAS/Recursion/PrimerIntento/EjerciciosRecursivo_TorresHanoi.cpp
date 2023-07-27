#include <iostream>
using namespace std;

// Función recursiva que mueve los discos de una torre a otra
void moverDiscos(int n, char origen, char destino, char auxiliar) {
    // Caso base: mover un disco de la torre origen a la torre destino
    if (n == 1) {
        cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
        return;
    }
    // Mover n-1 discos de la torre origen a la torre auxiliar
    moverDiscos(n-1, origen, auxiliar, destino);
    // Mover el disco restante de la torre origen a la torre destino
    cout << "Mover disco " << n << " de " << origen << " a " << destino << endl;
    // Mover los n-1 discos de la torre auxiliar a la torre destino
    moverDiscos(n-1, auxiliar, destino, origen);
}

int main() {
    int numDiscos;
    cout << "Ingrese el número de discos: ";
    cin >> numDiscos;
    moverDiscos(numDiscos, 'A', 'C', 'B');
    return 0;
}

