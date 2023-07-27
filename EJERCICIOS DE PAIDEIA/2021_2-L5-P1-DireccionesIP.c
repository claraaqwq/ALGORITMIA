/*
 * Examen 2 (2021-1), pregunta 3a
 * Desarrollado por Johan Baldeon
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

const int MAX_LEN = 12;

// Función que verifica si una solución es válida
int is_valid(int N, int solution[], int step, int digits[]) {
    int i, marked_digit = 0, digits_count = 1;
    int count = 1, aux_num;

    // Comprueba si el primer dígito es 0, lo cual no es válido para un grupo
    if (solution[0] == 0) {
        return 0;
    }

    int j;
    for (i = 1; i <= step; i++) {
        // Comprueba si el dígito actual es diferente al anterior
        if (solution[i] != solution[i - 1]) {
            count++;
            
            // Si se ha excedido el número máximo de dígitos en un grupo o el número máximo de grupos permitidos, no es válido
            if (digits_count > 3 || count > 4) {
                return 0;
            }

            aux_num = 0;
            for (j = digits_count - 1; j >= 0; j--) {
                // Construye el número a partir de los dígitos almacenados en el arreglo "digits[]"
                aux_num += digits[i - (j + 1)] * pow(10, j);
            }

            // Comprueba si el número construido está fuera del rango permitido para una dirección IP
            if (aux_num > 255 || (digits_count == 2 && aux_num < 10) || (digits_count == 3 && aux_num < 100)) {
                return 0;
            }

            digits_count = 1;  // Reinicia el contador de dígitos para el próximo grupo
        } else {
            digits_count++;  // Incrementa el contador de dígitos para el grupo actual
        }
    }

    aux_num = 0;
    for (j = digits_count - 1; j >= 0; j--) {
        // Construye el número para el último grupo
        aux_num += digits[i - (j + 1)] * pow(10, j);
    }

    // Comprueba si el último número construido está fuera del rango permitido para una dirección IP
    if (aux_num > 255 || (digits_count == 2 && aux_num < 10) || (digits_count == 3 && aux_num < 100)) {
        return 0;
    }

    // Comprueba si se ha alcanzado una solución completa y verifica las condiciones finales
    if ((step == N - 1 && count != 4) || (step < N - 1 && count > 4) || digits_count > 3) {
        return 0;
    } else {
        return 1;
    }
}


//Esta función imprime una solución válida de agrupamiento de dígitos en formato de dirección IP. 
//Recibe los siguientes parámetros:
//N: El tamaño de la cadena de dígitos.
//solution[]: Un arreglo que almacena la solución de agrupamiento de dígitos.
//digits[]: Un arreglo que almacena los dígitos de la cadena de entrada.

//La función itera sobre la solución y los dígitos correspondientes para imprimirlos en el formato de dirección IP. 
//Coloca un punto "." entre los grupos de dígitos diferentes. 
//Por ejemplo, si la solución es [0, 0, 0, 1, 1, 1, 2, 2, 2, 3, 3, 3], 
//y los dígitos son [1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 1, 2], 
//la función imprimiría "123.456.789.012" en la consola.
//Por ejemplo: para imprimir: 1.1.1.1, solution[]={0,1,2,3} y digits[]={1,1,1,1}

void print_solution(int N, int solution[], int digits[]) {
    int i = 0;
    
    // Imprime el primer dígito de la solución
    printf("%d", digits[i]);
    
    // Recorre el resto de los dígitos y soluciones
    for (i = 1; i < N; i++) {
        if (solution[i] != solution[i - 1]) {
            printf("."); // Imprime un punto si se inicia un nuevo grupo de dígitos
        }
        printf("%d", digits[i]); // Imprime el dígito actual
    }
    
    printf("\n"); // Imprime un salto de línea al final de la dirección IP
}


//Esta es una función recursiva (BackTracking) que encuentra todas las soluciones válidas de agrupamiento de dígitos para formar direcciones IP. 
//Recibe los siguientes parámetros:
//N: El tamaño de la cadena de dígitos.
//solution[]: Un arreglo que almacena la solución parcial de agrupamiento de dígitos.
//step: El paso actual de la recursión.
//digits[]: Un arreglo que almacena los dígitos de la cadena de entrada.

//La función utiliza un enfoque de fuerza bruta para generar todas las combinaciones posibles de agrupamientos de dígitos 
//y verifica si son soluciones válidas utilizando la función is_valid(). 
//Imprime las soluciones válidas utilizando la función print_solution(). 
//La recursión avanza paso a paso, probando diferentes agrupamientos de dígitos hasta que se alcance una solución completa.
void get_IPs_rec(int N, int solution[], int step, int digits[]) {
    int i = 0;
    
    // Verifica si se ha alcanzado la solución completa
    if (step == N) {
        print_solution(N, solution, digits);  // Imprime la solución válida encontrada
        return;
    }
    
    // Realiza un bucle para probar diferentes valores en el paso actual
    do {
        solution[step] = i;  // Asigna el valor actual a la solución en el paso actual
        
        // Verifica si la solución parcial actual es válida
        if (is_valid(N, solution, step, digits)) {
            get_IPs_rec(N, solution, step + 1, digits);  // Llama recursivamente a la función para el siguiente paso
        }
        
        i++;  // Incrementa el valor para probar el siguiente
    } while (solution[step] != 1);  // Continúa el bucle hasta que se haya probado el valor 1 en el paso actual
    
    solution[step] = -1;  // Restaura el valor de la solución en el paso actual a -1 (no válido) para la siguiente iteración
}


int main() {
    char *data = (char *)malloc(sizeof(char) * (MAX_LEN + 1));
    printf("Ingrese una cadena de sólo dígitos: ");
    scanf("%s", data);
    int i;
    int N = strlen(data);
    
    // Verifica si el tamaño de la cadena de dígitos es válido
    if (N <= MAX_LEN) {
        int solution[N], digits[N];
        
        // Convierte los caracteres de la cadena en dígitos enteros y los almacena en el arreglo "digits[]"
        for (i = 0; i < N; i++) {
            digits[i] = data[i] - '0';
            solution[i] = -1;
        }

        // Llama a la función recursiva "get_IPs_rec()" para obtener todas las direcciones IP válidas
        get_IPs_rec(N, solution, 0, digits);
    } else {
        printf("No se pueden obtener direcciones por ser una cadena muy larga.\n");
    }
    return 0;
}


