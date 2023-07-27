/*
 * Examen 2 (2021-1), pregunta 3a
 * Desarrollado por Johan Baldeon
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const int MAX_LEN = 12;

// Funci�n que verifica si una soluci�n es v�lida
int is_valid(int N, int solution[], int step, int digits[]) {
    int i, marked_digit = 0, digits_count = 1;
    int count = 1, aux_num;

    // Comprueba si el primer d�gito es 0, lo cual no es v�lido para un grupo
    if (solution[0] == 0) {
        return 0;
    }

    int j;
    for (i = 1; i <= step; i++) {
        // Comprueba si el d�gito actual es diferente al anterior
        if (solution[i] != solution[i - 1]) {
            count++;
            
            // Si se ha excedido el n�mero m�ximo de d�gitos en un grupo o el n�mero m�ximo de grupos permitidos, no es v�lido
            if (digits_count > 3 || count > 4) {
                return 0;
            }

            aux_num = 0;
            for (j = digits_count - 1; j >= 0; j--) {
                // Construye el n�mero a partir de los d�gitos almacenados en el arreglo "digits[]"
                aux_num += digits[i - (j + 1)] * pow(10, j);
            }

            // Comprueba si el n�mero construido est� fuera del rango permitido para una direcci�n IP
            if (aux_num > 255 || (digits_count == 2 && aux_num < 10) || (digits_count == 3 && aux_num < 100)) {
                return 0;
            }

            digits_count = 1;  // Reinicia el contador de d�gitos para el pr�ximo grupo
        } else {
            digits_count++;  // Incrementa el contador de d�gitos para el grupo actual
        }
    }

    aux_num = 0;
    for (j = digits_count - 1; j >= 0; j--) {
        // Construye el n�mero para el �ltimo grupo
        aux_num += digits[i - (j + 1)] * pow(10, j);
    }

    // Comprueba si el �ltimo n�mero construido est� fuera del rango permitido para una direcci�n IP
    if (aux_num > 255 || (digits_count == 2 && aux_num < 10) || (digits_count == 3 && aux_num < 100)) {
        return 0;
    }

    // Comprueba si se ha alcanzado una soluci�n completa y verifica las condiciones finales
    if ((step == N - 1 && count != 4) || (step < N - 1 && count > 4) || digits_count > 3) {
        return 0;
    } else {
        return 1;
    }
}


//Esta funci�n imprime una soluci�n v�lida de agrupamiento de d�gitos en formato de direcci�n IP. 
//Recibe los siguientes par�metros:
//N: El tama�o de la cadena de d�gitos.
//solution[]: Un arreglo que almacena la soluci�n de agrupamiento de d�gitos.
//digits[]: Un arreglo que almacena los d�gitos de la cadena de entrada.

//La funci�n itera sobre la soluci�n y los d�gitos correspondientes para imprimirlos en el formato de direcci�n IP. 
//Coloca un punto "." entre los grupos de d�gitos diferentes. 
//Por ejemplo, si la soluci�n es [0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3], 
//y los d�gitos son [1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2], 
//la funci�n imprimir�a "123.456.789.012" en la consola.
//Por ejemplo: para imprimir: 1.1.1.1, solution[]={0,1,2,3} y digits[]={1,1,1,1}

void print_solution(int N, int solution[], int digits[]) {
    int i = 0;
    
    // Imprime el primer d�gito de la soluci�n
    printf("%d", digits[i]);
    
    // Recorre el resto de los d�gitos y soluciones
    for (i = 1; i < N; i++) {
        if (solution[i] != solution[i - 1]) {
            printf("."); // Imprime un punto si se inicia un nuevo grupo de d�gitos
        }
        printf("%d", digits[i]); // Imprime el d�gito actual
    }
    
    printf("\n"); // Imprime un salto de l�nea al final de la direcci�n IP
}


//Esta es una funci�n recursiva (BackTracking) que encuentra todas las soluciones v�lidas de agrupamiento de d�gitos para formar direcciones IP. 
//Recibe los siguientes par�metros:
//N: El tama�o de la cadena de d�gitos.
//solution[]: Un arreglo que almacena la soluci�n parcial de agrupamiento de d�gitos.
//step: El paso actual de la recursi�n.
//digits[]: Un arreglo que almacena los d�gitos de la cadena de entrada.

//La funci�n utiliza un enfoque de fuerza bruta para generar todas las combinaciones posibles de agrupamientos de d�gitos 
//y verifica si son soluciones v�lidas utilizando la funci�n is_valid(). 
//Imprime las soluciones v�lidas utilizando la funci�n print_solution(). 
//La recursi�n avanza paso a paso, probando diferentes agrupamientos de d�gitos hasta que se alcance una soluci�n completa.
void get_IPs_rec(int N, int solution[], int step, int digits[]) {
    int i = 0;
    
    // Verifica si se ha alcanzado la soluci�n completa
    if (step == N) {
        print_solution(N, solution, digits);  // Imprime la soluci�n v�lida encontrada
        return;
    }
    
    // Realiza un bucle para probar diferentes valores en el paso actual
    do {
        solution[step] = i;  // Asigna el valor actual a la soluci�n en el paso actual
        
        // Verifica si la soluci�n parcial actual es v�lida
        if (is_valid(N, solution, step, digits)) {
            get_IPs_rec(N, solution, step + 1, digits);  // Llama recursivamente a la funci�n para el siguiente paso
        }
        
        i++;  // Incrementa el valor para probar el siguiente
    } while (solution[step] != 1);  // Contin�a el bucle hasta que se haya probado el valor 1 en el paso actual
    
    solution[step] = -1;  // Restaura el valor de la soluci�n en el paso actual a -1 (no v�lido) para la siguiente iteraci�n
}


int main() {
    char *data = (char *)malloc(sizeof(char) * (MAX_LEN + 1));
    printf("Ingrese una cadena de s�lo d�gitos: ");
    scanf("%s", data);
    int i;
    int N = strlen(data);
    
    // Verifica si el tama�o de la cadena de d�gitos es v�lido
    if (N <= MAX_LEN) {
        int solution[N], digits[N];
        
        // Convierte los caracteres de la cadena en d�gitos enteros y los almacena en el arreglo "digits[]"
        for (i = 0; i < N; i++) {
            digits[i] = data[i] - '0';
            solution[i] = -1;
        }

        // Llama a la funci�n recursiva "get_IPs_rec()" para obtener todas las direcciones IP v�lidas
        get_IPs_rec(N, solution, 0, digits);
    } else {
        printf("No se pueden obtener direcciones por ser una cadena muy larga.\n");
    }
    return 0;
}


