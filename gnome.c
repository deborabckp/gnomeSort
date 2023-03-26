#include <stdio.h>
#include <string.h>
#include <time.h>

void gnomeSort(char *array[], int n){
    int pos = 0; 

    while(pos < n){
        if (pos == 0 || strcmp(array[pos], array[pos-1]) >= 0){
            pos++;
        }

        else{
            char *temp = array[pos];
            array[pos] = array[pos - 1];
            array[pos - 1] = temp;
            pos--;
        }
    }
}

int main(void){
    clock_t inicio, fim;
    double tempo_execucao;
    char *array[] = {"Debora", "Armando", "Angela", "Fernanda"};
    int n = sizeof(array) / sizeof(array[0]);

    inicio = clock();
    printf("%d\n", n);

    printf("Vetor original:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i]);
    }
    printf("\n");

    gnomeSort(array, n);

    printf("Vetor ordenado:\n");
    for(int i = 0; i < n; i++){
        printf("%s\n", array[i]);
    }
    printf("\n");

    fim = clock();
    tempo_execucao = (double)(fim - inicio) / CLOCKS_PER_SEC;
    printf("Tempo de execução: %.5f segundos\n", tempo_execucao);
    return 0;
}