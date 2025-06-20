#include "../constante.h"

//Funcao para verificar se o numero ja existe no vetor
int numeroExistente(int* vetor, int tamanho, int numero) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == numero) {
            return 1; // Numero ja existe
        }
    }
    return 0; // Numero nao existe
}

//Funcao para sortear numeros aleatorios para a loteria
void sortearNumeros(int* sorteados) {
    int i = 0;
    while (i < NUMEROS_LOTERIA) {
        int numero = 1 + (rand() % MAXIMO_LOTERIA); // Gera numero entre 1 e MAXIMO_LOTERIA = 60 
        
        if (!numeroExistente(sorteados, i, numero)) {
            sorteados[i] = numero; // Adiciona o numero ao vetor se nao existir
            i++;
        }
    }
}

//Funcao para contar acertos entre a aposta e os numeros sorteados
int contarAcertos(int* aposta, int* sorteados) {
    int acertos = 0;
    for (int i = 0; i < NUMEROS_LOTERIA; i++) {
        for (int j = 0; j < NUMEROS_LOTERIA; j++) {
            if (aposta[i] == sorteados[j]) {
                acertos++; // Incrementa contador de acertos
                break; // Passa para o proximo numero da aposta
            }
        }
    }
    return acertos;
}

//Funcao principal do jogo de loteria
void jogarLoteria() {
    // Aloca memoria para a aposta e numeros sorteados
    int* aposta = (int*)malloc(NUMEROS_LOTERIA * sizeof(int));
    int* sorteados = (int*)malloc(NUMEROS_LOTERIA * sizeof(int));
    
    if (aposta == NULL || sorteados == NULL) {
        printf("Erro na alocacão de memoria!\n");
        if (aposta) free(aposta);
        if (sorteados) free(sorteados);
        return;
    }

    printf("Digite os numeros da sua aposta (%d numeros de 1 a %d):\n", NUMEROS_LOTERIA, MAXIMO_LOTERIA);
    
    // Coleta os numeros da aposta
    int i = 0;
    while (i < NUMEROS_LOTERIA) {
        int numero;
        printf("Numero %d: ", i + 1);
        scanf("%d", &numero);
        
        if (numero < 1 || numero > MAXIMO_LOTERIA) {
            printf("Numero invalido! Digite um numero entre 1 e %d.\n", MAXIMO_LOTERIA);
        } else if (numeroExistente(aposta, i, numero)) {
            printf("Numero ja escolhido! Escolha outro numero.\n");
        } else {
            aposta[i] = numero;
            i++;
        }
    }
    sortearNumeros(sorteados);

    printf("\nSeus numeros da aposta: ");
    for (int i = 0; i < NUMEROS_LOTERIA; i++) {
        printf("%d ", aposta[i]);
    }
    printf("\nNumeros sorteados: ");
    for (int i = 0; i < NUMEROS_LOTERIA; i++) {
        printf("%d ", sorteados[i]);
    }
    int acertos = contarAcertos(aposta, sorteados);
    printf("\nTotal de acertos: %d\n", acertos);

    // Verifica os premios
    if (acertos == 6) {
        printf("Parabens! Voce ganhou na MEGASENA!\n");
    } else if (acertos == 5) {
        printf("Voce acertou 5 numeros! Voce ganhou na quina!\n");
    } else if (acertos == 4) {
        printf("Voce acertou 4 numeros! Voce ganhou na quadra!\n");
    } else if (acertos == 3) {
        printf("Voce acertou 3 numeros! Nao ganhou nada desta vez. Tente novamente!\n");
    } else {
        printf("Infelizmente, voce nao ganhou nenhum premio desta vez.\n");
    }

    // Libera a memoria alocada
    free(aposta);
    free(sorteados);
    
}