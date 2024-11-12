#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
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
int getNextGap(int gap){
    gap=(gap*10)/13;
    if(gap<1) return 1;

    return gap;
}

void CombSort(int *a, int n){
    int gap=n;
    int temp,i;
    bool swapped=true;

    while(gap!=1 || swapped==true){
        gap=getNextGap(gap);
              swapped=false;
        
        for(i=0; i<n-gap;i++){
            if(a[i]>a[i+gap]){
                temp=a[i];
                a[i]=a[i+gap];
                a[i+gap]= temp;
                swapped=true;
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
    start_t=clock();
    int n=maximumData(file);
    int array[n];
    insert(file, array);
    
    CombSort(array, n);
    end_t=clock();
    total_t=((double)(end_t-start_t)/ CLOCKS_PER_SEC) *1000.0;
    printf("Tiempo total usado por la cpu: %fms\n", total_t);

    fclose(file);
    return 0;
}
