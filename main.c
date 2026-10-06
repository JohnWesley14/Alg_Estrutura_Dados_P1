#include <stdio.h>
int main(){

    int max = 0;
    int quantidade = 0;
    int valor;
    int index3;
    int indexDelete;

    printf("Digite o tamanho max do vetor: ");
    scanf("%d", &max);
   
    int vetor[max];

    struct item
    {
        int encontrado;
        int posicao;
    };
  
    int indexRoute = 10;
     for (int i = 0; i < max; i++){
            printf("Digite um valor: pra position %i: ", i);
            scanf("%d", &valor);
            vetor[i] = valor;
           
            }  
              for (int i = 0; i < max; i++)
            {
                printf("Position: %d\n", i);
                printf("Value: %d\n", vetor[i]);
                printf("------------------- \n");
            }
    while(indexRoute != 0){
        
        printf("\n0 - Sair");
        printf("\n1 - Busca por valor");
        printf("\n2 - Buscar por índice");
        printf("\n3 - Deletar por índice");
        printf("\n4 - Atualizar por índice");
        printf("\n5 - Listar Array");
        printf("\n\nEscolha a opção: ");
        scanf("%d", &indexRoute );
        
        if(indexRoute == 1){
            printf("\n-----------------------------------\n");
            printf("Digite o numero que quer buscar: ");
            scanf("%d", &valor);
            struct item item1 = {0};
            for (int i = 0; i < max; i++)
            {
               
                if(vetor[i] == valor){
                    item1.posicao = i;
                    item1.encontrado = 1;
                }
            }
            if(item1.encontrado){
   
                printf("Foi encontrado e a posicao eh: %d\n", item1.posicao);
            }else{
                printf("Não achamos, volte mais tarde meu lindo\n");
            }
           
           
        }
        if(indexRoute == 2){
            printf("\n-----------------------------------\n");
            printf("\nDiga o índice do valor que quer buscar, deve ser de 0 a %d\n", max-1);
            scanf("%d", &index3);
            if(index3 >= 0 && index3 < max){
                printf("\nO valor de vetor[%d] é: %d\n", index3, vetor[index3]);
            }else{
                printf("Índice inexistente");
            }
        }
        if(indexRoute == 3){
            printf("\n-----------------------------------\n");
            printf("Diga o índice do valor a ser deletado: \n");
            scanf("%d", &indexDelete);
        
           
            if(indexDelete < 0 || indexDelete >= max){
                printf("Erro: Índice inválido!\n");
            } else {

                for (int i = indexDelete; i < max - 1; i++) {
                    vetor[i] = vetor[i + 1];
                }
                
                max--;
                printf("Valor deletado com sucesso!\n\n");
                
                // 4. Listar os valores atualizados
                printf("--- Lista de Valores Atualizada ---\n");
                if (max == 0) {
                    printf("O array está vazio agora.\n");
                } else {
                    for (int i = 0; i < max; i++) {
                        printf("Índice [%d]: %d\n", i, vetor[i]); 
                    }
                }
                printf("\n-----------------------------------\n");
            }
        }
        
        if(indexRoute == 4){
            int indexAtualizar;
            int valorAtualizar;
            printf("\n-----------------------------------\n");
            printf("Digite o índice que quer atualizar, que seja entre 0 e %d: ", max-1);
            scanf("%d", &indexAtualizar);
            printf("\nDigite qual o valor deseja colocar no indice %d: ", indexAtualizar);
            scanf("%d", &valorAtualizar);
            vetor[indexAtualizar] = valorAtualizar;
            
            indexRoute = 5;
        }
        
        
        
        if(indexRoute == 5){
            for (int i = 0; i < max; i++) {
                printf("-------------------\n");
                printf("\nPosition: %d \n Value: %d \n", i, vetor[i]);
                printf("-------------------\n");
            }
        }
    }
    return 0;
   
}