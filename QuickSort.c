#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void swap(int *a, int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}

int partition(int arr[], int low, int high){
    /*Inicializar el pivote para el primer elemento*/
    int p=arr[low];
    int i=low;
    int j=high;

    while(i<j){

        /*Encontrar el primer elemento más grande que el pivote*/
        while(arr[i]<=p && i<=high -1){
            i++;
        }

        /*Encontrar el primer elemento más pequeño que el pivote*/
        while(arr[j]>p && j>=low+1){
            j--;
        }
        if(i<j){
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[low], &arr[j]);
    return j;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        /*Función para encontrar la partición*/
        int pi=partition(arr, low, high);
        /*Función recursiva quickSort para la mitad izquierda o derecha basado en el pivote*/
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

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

void printSorted(int *arr, int n){
	FILE *fPtr= fopen("sorted.txt","w");
	if(fPtr == NULL){
		perror("Error in file\n");
	} else {
		for(int i= 0; i<n; i++){
			fprintf(fPtr,"%d\n",arr[i]);
		}
		printf("Sorted Array Created!\n");
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
    start_t=clock();
    int n=maximumData(file);
    int array[n];
    insert(file, array);
    quickSort(array,0, n-1);
    end_t=clock();
    printSorted(array,n);
    total_t=((double)(end_t-start_t)/ CLOCKS_PER_SEC) *1000.0;
    printf("Tiempo total usado por la cpu: %fms\n", total_t);
    fclose(file);
    return 0;

}
