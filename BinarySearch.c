#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int maximumData(FILE *archive){
    int i=0;
    int n;
    while(fscanf(archive, "%d", &n)!=EOF){ //lee un dato tipo entero en el archivo hasta que llega al final del archivo ya que nuestros datos tienen salto de línea.
        i++;
    }
    rewind(archive);
    return i;
}
void insert(FILE *archive, int *arr){
    int i=0;
    int n;
    while(fscanf(archive, "%d", &n)!=EOF){
        arr[i]=n;
        i++;
    }
    rewind(archive);
    
}

int binarySearch(int arr[], int left, int right, int key){

    while(left<=right){
        int mid=left+ (right-left)/2;

        if(arr[mid]==key){
            return mid;
        }

        if(arr[mid]<key){
            left=mid+1;
        }

        else{
            right=mid-1;
        }

    }
    return -1;
}

int main(){
    clock_t start_t, end_t;
    double total_t;
    int key, toSearch;
    
    FILE *file=fopen("random.txt","r");
    if(file == NULL){
        perror("Error al abrir el archivo");
        return EXIT_FAILURE;
    }
    printf("Ingrese el elemento a buscar: ");
    scanf("%d",&key);
    start_t=clock();
    int n=maximumData(file);
    int array[n];
    insert(file, array);
    toSearch=binarySearch(array, 0, n-1, key);
    end_t=clock();
    if(toSearch==-1){
        printf("El elemento no pudo ser encontrado\n");
    }else{
        printf("El elemento se encontro en el indice: %d\n",toSearch);
    }
    total_t=((double)(end_t-start_t)/ CLOCKS_PER_SEC) *1000.0;
    printf("Tiempo total usado por la cpu: %fms\n", total_t);
    fclose(file);
    return 0;
}