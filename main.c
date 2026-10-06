#include <stdio.h>

int main() {
    int capacidade = 0;   // Capacidade máxima (tamanho do vetor)
    int quantidade = 0;   // Quantidade de elementos ativos/adicionados
    int valor;
    int index3;
    int indexDelete;
    int indexRoute = 10;

    printf("Digite o tamanho max do vetor: ");
    scanf("%d", &capacidade);

    int vetor[capacidade];

    // Preenchimento inicial do vetor
    printf("\n--- Preenchimento Inicial ---\n");
    for (int i = 0; i < capacidade; i++) {
        printf("Digite um valor para a posicao %d: ", i);
        scanf("%d", &valor);
        vetor[i] = valor;
        quantidade++; // Incrementa a quantidade conforme adiciona
    }

    printf("\n--- Array Inicial ---\n");
    for (int i = 0; i < quantidade; i++) {
        printf("Position: %d\n", i);
        printf("Value: %d\n", vetor[i]);
        printf("------------------- \n");
    }

    while (indexRoute != 0) {
        printf("\n0 - Sair");
        printf("\n1 - Busca por valor");
        printf("\n2 - Buscar por índice");
        printf("\n3 - Deletar por índice");
        printf("\n4 - Atualizar por índice");
        printf("\n5 - Listar Array");
        printf("\n\nEscolha a opção: ");
        scanf("%d", &indexRoute);

        // 1. Busca por valor (Sem struct)
        if (indexRoute == 1) {
            printf("\n-----------------------------------\n");
            printf("Digite o numero que quer buscar: ");
            scanf("%d", &valor);

            int encontrado = 0;
            int posicao = -1;

            for (int i = 0; i < quantidade; i++) {
                if (vetor[i] == valor) {
                    posicao = i;
                    encontrado = 1;
                }
            }

            if (encontrado) {
                printf("Foi encontrado e a posicao eh: %d\n", posicao);
            } else {
                printf("Não achamos, volte mais tarde meu lindo\n");
            }
        }

        // 2. Buscar por índice
        if (indexRoute == 2) {
            printf("\n-----------------------------------\n");
            if (quantidade == 0) {
                printf("O array está vazio!\n");
            } else {
                printf("Diga o índice do valor que quer buscar (0 a %d): ", quantidade - 1);
                scanf("%d", &index3);

                if (index3 >= 0 && index3 < quantidade) {
                    printf("\nO valor de vetor[%d] é: %d\n", index3, vetor[index3]);
                } else {
                    printf("Índice inexistente!\n");
                }
            }
        }

        // 3. Deletar por índice
        if (indexRoute == 3) {
            printf("\n-----------------------------------\n");
            if (quantidade == 0) {
                printf("O array está vazio!\n");
            } else {
                printf("Diga o índice do valor a ser deletado (0 a %d): ", quantidade - 1);
                scanf("%d", &indexDelete);

                if (indexDelete < 0 || indexDelete >= quantidade) {
                    printf("Erro: Índice inválido!\n");
                } else {
                    // Desloca os elementos para a esquerda
                    for (int i = indexDelete; i < quantidade - 1; i++) {
                        vetor[i] = vetor[i + 1];
                    }

                    quantidade--; // Reduz apenas a quantidade atual
                    printf("Valor deletado com sucesso!\n\n");

                    printf("--- Lista de Valores Atualizada ---\n");
                    if (quantidade == 0) {
                        printf("O array está vazio agora.\n");
                    } else {
                        for (int i = 0; i < quantidade; i++) {
                            printf("Índice [%d]: %d\n", i, vetor[i]);
                        }
                    }
                    printf("\n-----------------------------------\n");
                }
            }
        }

        // 4. Atualizar por índice
        if (indexRoute == 4) {
            int indexAtualizar;
            int valorAtualizar;
            printf("\n-----------------------------------\n");

            if (quantidade == 0) {
                printf("O array está vazio! Não há o que atualizar.\n");
            } else {
                printf("Digite o índice que quer atualizar (0 a %d): ", quantidade - 1);
                scanf("%d", &indexAtualizar);

                if (indexAtualizar >= 0 && indexAtualizar < quantidade) {
                    printf("Digite qual o valor deseja colocar no indice %d: ", indexAtualizar);
                    scanf("%d", &valorAtualizar);
                    vetor[indexAtualizar] = valorAtualizar;

                    indexRoute = 5; // Vai para a opção 5 para listar
                } else {
                    printf("Erro: Índice inválido!\n");
                }
            }
        }

        // 5. Listar Array
        if (indexRoute == 5) {
            printf("\n--- Elementos no Array (%d) ---\n", quantidade);
            if (quantidade == 0) {
                printf("O array está vazio.\n");
            } else {
                for (int i = 0; i < quantidade; i++) {
                    printf("-------------------\n");
                    printf("Position: %d \nValue: %d \n", i, vetor[i]);
                    printf("-------------------\n");
                }
            }
        }
    }

    return 0;
}