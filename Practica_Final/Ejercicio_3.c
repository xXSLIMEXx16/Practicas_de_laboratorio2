/*Se desea trabajar con una matriz dinámica de enteros de $N \times M$.
a) Escribir el código necesario para reservar memoria para una matriz de 3 filas y 3 columnas utilizando malloc.
b) Implementar una función que reciba la matriz y sus dimensiones, y devuelva la suma de todos los elementos que se encuentran en la última columna.
c) Explicar: ¿Qué es un "puntero a puntero" (int **) y por qué es necesario para crear una matriz dinámica?
d) Escribir el código para liberar correctamente toda la memoria reservada en el punto (a).*/

#include <stdio.h>
#include <stdlib.h>
void suma_ultimaColumna(int **matriz, int fila, int columna);

int main()
{
    int **matriz, fila = 3, columna = 3;

    matriz = (int **)malloc(fila * sizeof(int*));

    for (int i = 0; i < fila; i++)
    {
        
        matriz[i] = (int *)malloc(columna * sizeof(int));
    }
    
    matriz[0][0] = 5;
    matriz[0][1] = 67;
    matriz[0][2] = -95;
    matriz[1][0] = 12;
    matriz[1][1] = 0;
    matriz[1][2] = 44;
    matriz[2][0] = -1;
    matriz[2][1] = 8;
    matriz[2][2] = 100;

    suma_ultimaColumna(matriz, fila, columna);

    for (int i = 0; i < fila; i++)
    {
        free(matriz[i]);
    }
    
    free(matriz);
    
    return 0;
}
void suma_ultimaColumna(int **matriz, int fila, int columna){

    int sumador = 0;

    for (int i = 0; i < fila; i++)
    {
        sumador += matriz[i][columna - 1];
    }
    printf("La suma de las ultimas columnas de cada fila es de: %d",sumador);
}