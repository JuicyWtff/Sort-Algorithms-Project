#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
Función para saber el número de datos en nuestro archivo
Avanza leyendo datos enteros hasta encontrar el fin de archivo
*/
int numberOfLines(FILE *archive){
    int i=0,n;

    while(fscanf(archive, "%d", &n)!=EOF) i++;
    rewind(archive);

    return i;
}

/*
Funcion para insertar en un arreglo cualquiera los datos leidos del archivo
*/
void insert(FILE *archive, int *arr){
    int i=0, n;
    while(fscanf(archive, "%d", &n)!=EOF){
        arr[i]=n;
        i++;
    }
    rewind(archive);
    
}   

void BubbleSort(int *a, int n) {
    int interruptor = 1;
    int pasada, j;

    for (pasada = 0; pasada < n - 1 && interruptor; pasada++) {
        /* El bucle externo controla la cantidad de pasadas */
        interruptor = 0;
        for (j = 0; j < n - pasada - 1; j++) {
            if (a[j] > a[j + 1]) {
                /* Intercambiamos si están desordenados */
                int aux;
                interruptor = 1;
                aux = a[j];
                a[j] = a[j + 1];
                a[j + 1] = aux;
            }
        }
    }
}

int main(){
    clock_t start_t, end_t;
    double total_t;
    
    FILE *file=fopen("random.txt","r");
    if(file == NULL){
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }
    
    //Inicialización de variables para igualdad de condiciones
    int n=numberOfLines(file);
    int array[n];
    insert(file, array);

    /*Inicio de cronometro para BubbleSort*/
    start_t=clock();
    BubbleSort(array, n);
    end_t=clock();
    /*Fin de cronometro para BubbleSort*/

    total_t=((double)(end_t-start_t)/ CLOCKS_PER_SEC) *1000.0;

    printf("Tiempo total usado por la cpu: %fms\n", total_t);

    fclose(file);
     
    return 0;
}
