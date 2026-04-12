#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct
{
    int codigo;
    char nombre[30];
    float precio;
} Producto;

void Guardar_producto( Producto *canasta, int *cantidad);
void Cargar_productos(Producto *canasta, int *cantidad);

int main()
{
    Producto canasta[100];
    int cantidad = 0;
   // Guardar_producto(canasta, &cantidad);

    Cargar_productos(canasta, &cantidad);

    for (int i = 0; i < cantidad; i++)
    {
        printf("\nCodigo: %d \nNombre: %s \n Precio: %.2f",canasta[i].codigo, canasta[i].nombre, canasta[i].precio);
    }
    
    return 0;
}

void Guardar_producto( Producto *canasta, int *cantidad){
    
 
    FILE *archivo = fopen("Datos1.bin","wb");
    if(archivo != NULL){

        printf("Ingrese el codigo del producto: ");
        scanf("%d",&canasta[*cantidad].codigo);
        while(getchar() != '\n');

        printf("Ingrese el nombre: ");
        fgets(canasta[*cantidad].nombre, 30, stdin);
        canasta[*cantidad].nombre[strcspn(canasta[*cantidad].nombre, "\n")] = 0;

        printf("Ingrese el precio: ");
        scanf("%f",&canasta[*cantidad].precio);
        while(getchar() != '\n');

        (*cantidad)++;

        fwrite(canasta, sizeof(Producto), *cantidad, archivo);

        fclose(archivo);
        return;
    }else{printf("Error"); }

    return;
}

void Cargar_productos(Producto *canasta, int *cantidad){
      FILE *archivo = fopen("Datos1.bin","rb");
    if(archivo != NULL){

        fseek(archivo, 0, SEEK_END); // Va al final del archivo
        long tam_bytes = ftell(archivo); // Nos dice cuántos bytes mide
        fseek(archivo, 0, SEEK_SET); //

        *cantidad = tam_bytes / sizeof(Producto);
        fread(canasta, sizeof(Producto), *cantidad, archivo);

        fclose(archivo);
        return;
    }else{printf("Error"); }
}