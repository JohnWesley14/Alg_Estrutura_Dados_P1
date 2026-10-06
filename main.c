#include <stdio.h>

int main() {
    int capacity = 0;      
    int size = 0;           
    int input_value;
    int search_index;
    int delete_index;
    int menu_option = 10;

    printf("Digite o limite de recordes da maquina de Arcade: ");
    scanf("%d", &capacity);

    int array[capacity];

    // Preenchimento inicial
    printf("\n--- Registrando High Scores Iniciais ---\n");
    for (int i = 0; i < capacity; i++) {
        printf("Digite a pontuacao para a posicao %d do ranking: ", i);
        scanf("%d", &input_value);
        array[i] = input_value;
        size++;
    }

    printf("\n--- Tabela de High Scores Inicial ---\n");
    for (int i = 0; i < size; i++) {
        printf("Posicao no Ranking: %d\n", i);
        printf("Pontuacao: %d\n", array[i]);
        printf("------------------- \n");
    }

    while (menu_option != 0) {
        printf("\n0 - Desligar Maquina ");
        printf("\n1 - Buscar por pontuacao exata");
        printf("\n2 - Buscar recorde por posicao no ranking");
        printf("\n3 - Apagar recorde da posicao");
        printf("\n4 - Atualizar recorde na posicao (Novo High Score)");
        printf("\n5 - Exibir Ranking Completo");
        printf("\n6 - Exibir Top High Scores ");
        printf("\n\nEscolha a acao do sistema: ");
        scanf("%d", &menu_option);

        // 1. Busca por valor
        if (menu_option == 1) {
            printf("\n-----------------------------------\n");
            printf("Digite a pontuacao exata que deseja buscar: ");
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
                printf("Pontuacao encontrada! Esta na posicao: %d do ranking.\n", found_index);
            } else {
                printf("Nenhum jogador atingiu essa pontuacao exata ainda.\n");
            }
        }

        // 2. Buscar por índice
        if (menu_option == 2) {
            printf("\n-----------------------------------\n");
            if (size == 0) {
                printf("A tabela de recordes esta vazia!\n");
            } else {
                printf("Diga a posicao do ranking que deseja consultar (0 a %d): ", size - 1);
                scanf("%d", &search_index);

                if (search_index >= 0 && search_index < size) {
                    printf("\nO recorde na posicao [%d] e de: %d pontos\n", search_index, array[search_index]);
                } else {
                    printf("Posicao de ranking inexistente!\n");
                }
            }
        }

        // 3. Deletar por índice
        if (menu_option == 3) {
            printf("\n-----------------------------------\n");
            if (size == 0) {
                printf("A tabela de recordes esta vazia!\n");
            } else {
                printf("Diga a posicao do recorde a ser apagado (0 a %d): ", size - 1);
                scanf("%d", &delete_index);

                if (delete_index < 0 || delete_index >= size) {
                    printf("Erro: Posicao de ranking invalida!\n");
                } else {
                    for (int i = delete_index; i < size - 1; i++) {
                        array[i] = array[i + 1];
                    }

                    size--;
                    printf("Recorde apagado com sucesso do sistema!\n\n");

                    printf("--- Tabela de Recordes Atualizada ---\n");
                    if (size == 0) {
                        printf("Nao ha mais nenhum recorde registrado.\n");
                    } else {
                        for (int i = 0; i < size; i++) {
                            printf("Posicao [%d]: %d pontos\n", i, array[i]);
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
                printf("A tabela esta vazia! Nao ha recorde para sobrescrever.\n");
            } else {
                printf("Digite a posicao que o novo High Score ocupara (0 a %d): ", size - 1);
                scanf("%d", &update_index);

                if (update_index >= 0 && update_index < size) {
                    printf("Digite a nova pontuacao para a posicao %d: ", update_index);
                    scanf("%d", &new_value);
                    array[update_index] = new_value;

                    menu_option = 5;
                } else {
                    printf("Erro: Posicao de ranking invalida!\n");
                }
            }
        }

        // 5. Listar Array
        if (menu_option == 5) {
            printf("\n--- Ranking do Arcade (%d recordes) ---\n", size);
            if (size == 0) {
                printf("Nenhum recorde registrado ainda.\n");
            } else {
                for (int i = 0; i < size; i++) {
                    printf("-------------------\n");
                    printf("Posicao: %d \nPontos: %d \n", i, array[i]);
                    printf("-------------------\n");
                }
            }
        }

        // 6. Exibir Top High Scores (Ordenado)
        if (menu_option == 6) {
            printf("\n--- Podio de High Scores ---\n");
            if (size == 0) {
                printf("Nenhum recorde registrado ainda.\n");
            } else {
                // Cria uma cópia do vetor para não desorganizar os índices originais da máquina
                int temp_array[size];
                for (int i = 0; i < size; i++) {
                    temp_array[i] = array[i];
                }

                // Ordena a cópia do maior para o menor (utilizando Bubble Sort)
                for (int i = 0; i < size - 1; i++) {
                    for (int j = 0; j < size - i - 1; j++) {
                        if (temp_array[j] < temp_array[j + 1]) {
                            int temp = temp_array[j];
                            temp_array[j] = temp_array[j + 1];
                            temp_array[j + 1] = temp;
                        }
                    }
                }

                // Exibe o ranking ordenado
                for (int i = 0; i < size; i++) {
                    printf("%dº Lugar: %d pontos\n", i + 1, temp_array[i]);
                }
                printf("-------------------\n");
            }
        }
    }

    return 0;
}
