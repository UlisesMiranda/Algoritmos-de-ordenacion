#include <stdio.h>
#include <stdlib.h>
#include <time.h> //MIRANDA CHAVEZ VICTOR ULISES
#define lenght 200

int particion(int *A, int p, int r);
void quicksort(int *A, int p, int r);
void ImprimirArreglo(int *arr);
void InicializarArray(int *arr, int max, int min);
int *CrearArreglo(int N);


int main(){
    
    int Arreglo[lenght+1];

    InicializarArray(Arreglo, 99, 1);

     int* A = Arreglo;

    printf("Arreglo original con longitud %d\n", lenght);
  
    ImprimirArreglo (A);

    quicksort(A, 1, lenght);

    printf("\n\nArreglo ordenado: \n");

    ImprimirArreglo(A);

    return 0;

}


int particion(int *A, int p, int r) {

    int x, i, j;

    x = A[r];
    i = p-1;

    for ( j = p; j <= r-1; j++)
    {
        if (A[j] <= x)
        {
            int aux;
            i = i+1;
            aux = A[i]; 
            A[i]= A[j];
            A[j] = aux;
        }
    }
    int temp;

    temp = A[i+1];
    A[i+1] = A[r];
    A[r] = temp;
        
    return i+1;
}

void quicksort (int *A, int p, int r){

    if (p < r){
        int q = particion(A, p, r);
        quicksort(A, p, q-1);
        quicksort(A, q+1, r);
    }
}

void ImprimirArreglo (int *arr)
{
    int i;

    for (i=1; i <= lenght; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void InicializarArray (int *arr, int max, int min) {

    srand(time(NULL));
    
    int i;

    for ( i = 1; i <= lenght+1; i++ ){
        arr[i] = (rand() % (max - min + 1)) + min; 
    }
}

int *CrearArreglo(int N)
{
    int *arr = NULL;

    arr = (int *) malloc(N*sizeof(int));

    return (arr);
}