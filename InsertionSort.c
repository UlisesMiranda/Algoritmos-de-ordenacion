
//AUTOR: VICTOR ULISES MIRANDA CHAVEZ
//3BM1

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lenght 25

void InsertionSort (int A[]);
void InicializarArray (int arr[], int max, int min);
void ImprimirArreglo (int arr[]);

int main () {

    int arr[lenght];

    InicializarArray (arr, 99, 1);

    printf("Arreglo original con longitud %d\n", lenght);

    ImprimirArreglo(arr);

    InsertionSort(arr);

    printf("\n\nArreglo ordenado: \n");

    ImprimirArreglo (arr);

    return 0;
}

void InsertionSort (int A[]) {
    int j, i, key;
 
    for ( j = 2; j <= lenght; j++ ) {

    key = A[j];
        i = j - 1;

        while (i > 0 && A[i] > key)
        {
            A[i + 1] = A[i];
            i = i - 1; 
        }
        
        A[i + 1] = key;
        
    }
} 

void InicializarArray (int arr[], int max, int min) {

    srand(time(NULL));
    
    int i;

    for ( i = 1; i <= lenght; i++ ){
        arr[i] = (rand() % (max - min + 1)) + min; 
    }
}

void ImprimirArreglo (int arr[])
{
    int i;

    for (i=1; i <= lenght; i++)
    {
        printf("%d\t", arr[i]);
    }
}
