#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(){
    int limit;
    printf("Ingrese el limite de numeros a generar: ");
    scanf("%d", &limit);

    srand(time(NULL));
    FILE *file = fopen("random.txt", "w");
    if(file == NULL){
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }

    for(int i=0; i<limit; i++){
        int num = rand();
        fprintf(file, "%d\n", num);
    }
    fclose(file);
    
    return 1;
}    