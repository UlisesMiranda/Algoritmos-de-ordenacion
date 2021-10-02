#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define lenght 25  

void MergeSort (int *A, int p, int r);
void Merge (int *A, int p, int q, int r);
void InicializarArray (int arr[], int max, int min);
void ImprimirArreglo (int *arr);
int *CrearArreglo(int N);
 

int main ()
{   

    int arr [lenght+1];
    InicializarArray(arr, 99, 1);
    int *arreglo = arr;

    printf("Arreglo original con longitud %d\n", lenght);
  
    ImprimirArreglo (arreglo);

    MergeSort (arreglo, 0 , lenght);

    printf("\n\nArreglo ordenado: \n");

    ImprimirArreglo (arreglo);
    

    free(arreglo);

    return 0;
}

void MergeSort (int *A, int p, int r)
{
    if (p < r)
    {
        int q= ((p + r)/2);
        MergeSort (A, p, q);
        MergeSort (A, q + 1, r);
        Merge (A, p, q, r);
    }
}

void Merge (int *A, int p, int q, int r)
{
    int n1, n2;
    int *L, *R;

    n1 = q - p + 1;
    n2 = r - q;
    
    L = CrearArreglo (n1 + 1);
    R = CrearArreglo (n2 + 1);

    for (int i = 1; i <= n1; i++ ) {
        L[i] = A[p + i -     1];
    }

    for ( int j = 1; j <= n2; j++ ) {
        R[j] = A[q + j];
    }

    int i = 1, j = 1;

    for ( int k = p; k <= r; k++) {
        if ( L[i] <= R[j] ){
            A[k] = L[i];
            i = i + 1;
        }    
        else {
            A[k] = R[j];
            j = j + 1; 
        }
    }

    free(L); 
    free(R);
}

void InicializarArray (int arr[], int max, int min) {

    srand(time(NULL));
    
    int i;

    for ( i = 1; i <= lenght+1; i++ ){
        arr[i] = (rand() % (max - min + 1)) + min; 
    }
}

void ImprimirArreglo (int *arr)
{
    int i;

    for (i=1; i <= lenght; i++)
    {
        printf("%d,", arr[i]);
    }
}

int *CrearArreglo(int N)
{
    int *arr = NULL;

    arr = (int *) malloc(N*sizeof(int));

    return (arr);
}