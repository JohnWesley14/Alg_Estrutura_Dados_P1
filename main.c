#include <stdio.h>

int main() {
    int capacity = 0;      
    int size = 0;           
    int input_value;
    int search_index;
    int delete_index;
    int menu_option = 10;

    printf("Digite o tamanho max do vetor: ");
    scanf("%d", &capacity);

    int array[capacity];

    // Preenchimento inicial
    printf("\n--- Preenchimento Inicial ---\n");
    for (int i = 0; i < capacity; i++) {
        printf("Digite um valor para a posicao %d: ", i);
        scanf("%d", &input_value);
        array[i] = input_value;
        size++;
    }

    printf("\n--- Array Inicial ---\n");
    for (int i = 0; i < size; i++) {
        printf("Position: %d\n", i);
        printf("Value: %d\n", array[i]);
        printf("------------------- \n");
    }

    while (menu_option != 0) {
        printf("\n0 - Sair");
        printf("\n1 - Busca por valor");
        printf("\n2 - Buscar por índice");
        printf("\n3 - Deletar por índice");
        printf("\n4 - Atualizar por índice");
        printf("\n5 - Listar Array");
        printf("\n\nEscolha a opção: ");
        scanf("%d", &menu_option);

        // 1. Busca por valor
        if (menu_option == 1) {
            printf("\n-----------------------------------\n");
            printf("Digite o numero que quer buscar: ");
            scanf("%d", &input_value);

            int is_found = 0;
            int found_index = -1;

            for (int i = 0; i < size; i++) {
                if (array[i] == input_value) {
                    found_index = i;
                    is_found = 1;
                }
            }

            if (is_found) {
                printf("Foi encontrado e a posicao eh: %d\n", found_index);
            } else {
                printf("Não achamos, volte mais tarde meu lindo\n");
            }
        }

        // 2. Buscar por índice
        if (menu_option == 2) {
            printf("\n-----------------------------------\n");
            if (size == 0) {
                printf("O array está vazio!\n");
            } else {
                printf("Diga o índice do valor que quer buscar (0 a %d): ", size - 1);
                scanf("%d", &search_index);

                if (search_index >= 0 && search_index < size) {
                    printf("\nO valor de array[%d] é: %d\n", search_index, array[search_index]);
                } else {
                    printf("Índice inexistente!\n");
                }
            }
        }

        // 3. Deletar por índice
        if (menu_option == 3) {
            printf("\n-----------------------------------\n");
            if (size == 0) {
                printf("O array está vazio!\n");
            } else {
                printf("Diga o índice do valor a ser deletado (0 a %d): ", size - 1);
                scanf("%d", &delete_index);

                if (delete_index < 0 || delete_index >= size) {
                    printf("Erro: Índice inválido!\n");
                } else {
                    for (int i = delete_index; i < size - 1; i++) {
                        array[i] = array[i + 1];
                    }

                    size--;
                    printf("Valor deletado com sucesso!\n\n");

                    printf("--- Lista de Valores Atualizada ---\n");
                    if (size == 0) {
                        printf("O array está vazio agora.\n");
                    } else {
                        for (int i = 0; i < size; i++) {
                            printf("Índice [%d]: %d\n", i, array[i]);
                        }
                    }
                    printf("\n-----------------------------------\n");
                }
            }
        }

        // 4. Atualizar por índice
        if (menu_option == 4) {
            int update_index;
            int new_value;
            printf("\n-----------------------------------\n");

            if (size == 0) {
                printf("O array está vazio! Não há o que atualizar.\n");
            } else {
                printf("Digite o índice que quer atualizar (0 a %d): ", size - 1);
                scanf("%d", &update_index);

                if (update_index >= 0 && update_index < size) {
                    printf("Digite qual o valor deseja colocar no indice %d: ", update_index);
                    scanf("%d", &new_value);
                    array[update_index] = new_value;

                    menu_option = 5;
                } else {
                    printf("Erro: Índice inválido!\n");
                }
            }
        }

        // 5. Listar Array
        if (menu_option == 5) {
            printf("\n--- Elementos no Array (%d) ---\n", size);
            if (size == 0) {
                printf("O array está vazio.\n");
            } else {
                for (int i = 0; i < size; i++) {
                    printf("-------------------\n");
                    printf("Position: %d \nValue: %d \n", i, array[i]);
                    printf("-------------------\n");
                }
            }
        }
    }

    return 0;
}