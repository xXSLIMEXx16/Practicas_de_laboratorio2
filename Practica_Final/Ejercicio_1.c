#include <stdio.h>
#include <stdlib.h>

void cantidad_PosyNeg(int *v, int n);
void promedio_pates( int *v, int n);

int main()
{
    int *v;
    int n = 10;

    v = (int *)malloc(n * sizeof(int));

    v[0] = 10;
    v[1] = 777;
    v[2] = 6;
    v[3] = -987;
    v[4] = 89;
    v[5] = -987;
    v[6] = 5;
    v[7] = 66;
    v[8] = 35;
    v[9] = 872;
    

    cantidad_PosyNeg(v, n);
    promedio_pates(v, n);

    free(v);

    return 0;
}

void cantidad_PosyNeg(int *v, int n){
    int pos = 0, neg = 0;

    for (int i = 0; i < n; i++)
    {
        if(v[i] > 0){
            pos++;
        }else{neg++; }
    }
    
    printf("\nLa cantidad de valores positivos es de: %d, y de negativos: %d \n",pos,neg);

}

void promedio_pates( int *v, int n){
    float promedio=0;
    int cant_par = 0;
    for (int i = 0; i < n; i++)
    {
        if(v[i] % 2 == 0){
            cant_par++;
        }
    }
    
    promedio = (cant_par * 100) / n;

    printf("El promedio de los pares es de: %.2f \n",promedio);
}

/**/