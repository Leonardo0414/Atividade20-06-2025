#include "../constante.h"

//Funcao para gerar um vetor de numeros aleatorios
void gerarVetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 10000; //Numeros aleatorios entre 0 e 9999
    }
}

//Funcao para copiar um vetor de origem para um destino com tamanho especifico
void copiarVetor(int* origem, int* destino, int tamanho) {
    memcpy(destino, origem, tamanho * sizeof(int)); // Copia o vetor origem para o destino
    // memcpy é da biblioteca string.h que copia blocos de memoria
}

//Funcao para imprimir os primeiros e ultimos n elementos de um vetor
void imprimirVetor(int* vetor, int tamanho, int n) {
    // Exibe os primeiros n elementos
    for (int i = 0; i < n && i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    
    // Se o vetor for maior que 2*n, exibe "..." para indicar que há mais elementos
    if (tamanho > 2 * n) {
        printf("... ");
    }
    
    // Exibe os ultimos n elementos
    if (tamanho > n) {
        for (int i = tamanho - n; i < tamanho; i++) {
            printf("%d ", vetor[i]);
        }
    }
    printf("\n");
}

//Funcao de ordenacao Insertion Sort
void insertionSort(int* vetor, int tamanho, int ordem) {
    for (int i = 1; i < tamanho; i++) {
        int chave = vetor[i];
        int j = i - 1;

        // Compara e move os elementos baseado na ordem (1=crescente, 0=decrescente)
        while (j >= 0 && ((ordem == 1 && vetor[j] > chave) || (ordem == 0 && vetor[j] < chave))) {
            vetor[j + 1] = vetor[j];
            j--;
        }
        vetor[j + 1] = chave;
    }
}

//Funcao de ordenacao Quick Sort
void quickSort(int* vetor, int inicio, int fim, int ordem) {
    if (inicio < fim) {
        int pivo = vetor[fim];
        int i = inicio - 1;

        // Particiona o vetor baseado no pivo e na ordem desejada
        for (int j = inicio; j < fim; j++) {
            if ((ordem == 1 && vetor[j] <= pivo) || (ordem == 0 && vetor[j] >= pivo)) {
                i++;
                int temp = vetor[i];
                vetor[i] = vetor[j];
                vetor[j] = temp;
            }
        }
        i++;
        int temp = vetor[i];
        vetor[i] = vetor[fim];
        vetor[fim] = temp;

        // Chama quickSort recursivamente para as duas particao
        quickSort(vetor, inicio, i - 1, ordem);
        quickSort(vetor, i + 1, fim, ordem);
    }
}

//Funcao para demonstrar os algoritmos de ordenacao
void demonstrarAlgoritmosOrdenacao() {
    // Aloca memoria para o vetor original e vetor copia
    int* vetorOriginal = (int*)malloc(TAMANHO * sizeof(int));
    int* vetorCopia = (int*)malloc(TAMANHO * sizeof(int));
    
    if (vetorOriginal == NULL || vetorCopia == NULL) {
        printf("Erro na alocação de memória!\n");
        if (vetorOriginal) free(vetorOriginal);
        if (vetorCopia) free(vetorCopia);
        return;
    }
    // Gera vetor original com numeros aleatorios
    gerarVetor(vetorOriginal, TAMANHO);
    
    printf("\nVETOR ORIGINAL (primeiros %d e ultimos %d): ", N_EXIBIR, N_EXIBIR);
    imprimirVetor(vetorOriginal, TAMANHO, N_EXIBIR);

    //Insertion Sort Crescente
    copiarVetor(vetorOriginal, vetorCopia, TAMANHO);
    insertionSort(vetorCopia, TAMANHO, 1);
    printf("\nINSERTION SORT CRESCENTE (primeiros %d e ultimos %d): ", N_EXIBIR, N_EXIBIR);
    imprimirVetor(vetorCopia, TAMANHO, N_EXIBIR);

    // TeInsertion Sort Decrescente
    copiarVetor(vetorOriginal, vetorCopia, TAMANHO);
    insertionSort(vetorCopia, TAMANHO, 0);
    printf("\nINSERTION SORT DECRESCENTE (primeiros %d e ultimos %d): ", N_EXIBIR, N_EXIBIR);
    imprimirVetor(vetorCopia, TAMANHO, N_EXIBIR);

    //  Quick Sort Crescente
    copiarVetor(vetorOriginal, vetorCopia, TAMANHO);
    quickSort(vetorCopia, 0, TAMANHO - 1, 1);
    printf("\nQUICK SORT CRESCENTE (primeiros %d e ultimos %d): ", N_EXIBIR, N_EXIBIR);
    imprimirVetor(vetorCopia, TAMANHO, N_EXIBIR);

    // Quick Sort Decrescente
    copiarVetor(vetorOriginal, vetorCopia, TAMANHO);
    quickSort(vetorCopia, 0, TAMANHO - 1, 0);
    printf("\nQUICK SORT DECRESCENTE (primeiros %d e ultimos %d): ", N_EXIBIR, N_EXIBIR);
    imprimirVetor(vetorCopia, TAMANHO, N_EXIBIR);

    // Libera a memoria alocada
    free(vetorOriginal);
    free(vetorCopia);
}