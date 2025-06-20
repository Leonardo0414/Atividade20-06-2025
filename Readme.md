# Sistema de Loteria e Algoritmos de Ordenação

## Descrição
Este sistema foi desenvolvido como parte do trabalho A3 para a disciplina de Fundamentos de Algoritmos e Programação da Universidade Comunitária da Região de Chapecó (UNO). O projeto implementa dois módulos principais: um jogo de loteria e uma demonstração de algoritmos de ordenação utilizando ponteiros.

## Funcionalidades

### Jogo de Loteria
- Permite ao usuário escolher 6 números entre 1 e 60
- Sorteia 6 números aleatórios
- Mostra os números do usuário e os sorteados
- Indica quantos números o usuário acertou e o prêmio correspondente

### Demonstração de Algoritmos de Ordenação
- Gera um vetor de 1000 números aleatórios usando alocação dinâmica de memória
- Implementa e demonstra dois algoritmos de ordenação:
  - Insertion Sort (ordem crescente e decrescente)
  - Quick Sort (ordem crescente e decrescente)
- Exibe os primeiros 20 e últimos 20 elementos de cada vetor ordenado

## Tecnologias Utilizadas
- Linguagem C
- Ponteiros e alocação dinâmica de memória
- Estruturas de dados
- Algoritmos de ordenação
- Geração de números aleatórios

## Como Executar
O executável já compilado está disponível na raiz do projeto:

`main.exe`: Versão executável para Windows

Basta clicar duas vezes sobre o arquivo executável ou executá-lo via linha de comando:
```
./main.exe
```

## Compilando o Código

⚠️ É necessário ter um compilador C instalado na máquina.

Compilação (na raiz do projeto):
```
gcc main.exe -o main.c
```

## Estrutura do Projeto
O projeto está organizado em diversos arquivos e diretórios:
```
projeto/
├── Loteria/              # Diretório contendo o módulo da loteria
│   └── loteria.c         # Implementação das funções da loteria
├── Ordenacao/            # Diretório contendo o módulo de ordenação
│   └── ordenacao.c       # Implementação dos algoritmos de ordenação
├── constante.h           # Definições de constantes globais
├── main.c                # Função principal e menu
└── README.md             # Documentação do projeto
```

## Uso do Programa

Ao iniciar, o programa apresenta um menu com 3 opções:

- 1: Jogar na Loteria
- 2: Demonstrar Algoritmos de Ordenação
- 3: Sair

Para jogar na loteria:
1. Escolha a opção 1
2. Digite 6 números diferentes entre 1 e 60
3. O programa mostrará os resultados do sorteio

Para demonstrar os algoritmos de ordenação:
1. Escolha a opção 2
2. O programa gera um vetor aleatório e mostra os resultados das ordenações

## Algoritmos Implementados

### Insertion Sort
Um algoritmo de ordenação simples que constrói o vetor ordenado um elemento por vez. É eficiente para conjuntos pequenos de dados e funciona como pessoas geralmente ordenam cartas de baralho.

### Quick Sort
Um algoritmo de ordenação mais eficiente baseado na estratégia "dividir para conquistar". Escolhe um elemento como pivô e particiona o vetor em torno desse pivô, recursivamente ordenando as partições.

## Conceitos Aplicados de Ponteiros
- Alocação dinâmica de memória para os vetores
- Passagem de vetores por referência
- Manipulação direta de endereços de memória
- Cópia eficiente de vetores usando memcpy

## Autores
Este projeto foi desenvolvido por Leonardo Pereira Por, estudante da UNO, como parte da disciplina de Fundamentos de Algoritmos e Programação, sob orientação do Professor Lucas Volfe.

## Observações
Este projeto foi desenvolvido para fins estudantis como parte do aprendizado de programação em C. O código implementa conceitos de algoritmos de ordenação, estruturas de dados e ponteiros estudados na disciplina.

---

**Universidade Comunitária da Região de Chapecó - UNO**  
**Curso:** Ciência da Computação  
**Disciplina:** 1030900 - FUNDAMENTOS DE ALGORITMOS E PROGRAMAÇÃO