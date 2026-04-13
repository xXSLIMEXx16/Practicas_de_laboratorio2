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
Estudiante* Cargar_datos(Estudiante *Estudiante, int *cantidad);

int main()
{
    Estudiante *estudiantes = NULL;
    int cantidad = 0;

    //Guardar_datos(estudiantes, &cantidad);

    estudiantes = Cargar_datos(estudiantes, &cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        printf("=======%d=======\n Id: %d \nApellido: %s \nPromedio: %.2f",i+1, estudiantes[i].id_estudiante, estudiantes[i].apellido, estudiantes[i].promedio);
    }
    free(estudiantes);
    return 0;
}

void Guardar_datos(Estudiante *estudiantes, int *cantidad){

     Estudiante *aux = (Estudiante*)realloc(estudiantes, (*cantidad + 1) * sizeof(Estudiante));
     
     if(aux != NULL){
        estudiantes = aux;
        FILE *Archivo = fopen("alumnos.dat","ab");

        printf("Ingrese el id del estudiante: ");
        scanf("%d",&estudiantes[*cantidad].id_estudiante);
        getchar();

        printf("Ingrese el apellido del estudiante: ");
        fgets(estudiantes[*cantidad].apellido, 40, stdin);
        estudiantes[*cantidad].apellido[strcspn(estudiantes[*cantidad].apellido, "\n")] = '\0';

        printf("Ingrese el promedio del estudiante: ");
        scanf("%f",&estudiantes[*cantidad].promedio);

        (*cantidad)++;

        fwrite(estudiantes, sizeof(Estudiante), *cantidad, Archivo);

        fclose(Archivo);

        printf("Guardado exitoso...");

     }else{ printf("Error al asignar memoria...");}


    }

    Estudiante* Cargar_datos(Estudiante *Estudiantes, int *cantidad){

        FILE *Archivo = fopen("alumnos.dat","rb");

        if(Archivo != NULL){

            fseek(Archivo,0,SEEK_END); 
            (*cantidad) = ftell(Archivo)/sizeof(Estudiante);
            fseek(Archivo,0,SEEK_SET); 

            Estudiantes = (Estudiante*)realloc(Estudiantes, (*cantidad) * sizeof(Estudiante));
            
            fread(Estudiantes, sizeof(Estudiante),*cantidad, Archivo);

            fclose(Archivo);

            printf("\nArchivos cargados correctamente...");

            return Estudiantes;
        }else{printf("No hay datos guardados.");}
    }