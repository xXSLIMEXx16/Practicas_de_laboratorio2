/*
a) Implementar una función que permita cargar un estudiante por teclado y lo guarde al final de un archivo binario llamado "alumnos.dat".
b) Implementar una función que lea el archivo completo y calcule el promedio general (la media de todos los promedios) de todos los estudiantes guardados.
c) ¿Cuál es la diferencia entre abrir un archivo con el modo "wb" y el modo "ab"?
d) ¿Por qué es necesario usar fread y fwrite en lugar de fprintf o fscanf para manejar esta estructura en un archivo binario?
*/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>


typedef struct {
    int id_estudiante;
    char apellido[40];
    float promedio;
} Estudiante;

void Guardar_datos(Estudiante *Estudiante, int *cantidad);

int main()
{
    Estudiante *estudiantes = NULL;
    int cantidad = 0;


    return 0;
}

void Guardar_datos(Estudiante *estudiantes, int *cantidad){

     Estudiante *aux = (Estudiante*)realloc(estudiantes, (*cantidad + 1) * sizeof(Estudiante));
     
     if(*aux != NULL){
        estudiantes = aux;
        FILE *Archivo = fopen("alumnos.dat","aw");
     }


    }