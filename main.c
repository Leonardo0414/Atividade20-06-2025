#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "Loteria/loteria.c"
#include "Ordenacao/ordenacao.c"

int main() {
    int opcao;
    // Inicializa o gerador de numeros aleatorios
    srand(time(NULL));
    // Menu de Opcao do Sistema
    do {
        printf("\nEscolha uma opcao:\n");
        printf("1 - Jogar na Loteria\n");
        printf("2 - Demonstrar Algoritmos de Ordenacao\n");
        printf("3 - Sair\n");
        scanf("%d", &opcao);
        
        switch(opcao) {
            case 1:
                jogarLoteria();
                break;
            case 2:
                demonstrarAlgoritmosOrdenacao();
                break;
            case 3:
                printf("Saindo do Sistema...\n");
                break;
            default:
                printf("Opcao invalida! Por favor, tente novamente.\n");
        }
    } while(opcao != 3);
    
    return 0;
}